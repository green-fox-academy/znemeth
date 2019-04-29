#include "salt_effect.h"

cv::Mat saltEffect(cv::Mat image);

void saltParser(int argc, const char** argv)
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
			resultImage = saltEffect(originalImage);
			cv::imwrite("../../img/salt_effect.jpg", resultImage);
			break;
		case 3:
			resultImage = saltEffect(originalImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
		break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = saltEffect(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Salt Effect", cv::WINDOW_AUTOSIZE);
	cv::imshow("Salt Effect", resultImage);
	cv::waitKey(0);
}

cv::Mat saltEffect(cv::Mat image)
{
	cv::Mat resultImage = image.clone();
	if (resultImage.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		
		return errorImage;
	}
	cv::RNG randomNumber; 
	float salt_strongness = 0.02;
	int strongness = resultImage.rows * resultImage.cols * salt_strongness; 

	cv::Vec<uchar, 3> whitePixel = { 255, 255, 255 };
	for (int i = 0; i < strongness; i++) {
		resultImage.at<cv::Vec3b>(randomNumber.uniform(0, resultImage.rows), randomNumber.uniform(0, resultImage.cols)) = whitePixel;
	}

	return resultImage;
}
