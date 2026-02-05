#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
int main()
{
    Mat image = imread("image.png");
    imshow("Woman", image);
    Mat crop = image(Rect(100, 100, 80, 150));
    imwrite("cropped.png", crop);
    imshow("Часть человека", crop);
    waitKey();
}