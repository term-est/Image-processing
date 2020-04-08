#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;

Mat newsize;

int main()
{
	Mat img1 = imread("gradyan.bmp");
	Mat img2 = imread("Test.jpeg");

	resize(img1, newsize, Size(img2.cols, img2.rows));

	namedWindow("Image1", WINDOW_AUTOSIZE);
	namedWindow("Image2", WINDOW_AUTOSIZE);
	namedWindow("ResizeImage", WINDOW_AUTOSIZE);
	


	while (true)
	{
		imshow("Image1", img1);
		imshow("Image2", img2);
		imshow("ResizeImage", newsize);

		if (waitKey(30) == 27)
		{
			break;
		}
	}
	destroyAllWindows();
	return 0;
}