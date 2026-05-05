#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;


int main()
{
	double opacity = 0.3; // требуемая базовая прозрачность логотипа
	Mat frame; // исходный кадр из видео
	Mat roi;  // регион рисования логотипа
	Mat bgr_logo; // логотип без альфа-канала
	Mat alpha_mask; // маска прозрачности логотипа
	Mat watermark = imread("mark.png", IMREAD_UNCHANGED); // читаем логотип с альфа каналом
	resize(watermark, watermark, Size(), 0.5, 0.5); // уменьшаем в 2 раза
	int logo_h = watermark.rows; // высота лого
	int logo_w = watermark.cols; // ширина лого
	VideoCapture capture("Video.mp4");
	VideoWriter writer;
	auto w = capture.get(CAP_PROP_FRAME_WIDTH);
	auto h = capture.get(CAP_PROP_FRAME_HEIGHT);
	auto fps = capture.get(CAP_PROP_FPS);
	auto frames = capture.get(CAP_PROP_FRAME_COUNT);
	std::cout << "Width=" << w << " height=" << h << "\n";
	std::cout << "Fps=" << fps << " frames=" <<
		frames << "\n";

	if (capture.isOpened())
	{
		int codec = VideoWriter::fourcc('X', 'V', 'I', 'D');
		writer.open("outfile.mp4", codec, fps,
			Size(w, h));
		while (capture.read(frame))
		{
			roi = frame(Rect(w - 50, h - 50, 48, 48)); // выделяем регион рисования логотипа на кадре
			vector<Mat> channels(4); // вектор каналов логотипа BGRA
			split(watermark, channels); // Делим изображение логотипа на каналы
			vector<Mat> bgr_channels = { channels[0], channels[1], channels[2] }; // выбираем только цветовые каналы без прозрачности
			merge(bgr_channels, bgr_logo); // объединяем каналы в целое изображение
			channels[3].convertTo(alpha_mask, CV_32F, opacity / 255.0); // преобразовываем альфа канал в float и добавляем к нему базовую прозрачность логотипа
			// циклы попиксельного смешивания изображения и логотипа
			for (int r = 0; r < logo_h; r++)
				for (int c = 0; c < logo_w; c++)
				{
					float alpha = alpha_mask.at<float>(r, c); // берем прозрачность пикселя из альфаканала
					if (alpha > 0) // если пиксель логотипа не полностью прозрачен, смешиваем его с изображением
					{
						Vec3b& roi_pixel = roi.at<Vec3b>(r, c); // берем пиксель изображения
						Vec3b& logo_pixel = bgr_logo.at<Vec3b>(r, c); // берем пиксель логотипа
						// смешиваем цвета каждого канала по формуле
						roi_pixel[0] = roi_pixel[0] * (1 - alpha) + logo_pixel[0] * alpha; // синий
						roi_pixel[1] = roi_pixel[1] * (1 - alpha) + logo_pixel[1] * alpha; // зеленый
						roi_pixel[2] = roi_pixel[2] * (1 - alpha) + logo_pixel[2] * alpha; // красный
					}
				}

			writer.write(frame); // записываем измененный кадр в выходной файл
			imshow("Video from file", frame);

			auto key = waitKey((int)(1 / fps * 1000));
			if (key == 27) break;
		}
		capture.release();
		writer.release();
		destroyAllWindows();
	}
}
