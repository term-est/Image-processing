#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

Mat orgImage;

int main()
{
	orgImage = imread("Test.jpeg");
	namedWindow("Image Display", WINDOW_AUTOSIZE);

	if (orgImage.empty())
	{
		std::cout << "Image could not upload \n";
		return -1;
	}
	else
	{
		imshow("Image Display", orgImage);
		waitKey(0);
		destroyWindow("Image Display");
	}

	return 0;
}

