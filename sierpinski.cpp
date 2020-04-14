#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"


int main()
{
	cv:: Mat creat_img(1080, 1920, CV_8UC4, cv::Scalar(0, 0, 0, 0));

	cv::Point triangle[4] = {{1079,1920}, {0,1920/2}, {1079,0}, {rand() % 1080, rand() % 1920}}; 

	for(unsigned int i = 0; i < 1080; ++i)
	for(unsigned int j = 0; j < 1920; ++j)
	{
		creat_img.at<cv::Vec4b>(i,j)[0] = (i + j) * 255 / (1080 + 1920);
		creat_img.at<cv::Vec4b>(i,j)[1] = (i * j) * 255 / (1080 * 1920);
		creat_img.at<cv::Vec4b>(i,j)[2] = j * 255 / 1920;
		creat_img.at<cv::Vec4b>(i,j)[3] = i * 255 / 1920;
	}


	for(unsigned int rand_ = rand() % 3, i = 0; i < 1000000; ++i, rand_ = rand() % 3)
	{
		triangle[3].y = (triangle[rand_].y + triangle[3].y) / 2;
		triangle[3].x = (triangle[rand_].x + triangle[3].x) / 2;
		creat_img.at<cv::Vec4b>(triangle[3].x, triangle[3].y)[3] = 255;


	}



	cv::namedWindow("Image", cv::WINDOW_AUTOSIZE);

	cv::imwrite("transparan.png", creat_img);

	cv::waitKey(0);

	return EXIT_SUCCESS;
}