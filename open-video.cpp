#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

int main()
{
	VideoCapture vid("1280.mp4");
	namedWindow("Video", WINDOW_AUTOSIZE);

	float fps = vid.get(CAP_PROP_FPS);

	std::cout << fps << "\n";

	if (!vid.isOpened())
	{
		std::cout << "Wrong Path!" << "\n";
	}

	while (true)
	{
		Mat video;

		bool frame = vid.read(video);

		if (waitKey(30) == 27 || frame == 0) {
			destroyWindow("Video");
			break;
		}

		imshow("Video", video);
	}

	return 0;
}