#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>



int main()
{
	cv::VideoCapture capture(0);

	if(!cap.open(0))	return EXIT_FAILURE;

	while (true)
	{
		cv::Mat frame;

		capture >> frame;

		if(cv::waitKey(30) == 27 || frame.empty())	break;

		cv::imshow("Webcam Window", frame);
	}

	return EXIT_SUCCESS;
}