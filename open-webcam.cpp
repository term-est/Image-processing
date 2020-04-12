#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>




int main()
{
	cv::VideoCapture capture(0);

	if(!capture.open(0))	
	{
		std::cerr << "Failure" << std::endl;
		return EXIT_FAILURE;
	}

	while(true)
	{
		cv::Mat frame;

		capture >> frame;

		if(cv::waitKey(30) == 27 || frame.empty())	break;

		cv::imshow("Webcam Window", frame);
	}

	return EXIT_SUCCESS;
}