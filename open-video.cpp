#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>


int main()
{
	cv::VideoCapture vid("1280.mp4");
	cv::namedWindow("Video", cv::WINDOW_AUTOSIZE);

	double fps = vid.get(CAP_PROP_FPS);

	std::cout << fps << "\n";

	if(!vid.isOpened())
	{
		std::cerr << "File could not be read" << "\n";
		return EXIT_FAILURE;
	}

	while(true)
	{
		cv::Mat video;

		bool frame = vid.read(video);

		if (cv::waitKey(30) == 27 || !frame)
		{
			cv::destroyWindow("Video");
			break;
		}

		cv::imshow("Video", video);
	}

	return EXIT_SUCCESS;
}