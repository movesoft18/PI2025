#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
int main()
{
    Mat image = imread("image.png");
    if (!image.empty()) 
    {
        imshow("Тестовое изображение", image);
        waitKey();
    }
}

