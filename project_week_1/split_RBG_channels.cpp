#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <opencv2/core/core.hpp>

int main()
{
	cv::Mat img = cv::imread("cortona.jpg");
	if (img.empty())
	{
		std::cout << "Could not open or find the image!\n" << std::endl;
	}

	// display image
	cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
	cv::imshow("image", img);

	// split image into 3 channels
	cv::Mat RGBchannels[3];
	cv::split(img, RGBchannels);

	// for BLUE color comment this line:
	RGBchannels[0] = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
	// for GREEN color comment this line:
	RGBchannels[1] = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
	// for RED color comment this line:
	//RGBchannels[2] = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);

	cv::merge(RGBchannels, 3, img);
	cv::imshow("color", img);

	cv::waitKey(0);
	return 0;
}