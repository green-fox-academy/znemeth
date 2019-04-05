#include<opencv2/opencv.hpp>
#include<iostream>
#include "math.h"
#include <algorithm>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>

int main()
{
	// read in image
	cv::Mat img = cv::imread("cortona.jpg");
	if (img.empty())
	{
		std::cout << "Could not open or find the image!\n" << std::endl;
	}
	
	// display image
	cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
	cv::imshow("image", img);
	
	// number of pixels in cols || IMAGE_HEIGHT
	std::cout << "IMAGE_HEIGHT: " << fmin(img.cols, img.rows) << std::endl;
	// number of pixels in rows || IMAGE_WIDTH
	std::cout << "IMAGE_WIDTH: " << fmax(img.cols, img.rows) << std::endl;

	// contrast
	double alpha = 0.2;
	// brightness
	int beta = 100; 
	
	// calculation for contrast and brightness
	cv::Mat new_image = cv::Mat::zeros(img.size(), img.type());

	for (int y = 0; y < img.rows; y++) {
		for (int x = 0; x < img.cols; x++) {
			for (int c = 0; c < img.channels(); c++) {
				new_image.at<cv::Vec3b>(y, x)[c] =
					cv::saturate_cast<uchar>(alpha*img.at<cv::Vec3b>(y, x)[c] + beta);
			}
		}
	}
	
	// display NEW (contrast and brightness) image
	cv::namedWindow("new_image", cv::WINDOW_AUTOSIZE);
	cv::imshow("new_image", new_image);

	// create GREY aimge
	cv::Mat grey_image;
	cv::cvtColor(img, grey_image, cv::COLOR_BGR2GRAY);

	// display NEW image
	cv::namedWindow("grey_image", cv::WINDOW_AUTOSIZE);
	cv::imshow("grey_image", grey_image);

	// draw line
	//cv::line(grey_image, origin(0,0), origin(0, 0). BLUE, 3, 8, 0);

	cv::waitKey(0);
	return 0;
}