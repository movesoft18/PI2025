#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;


int main()
{
	Mat frame;
	VideoCapture capture("Video.mp4");
	VideoWriter writer;
	auto w = capture.get(CAP_PROP_FRAME_WIDTH);
	auto h = capture.get(CAP_PROP_FRAME_HEIGHT);
	auto fps = capture.get(CAP_PROP_FPS);
	auto frames = capture.get(CAP_PROP_FRAME_COUNT);
	std::cout << "Width=" << w << " height=" << h << "\n";
	std::cout << "Fps=" << fps << " frames=" << 
		frames << "\n";

	if (capture.isOpened())
	{
		int codec = VideoWriter::fourcc('X','V','I','D');
		writer.open("outfile.mp4", codec, 30.0,
			Size(w, h), false);
		while (capture.read(frame))
		{
			imshow("Video from file", frame);
			cvtColor(frame, frame, COLOR_BGR2GRAY);
			Canny(frame, frame, 220, 255);
			imshow("Gray video from file", frame);
			writer.write(frame);
			auto key = waitKey((int)(1/fps*1000));
			if (key == 27) break;
		}
		capture.release();
		writer.release();
		destroyAllWindows();
	}
}
