#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
    Mat result, HSV;
    Mat image = imread("2.webp");
    resize(image, image, Size(), 0.75, 0.75);
    cvtColor(image, HSV, COLOR_BGR2HSV);
    inRange(HSV, Scalar(159, 71, 210),
        Scalar(180, 255, 255), result);
    auto m = moments(result, true);
    if (m.m00 > 200) // нашли
    {
        int x = m.m10 / m.m00;
        int y = m.m01 / m.m00;
        circle(image, Point(x, y), 7, Scalar(255, 255, 0), -1);
    }
    //medianBlur(result, result, 9);
    imshow("Balls", image);
    imshow("Result", result);
    waitKey();
    destroyAllWindows();
}
