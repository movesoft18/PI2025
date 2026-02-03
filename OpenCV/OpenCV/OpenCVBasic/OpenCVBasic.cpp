#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
int main()
{
    setlocale(LC_ALL, "");
    Mat image = imread("image.png");
    if (!image.empty()) 
    {
        imshow("Тестовое изображение", image);
        std::cout << "Ширина изображения: ";
        std::cout << image.cols << std::endl;
        std::cout << "Высота изображения: ";
        std::cout << image.rows << std::endl;
        std::cout << "Число каналов изображения: ";
        std::cout << image.channels() << std::endl;
    }
    //Создаем пустые изображения
    Mat image1(480, 640, CV_8UC3, Scalar(255, 0, 0));
    imshow("Голубое изображение", image1);
    Mat image2(480, 640, CV_8UC3, Scalar::all(0));
    imshow("Черное изображение", image2);
    Mat image3(480, 640, CV_8UC1, Scalar::all(128));
    imshow("Серое изображение", image3);
    Mat gray = imread("image.png", IMREAD_GRAYSCALE);
    imshow("Серое изображение2", gray);
    imwrite("blue_image.jpg", image1);
    imwrite("black_image.bmp", image2);
    waitKey();
    //Создание копии
    Mat imgCopy = image.clone();
    imshow("Копия изображения", imgCopy);
    Rect selectedArea = selectROI("Выберите часть изображения", imgCopy);
    Mat imgCrop = imgCopy(selectedArea);
    imshow("Вырезано", imgCrop);
    waitKey();
    Mat resized, rotated, gray2, bilevel;
    resize(imgCrop, resized, Size(), 5, 3);
    imshow("Изменен размер", resized);
    waitKey();
    rotate(resized, rotated, ROTATE_90_COUNTERCLOCKWISE);
    imshow("Повернуто", rotated);
    cvtColor(rotated, rotated, COLOR_BGR2GRAY);
    imshow("Серое 2", rotated);
    waitKey();
    threshold(gray, bilevel, 180, 255, THRESH_OTSU);
    imshow("Черно-белое", bilevel);
    flip(bilevel, bilevel, -1);
    imshow("Отражено", bilevel);
    waitKey();
}

