#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

constexpr int minArea = 10000;

void findAllBalls()
{
    std::vector<std::vector<Point>> cnts, selectedCnts;
    Mat result, HSV, blurred;
    Mat image = imread("3.webp");
    resize(image, image, Size(), 0.75, 0.75);
    medianBlur(image, blurred, 13);
    imshow("blured", blurred);
    cvtColor(blurred, HSV, COLOR_BGR2HSV);
    inRange(HSV, Scalar(159, 71, 210),
        Scalar(180, 255, 255), result);
    imshow("bw", result);
    findContours(result, cnts, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    for (auto& c : cnts)
    {
        double area = contourArea(c);
        if (area > minArea)
        {
            selectedCnts.push_back(c);
            auto mom = moments(c);
            int x = mom.m10 / mom.m00;
            int y = mom.m01 / mom.m00;
            circle(image, Point(x,y), 9, Scalar(0, 255, 255), -1);
        }
    }
    drawContours(image, selectedCnts, -1, Scalar(0, 255, 0), 3);
    imshow("cnts", image);
    waitKey();
}

int main()
{
    findAllBalls();
    Mat result, HSV;
    Mat image = imread("3.webp");
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
