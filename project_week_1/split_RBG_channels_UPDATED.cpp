#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat img1 = cv::imread("cortona.jpg");
	cv::Mat img2 = cv::imread("cortona.jpg");
	cv::Mat img3 = cv::imread("cortona.jpg");
	if (img1.empty() || img2.empty() || img3.empty())
	{
		std::cout << "Could not open or find the image!\n" << std::endl;
	}
	else {
		// display image
		cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
		cv::imshow("image", img1);

		cv::Mat RGBchannels1[3];
		cv::split(img1, RGBchannels1);
		//RGBchannels1[0] = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
		RGBchannels1[1] = cv::Mat::zeros(img1.rows, img1.cols, CV_8UC1);
		RGBchannels1[2] = cv::Mat::zeros(img1.rows, img1.cols, CV_8UC1);
		cv::merge(RGBchannels1, 3, img1);
		cv::imshow("blue_image", img1);

		cv::Mat RGBchannels2[3];
		cv::split(img2, RGBchannels2);
		RGBchannels2[0] = cv::Mat::zeros(img2.rows, img2.cols, CV_8UC1);
		//RGBchannels[1] = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
		RGBchannels2[2] = cv::Mat::zeros(img2.rows, img2.cols, CV_8UC1);
		cv::merge(RGBchannels2, 3, img2);
		cv::imshow("green_image", img2);

		cv::Mat RGBchannels3[3];
		cv::split(img3, RGBchannels3);
		RGBchannels3[0] = cv::Mat::zeros(img3.rows, img3.cols, CV_8UC1);
		RGBchannels3[1] = cv::Mat::zeros(img3.rows, img3.cols, CV_8UC1);
		//RGBchannels[2] = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
		cv::merge(RGBchannels3, 3, img3);
		cv::imshow("red_image", img3);

		cv::waitKey(0);
	}
	return 0;
}