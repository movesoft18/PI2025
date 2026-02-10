#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

int main()
{
	Mat image = imread("eurobot.bmp");
	imshow("Оригинал", image);
	medianBlur(image, image, 3);
	imshow("Отфильтровано", image);
	Mat image1 = imread("image.jpg");
	imshow("Оригинал2", image1);
	medianBlur(image1, image1, 9);
	imshow("Отфильтровано2", image1);
	Mat image2 = imread("image2.jpg");
	imshow("Оригинал3", image2);
	GaussianBlur(image2, image2, Size(9,9), 0);
	imshow("Отфильтровано3", image2);
	Mat image3 = imread("eurobot.bmp");
	imshow("Оригинал4", image3);
	GaussianBlur(image3, image3, Size(3,3),0);
	imshow("Отфильтровано4", image3);
	waitKey();
	destroyAllWindows();
}

