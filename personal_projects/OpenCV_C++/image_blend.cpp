#include "image_blend.h"

const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;

cv::Mat image1;
cv::Mat image2;
cv::Mat dst;

static void on_trackbar(int, void*)
{
	alpha = (double)alpha_slider / alpha_slider_max;
	beta = (1.0 - alpha);
	cv::addWeighted(image1, alpha, image2, beta, 0.0, dst);
	cv::imshow("Linear Blend", dst);
}

void image_blend() {
	
	image1 = cv::imread("C:\\Users\\NEMETH\\Desktop\\speaker.jpg");
	image2 = cv::imread("C:\\Users\\NEMETH\\Desktop\\new_york.jpg");
	//cv::imshow("ORIGINAL IMAGE 1", image1);
	//cv::imshow("ORIGINAL IMAGE 2", image2);

	alpha_slider = 0;
	cv::namedWindow("Linear Blend", cv::WINDOW_AUTOSIZE);
	char TrackbarName[50];
	sprintf_s(TrackbarName, "Alpha %d", alpha_slider_max);
	cv::createTrackbar(TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar);
	on_trackbar(alpha_slider, 0);
}
