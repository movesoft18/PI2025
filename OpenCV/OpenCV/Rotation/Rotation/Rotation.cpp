#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int main()
{
	Mat rotated;
	Mat img = imread("image.jpg");
	imshow("Original", img);
	// Точка центра поворота
	Point center = Point2d(img.cols / 2, img.rows / 2);
	double angle = 0;
	while (true)
	{
		// вычисление матрицы поворота
		Mat matrix = getRotationMatrix2D(center, angle, 1);
		// применение поворота по вычисленной матрице
		warpAffine(img, rotated, matrix, Size(img.cols, img.rows));
		imshow("Rotated", rotated);
		angle += 0.5;
		if (waitKey(1) == 27) break; // Выход по Esc
	}
	destroyAllWindows();
}