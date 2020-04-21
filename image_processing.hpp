#ifndef __IMAGE_PROCESSING_HPP__
#define __IMAGE_PROCESSING_HPP__


#include <iostream>
#include <string>
#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

void open_image(std::string filename);

void open_video(std::string filename);

void find_circles(std::string filename);

void print_image_size(std::string filename);

void open_webcam();

void sierpinski();

void empty_image();

void empty_gray_image();

void binary_image(std::string filename);

void merge_split(std::string filename);

void negative_image(std::string filename);

void reach_pixel(std::string filename);

void recolor_image(std::string filename);

void gray_image_intensity(std::string filename);

void image_contrast(std::string filename);

void image_contrast_manuel(std::string filename);

#endif