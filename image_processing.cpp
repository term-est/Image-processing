#include "image_processing.hpp"
using namespace cv;

void open_image(std::string filename)
{
	cv::Mat org_img = cv::imread(filename);

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
	cv::VideoCapture vid(filename);


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
	cv::Mat img = cv::imread(filename);

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

	cv::destroyWindow("detected circles");
	
	return;
}

void print_image_size(std::string filename)
{
	cv::Mat img = cv::imread(filename);

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

	cv::destroyWindow("Webcam Window");

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

	cv::waitKey();

	return;
}

void empty_image()
{

	cv:: Mat creat_img(240, 240, CV_8UC3, cv :: Scalar(0, 0,0));

	cv:: namedWindow("Image", cv:: WINDOW_AUTOSIZE);

	cv:: imshow("Image", creat_img);

	cv:: waitKey();

	return;
}

void empty_gray_image()
{
	cv:: Mat create_gray(300, 300, CV_8UC1, cv:: Scalar(100));

	cv:: namedWindow("Image", cv:: WINDOW_AUTOSIZE);

	cv:: imshow("Image", create_gray);

	cv:: waitKey(0);

	cv::destroyWindow("Image");

	return;
}

void binary_image(std::string filename)
{
	cv:: Mat org_img = cv:: imread(filename);
	cv:: Mat gray, binary_img;
	
	cv:: cvtColor(org_img, gray, cv:: COLOR_BGR2GRAY);

	cv:: threshold(gray, binary_img, 100, 255, cv:: THRESH_OTSU);

	cv:: imshow("Orginal Image", org_img);
	cv:: imshow("Gray Image",gray);
	cv:: imshow("Binary Image", binary_img);

	cv:: waitKey(0);

	cv::destroyAllWindows();
	return;
}

void merge_split(std::string filename)
{

	cv:: Mat img = cv:: imread(filename);

	cv:: imshow("Orginal Image", img);

	cv:: Mat rgbchannel[3];

	cv:: split(img, rgbchannel);

	cv::imshow("Red", rgbchannel[0]);
	cv::imshow("Green", rgbchannel[1]);
	cv::imshow("Blue", rgbchannel[2]);

	cv:: Mat merged_image;

	std:: vector<cv::Mat> channels;

	channels.push_back(rgbchannel[0]);
	channels.push_back(rgbchannel[1]);
	channels.push_back(rgbchannel[2]);

	cv:: merge(channels, img);

	cv:: imshow("Merged", img);


	cv::waitKey(0);

	cv::destroyAllWindows();

	return;
}

void negative_image(std::string filename)
{
	cv:: Mat img = cv:: imread(filename);
	cv:: Mat negative_image;

	cv:: bitwise_not(img, negative_image);

	cv:: imshow("Orginal Image", img);
	cv:: imshow("Negative Image", negative_image);

	cv::waitKey(0);

	cv::destroyAllWindows();

	return;
}

void reach_pixel(std::string filename)
{
	cv:: Mat img = cv:: imread(filename);

 	int blue = img.at<cv:: Vec3b>(100, 120)[0];
 	int green = img.at<cv:: Vec3b>(100, 120)[1];
	int red = img.at<cv:: Vec3b>(100, 120)[2];

	std::cout << "[100][120] blue value = " << blue <<std::endl;
	std::cout << "[100][120] green value = " << green <<std::endl;
	std::cout << "[100][120] red value = " << red <<std::endl;

	cv:: imshow("Image", img);
	cv:: waitKey(0);

	cv::destroyWindow("Image");
}

void recolor_image(std::string filename)
{

	cv:: Mat org_img = cv:: imread(filename);

	cv:: Mat gray_img;

	cv:: cvtColor(org_img,gray_img, cv:: COLOR_BGR2GRAY);

	cv:: imshow("Orginal Image",org_img);
	cv:: imshow("Gray Image", gray_img);

	cv:: waitKey(0);

	cv::destroyAllWindows();

	return;
}

void gray_image_intensity(std::string filename)
{
	cv::Mat img = cv:: imread(filename);

	cv:: cvtColor(img,img,cv:: COLOR_BGR2GRAY);

	int intensity = img.at<uchar>(100,120);

	std::cout << "[100][120] intensity value = " << intensity << std::endl;

	cv:: imshow("Image", img);

	cv:: waitKey(0);

	cv::destroyWindow("Image");

	return;
}

void image_contrast(std::string filename)
{

	cv::Mat img = cv::imread(filename);
	cv::Mat new_low, new_high;

	img.convertTo(new_low, -1, 0.2, 0);
	img.convertTo(new_high, -1, 2, 0);

	cv::imshow("Orginal Image", img);
	cv::imshow("Low Contrast Image", new_low);
	cv::imshow("High Contrast Image", new_high);

	cv::waitKey();

	cv::destroyAllWindows();

	return;
}

void image_contrast_manuel(std::string filename)
{
	int depth;
	float multiple;
	cv::Mat img = cv::imread(filename);

	std::cout << "Depth : ";
	std::cin >> depth;

	std::cout << "multiple : ";
	std::cin >> multiple;

	if(depth == -1)
	{
		for (int i = 0; i < img.rows; ++i)
		{
			for (int j = 0; j < img.cols; ++j)
			{
				if(img.at<cv::Vec3b>(i,j)[0]*multiple > 255) img.at<cv::Vec3b>(i,j)[0] = 255;
				else img.at<cv::Vec3b>(i,j)[0] *= multiple;

				if(img.at<cv::Vec3b>(i,j)[1]*multiple > 255) img.at<cv::Vec3b>(i,j)[1] = 255;
				else img.at<cv::Vec3b>(i,j)[1] *= multiple;

				if(img.at<cv::Vec3b>(i,j)[2]*multiple > 255) img.at<cv::Vec3b>(i,j)[2] = 255;
				else img.at<cv::Vec3b>(i,j)[2] *= multiple;
			}
		}
		cv::imshow("Image",img);
		cv::waitKey();
		cv::destroyWindow("Image");
	}
	else
	{
		cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);

		for (int i = 0; i < img.rows; ++i)
		{
			for (int j = 0; j < img.cols; ++j)
			{
				if (img.at<uchar>(i,j)*multiple > 255) img.at<uchar>(i,j) = 255;
				else img.at<uchar>(i,j) *= multiple;
			}
		}
		cv::imshow("Image",img);
		cv::waitKey();
		cv::destroyWindow("Image");
	}
	return;
}