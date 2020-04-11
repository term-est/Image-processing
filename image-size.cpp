#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>


int main()
{

	cv::Mat img = imread("test.jpeg");

	unsigned const int columns = img.cols;
	unsigned const int rows = img.rows;

	std::cout << "Columns : " << columns << "\n" << "Rows : " << rows << std::endl;

	cv::namedWindow("Image");
	cv::imshow("Image", img);

	cv::waitKey(0);
	
	cv::destroyWindow("Image");

	return 0;
}