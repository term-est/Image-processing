#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>



int main()
{
	cv::Mat org_img = cv::imread("test.jpeg");

	if(org_img.empty())
	{
		std::cerr << "Image could not be displayed \n";
		return EXIT_FAILURE;
	}

		cv::namedWindow("Image Display", cv::WINDOW_AUTOSIZE);
		cv::imshow("Image Display", org_img);

		cv::waitKey(0);
		cv::destroyWindow("Image Display");

	return EXIT_SUCCESS;
}

