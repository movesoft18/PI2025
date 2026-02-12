#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat frame;
	VideoCapture capture(0);
	capture.set(CAP_PROP_FRAME_WIDTH, 320);
	capture.set(CAP_PROP_FRAME_HEIGHT, 240);
	//capture.set(CAP_PROP_FPS, 3);
	auto w = capture.get(CAP_PROP_FRAME_WIDTH);
	auto h = capture.get(CAP_PROP_FRAME_HEIGHT);
	auto fps = capture.get(CAP_PROP_FPS);
	cout << "width= " << w << " height= " << h << " fps=" << fps << endl;
	if (capture.isOpened())
	{
		while (true)
		{
			bool result = capture.read(frame);
			if (result)
			{
				imshow("Live video", frame);
				auto key = waitKey(1);
				if (key == 27) break;
			}
		}
		capture.release();
		destroyAllWindows();
	}
   
}
