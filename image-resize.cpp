#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>




int main()
{

	cv::Mat img1 = cv::imread("test.jpeg"), img2 = cv::imread("gradyan.bmp");
	cv::Mat size;

	cv::resize(img1, size, cv::Size(img2.cols, img2.rows));

	cv::namedWindow("Image1", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Image2", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("ResizeImage", cv::WINDOW_AUTOSIZE);
	


	cv::imshow("Image1", img1);
	cv::imshow("Image2", img2);
	cv::imshow("ResizeImage", size);

	cv::waitKey(0);


	cv::destroyAllWindows();

	return EXIT_SUCCESS;
}