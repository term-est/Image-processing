#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

int main()
{

	Mat img = imread("Test.jpeg");

	int columns = img.cols;
	int rows = img.rows;

	std::cout << "Sutunlar : " << columns << std::endl << "Satirlar : " << rows << std::endl;

	namedWindow("Image");

	imshow("Image", img);

	waitKey(0);
	
	destroyWindow("Image");

	return 0;
}