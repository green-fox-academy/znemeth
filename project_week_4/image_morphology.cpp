#include "image_morphology.h"

cv::Mat erodeImage(cv::Mat image);
cv::Mat dilateImage(cv::Mat image);
cv::Mat closingImage(cv::Mat image);
cv::Mat openingImage(cv::Mat image);

void erodeParser(int argc, const char** argv)
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
			resultImage = erodeImage(originalImage);
			cv::imwrite("../../img/erosion.jpg", resultImage);
			break;
		case 3:
			resultImage = erodeImage(originalImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = erodeImage(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Eroded Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Eroded Image", resultImage);
	cv::waitKey(0);
}

void dilateParser(int argc, const char** argv)
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
			resultImage = dilateImage(originalImage);
			cv::imwrite("../../img/dilate.jpg", resultImage);
			break;
		case 3:
			resultImage = dilateImage(originalImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = dilateImage(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Dilated Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Dilated Image", resultImage);
	cv::waitKey(0);
}

void closingParser(int argc, const char** argv)
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
			resultImage = closingImage(originalImage);
			cv::imwrite("../../img/closed.jpg", resultImage);
			break;
		case 3:
			resultImage = closingImage(originalImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = closingImage(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Closed Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Closed Image", resultImage);
	cv::waitKey(0);
}

void openingParser(int argc, const char** argv)
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
			resultImage = openingImage(originalImage);
			cv::imwrite("../../img/opened.jpg", resultImage);
			break;
		case 3:
			resultImage = openingImage(originalImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = openingImage(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Opened Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Opened Image", resultImage);
	cv::waitKey(0);
}

cv::Mat erodeImage(cv::Mat image)
{
	cv::Mat resultImage;
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}

	cv::Mat kernel = cv::Mat::ones(3, 3, CV_32F);
	cv::morphologyEx(image, resultImage, cv::MORPH_ERODE, kernel);

	return resultImage;
}

cv::Mat dilateImage(cv::Mat image)
{
	cv::Mat resultImage;
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}

	cv::Mat kernel = cv::Mat::ones(3, 3, CV_32F);
	cv::morphologyEx(image, resultImage, cv::MORPH_DILATE, kernel);

	return resultImage;
}

cv::Mat closingImage(cv::Mat image)
{
	cv::Mat resultImage;
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}

	cv::Mat kernel = cv::Mat::ones(3, 3, CV_32F);
	cv::morphologyEx(image, resultImage, cv::MORPH_CLOSE, kernel);

	return resultImage;
}

cv::Mat openingImage(cv::Mat image)
{
	cv::Mat resultImage;
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}

	cv::Mat kernel = cv::Mat::ones(3, 3, CV_32F);
	cv::morphologyEx(image, resultImage, cv::MORPH_OPEN, kernel);

	return resultImage;
}
