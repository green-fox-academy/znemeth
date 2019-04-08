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
	
	// ONLY FOR LANDSCAPE TYPE IMAGES
	// number of pixels in cols || IMAGE_HEIGHT
	std::cout << "IMAGE_HEIGHT: " << fmin(img.cols, img.rows) << std::endl;
	// number of pixels in rows || IMAGE_WIDTH
	std::cout << "IMAGE_WIDTH: " << fmax(img.cols, img.rows) << std::endl;

	// create GREY aimge
	cv::Mat grey_image;
	cv::cvtColor(img, grey_image, cv::COLOR_BGR2GRAY);

	// display GREY image
	cv::namedWindow("grey_image", cv::WINDOW_AUTOSIZE);
	cv::imshow("grey_image", grey_image);

	// contrast
	double alpha = 0.5;
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

	int x1 = 0;
	int y1 = 0;
	int x2 = 200;
	int y2 = 300;
	cv::Point pnt1 (x1, y1);
	cv::Point pnt2(x2, y2);
	cv::Scalar color(9, 199, 242);

	cv::line(new_image, pnt1, pnt2, color, 3, 8, 0);

	// display CONTRAST and BRIGHTNESS image WITH LINE
	cv::namedWindow("new_image", cv::WINDOW_AUTOSIZE);
	cv::imshow("new_image", new_image);

	// draw circle
	cv::Scalar color2(21, 21, 215);
	cv::circle(img, cv::Point(img.cols/2, img.rows/2), 30, color2, 8, 8, 0);
	
	// draw rectangle
	cv::Scalar color3(110, 160, 110);
	cv::rectangle(img, pnt1, pnt2, color3, 10, 8, 0);

	// draw ellipse
	cv::Point center(200, 300);
	cv::ellipse(img, center, cv::Size(100.0, 160.0), 300, 0, 200, cv::Scalar(110, 60, 10), 3);

	// display image
	cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
	cv::imshow("image", img);

	// blend 2 images
	cv::Mat dst;

	cv::Mat src1 = cv::imread("bckgrnd.jpg");
	cv::Mat src2 = cv::imread("fellini.jpg");
	cv::resize(src2, src2, src1.size());

	cv::namedWindow("linear_blend", 1);
	double alpha2 = 0.5;
	double beta2 = (1.0 - alpha2);
	cv::addWeighted(src1, alpha, src2, beta2, 0.0, dst);
	cv::imshow("linear_blend", dst);

	cv::RNG rand;
	int random = (unsigned)rand % 100 + 1;
	std::cout << "random number: " << random << std::endl;

	cv::waitKey(0);
	return 0;
}