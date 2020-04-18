#include "image_processing.hpp"




int main()
{

	open_image("test.jpeg");

	open_video("1280.mp4");

	find_circles("test.jpeg");

	print_image_size("test.jpeg");

	open_webcam();

	sierpinski();


	return EXIT_SUCCESS;
}