#include "operations.h"

void operations() {
	cv::Mat img1 = cv::imread("speaker.jpg");
	cv::Mat img2 = cv::imread("new_york.jpg");
	cv::Mat final_img;
	cv::Mat final_img2;
	cv::Mat final_img3;
	cv::Mat final_img4;

	if (img1.empty() || img2.empty())
	{
		std::cout << "Could not open or find the image!\n" << std::endl;
	}
	else {
		
		cv::namedWindow("image1", cv::WINDOW_AUTOSIZE);
		cv::imshow("image1", img1);
		cv::namedWindow("image2", cv::WINDOW_AUTOSIZE);
		cv::imshow("image2", img2);

		cv::addWeighted(img1, 0.5, img2, 0.5, 0.0, final_img);
		cv::namedWindow("final_image", cv::WINDOW_AUTOSIZE);
		cv::imshow("final_image", final_img);

		cv::subtract(img1, img2, final_img2);
		cv::namedWindow("final_image2", cv::WINDOW_AUTOSIZE);
		cv::imshow("final_image2", final_img2);

		cv::multiply(img1, img2, final_img3, 1);
		cv::namedWindow("final_image3", cv::WINDOW_AUTOSIZE);
		cv::imshow("final_image3", final_img3);

		cv::divide(img1, img2, final_img4, 1);
		cv::namedWindow("final_image4", cv::WINDOW_AUTOSIZE);
		cv::imshow("final_image4", final_img4);
	}

	cv::waitKey(0);
}