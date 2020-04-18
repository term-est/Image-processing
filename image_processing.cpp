#include "image_processing.hpp"
using namespace cv;

void open_image(std::string filename)
{
	cv::Mat org_img = cv::imread("test.jpeg");

	if(org_img.empty())
	{
		std::cerr << "Image could not be displayed \n";
		return;
	}

	cv::namedWindow("Image Display", cv::WINDOW_AUTOSIZE);
	cv::imshow("Image Display", org_img);

	cv::waitKey(0);
	cv::destroyWindow("Image Display");

	return;
}

void open_video(std::string filename)
{
	cv::VideoCapture vid("1280.mp4");


	if(!vid.isOpened())
	{
		std::cerr << "File could not be read" << "\n";
		return;
	}

	cv::namedWindow("Video", cv::WINDOW_AUTOSIZE);

	float fps = vid.get(cv::CAP_PROP_FPS);

	std::cout << fps << "\n";


	cv::Mat video;
	bool frame = vid.read(video);

	while(cv::waitKey(30) != 27 && frame)
	{
		cv::imshow("Video", video);
		frame = vid.read(video);
	}

	cv::destroyWindow("Video");

	return;
}

void find_circles(std::string filename)
{
	cv::Mat img = cv::imread("test.jpeg");

	if(img.empty())
	{
		std::cerr << "Error opening image" << std::endl;;
		return;
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
	
	return;
}

void print_image_size(std::string filename)
{
	cv::Mat img = cv::imread("test.jpeg");

	if(img.empty())
	{
		std::cerr << "Error opening image" << std::endl;;
		return;
	}

	unsigned const int columns = img.cols;
	unsigned const int rows = img.rows;

	std::cout << "Columns : " << columns << "\n" << "Rows : " << rows << std::endl;

	cv::namedWindow("Image");
	cv::imshow("Image", img);

	cv::waitKey(0);
	
	cv::destroyWindow("Image");

	return;
}

void open_webcam()
{
	cv::VideoCapture capture(0);

	if(!capture.open(0))	
	{
		std::cerr << "Failure" << std::endl;
		return;
	}

	while(true)
	{
		cv::Mat frame;

		capture >> frame;

		if(cv::waitKey(30) == 27 || frame.empty())	break;

		cv::imshow("Webcam Window", frame);
	}

	return;
}

void sierpinski()
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

	return;
}