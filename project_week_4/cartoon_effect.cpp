#include "cartoon_effect.h"

cv::Mat cartoonEffect(cv::Mat image);

void cartoonParser(int argc, const char** argv)
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
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = cartoonEffect(originalImage);
			cv::imwrite("../../img/cartoon_effect.jpg", resultImage);
			break;
		case 3:
			resultImage = cartoonEffect(originalImage);
			break;
		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = cartoonEffect(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Cartoon Effect", cv::WINDOW_AUTOSIZE);
	cv::imshow("Cartoon Effect", resultImage);
	cv::waitKey(0);
}

cv::Mat cartoonEffect(cv::Mat image)
{
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}
	
	cv::Mat blurImage;
	cv::medianBlur(image, blurImage, 3);

	cv::Mat edgesImage;
	cv::Canny(blurImage, edgesImage, 90, 270);
	cv::bitwise_not(edgesImage, edgesImage);

	cv::Mat kernel = cv::Mat::ones(2, 2, CV_32F);
	cv::morphologyEx(edgesImage, edgesImage, cv::MORPH_ERODE, kernel);

	cv::medianBlur(blurImage, blurImage, 17);
	blurImage = blurImage / 32;
	blurImage *= 32;
	
	cv::Mat resultImage;
	cv::bitwise_and(blurImage, blurImage, resultImage, edgesImage);

	return resultImage;
}
