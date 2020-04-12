#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


int main()
{
	cv::VideoCapture vid("1280.mp4");


	if(!vid.isOpened())
	{
		std::cerr << "File could not be read" << "\n";
		return EXIT_FAILURE;
	}

	cv::namedWindow("Video", cv::WINDOW_AUTOSIZE);

	float fps = vid.get(cv::CAP_PROP_FPS);

	std::cout << fps << "\n";


	cv::Mat video;
	bool frame = vid.read(video);

	while(cv::waitKey(30) != 27 && frame)
	{
		cv::imshow("Video", video);
		frame = vid.read(video);
	}

	cv::destroyWindow("Video");

	return EXIT_SUCCESS;
}