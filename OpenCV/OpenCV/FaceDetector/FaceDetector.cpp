
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;

int main()
{
	CascadeClassifier cascade;
	vector<Rect> faces;
	
	if (!cascade.load("C:\\openCV\\build\\etc\\haarcascades\\haarcascade_frontalface_alt2.xml"))
	//if (!cascade.load("C:\\openCV\\build\\etc\\haarcascades\\haarcascade_russian_plate_number.xml"))
			return 1;
	Mat img = imread("2.jpg");

	cascade.detectMultiScale(img, faces , 1.03, 5, 0, Size(5, 5), Size(50, 50));
	//cascade.detectMultiScale(img, faces);// , 1.03, 5, 0, Size(5, 5), Size(50, 50));
	for (auto& face : faces)
	{
		rectangle(img, face, Scalar(255, 30, 0), 2);
	}
	imshow("Faces", img);

	waitKey();
	for (auto& face : faces)
	{
		auto crop = img(face);
		blur(crop, crop, Size(27, 27));
	}
	imshow("Faces", img);

	waitKey();
	destroyAllWindows();
}