#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

int main()
{
	VideoCapture cap(0);

	if (!cap.open(0))	return -1;

	while (true)
	{
		Mat frame;

		cap >> frame;

		if (waitKey(30) == 27 || frame.empty()) break;

		imshow("Webcam Window", frame);
	}

	return 0;
}