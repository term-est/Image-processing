#include <iostream>
#include <vector>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


int main()
{
  
 
	cv::Mat img = cv::imread("test.jpeg");

	if(img.empty())
	{
		std::cerr << "Error opening image" << std::endl;;
		return EXIT_FAILURE;
	}

	cv::Mat gray;

	cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
	cv::medianBlur(gray, gray, 5);
	
	std::vector<cv::Vec3f> circles;

	cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / 8, 80, 30, 0, 0);

	for(size_t i = 0; i < circles.size(); i++)
	{
		cv::Vec3i c = circles[i];
		cv::Point center = cv::Point(c[0], c[1]);
		cv::circle(img, center, 1, cv::Scalar(0,100,100), 3, cv::LINE_AA);

		int radius = c[2];
		circle(img, center, radius, cv::Scalar(255,0,255), 3, cv::LINE_AA);
	}

	cv::imshow("detected circles", img);
	cv::waitKey();
	
	return EXIT_SUCCESS;
}