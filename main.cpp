#include "image_processing.hpp"




int main()
{

	open_image("test.jpeg");

	open_video("1280.mp4");

	find_circles("test_gray.jpeg");

	print_image_size("test.jpeg");

	open_webcam();

	sierpinski();

	empty_image();

	empty_gray_image();

	binary_image("test.jpeg");

	merge_split("test.jpeg");

	negative_image("test.jpeg");

	reach_pixel("test.jpeg");

	recolor_image("test.jpeg");

	gray_image_intensity("test.jpeg");

	image_contrast("test.jpeg");

	image_contrast_manuel("test.jpeg");

	return EXIT_SUCCESS;
}