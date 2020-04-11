#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>



int main()
{

	cv::Mat img1 = imread("test.jpeg"), img2 = imread("gradyan.bmp");

	cv::resize(img1, Mat(), Size(img2.cols, img2.rows));

	cv::namedWindow("Image1", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Image2", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("ResizeImage", cv::WINDOW_AUTOSIZE);
	


	while(true)
	{
		cv::imshow("Image1", img1);
		cv::imshow("Image2", img2);
		cv::imshow("ResizeImage", Mat());

		if(cv::waitKey(30) == 27)	break;
	}

	cv::destroyAllWindows();

	return EXIT_SUCCESS;
}