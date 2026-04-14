#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
     Mat result;
     double minVal;
     double maxVal;
     Point minLoc;
     Point maxLoc;
     Mat img = imread("field.jpg");
     Mat temp = imread("template.jpg");
     matchTemplate(img, temp, result, TM_CCORR_NORMED);
     imshow("results", result);
     minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
     double corr = maxVal;
     if (corr > 0.9)
     {
         int x = maxLoc.x;
         int y = maxLoc.y;
         ellipse(img, Point(x + temp.rows / 2, y + temp.cols / 2),
             Size(temp.rows / 2, temp.cols / 2), 0, 0,
             360, Scalar(255, 0, 255), 2);
         imshow("Image", img);
         cout << "x=" << x << " y=" << y << " corr=" << corr << endl;
     }
     else
     {
         cout << "Template not found\n";
     }
     waitKey();
     
}
