#include "decolor.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/photo.hpp>
#include <string>
#include <iostream> 

cv::Mat decolorImage(cv::Mat image);

void decolorParser(int argc, const char** argv)
{
	cv::Mat originalImage;
	cv::Mat resultImage;
	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");

	switch (saving)
	{
	case true:
		switch (argc)
		{
		case 3:
			resultImage = decolorImage(originalImage);
			break;
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = decolorImage(originalImage);
			imwrite("../../img/decolor_image.jpg", resultImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = decolorImage(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Decolorized image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Decolorized image", resultImage);
	cv::waitKey(0);
}

cv::Mat decolorImage(cv::Mat image)
{
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage = cv::Mat(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}
	cv::Mat resultImage, supportImage;
	cv::decolor(image, resultImage, supportImage);

	return resultImage;
}

