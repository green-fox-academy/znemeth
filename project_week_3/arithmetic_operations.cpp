#include "arithmetic_operations.h"

cv::Mat addImage(cv::Mat image, cv::Mat image2);
cv::Mat subtractImage(cv::Mat image, cv::Mat image2);
cv::Mat multiplyImage(cv::Mat image, cv::Mat image2);
cv::Mat divideImage(cv::Mat image, cv::Mat image2);

void addParser(int argc, const char** argv)
{
	cv::Mat originalImage;
	cv::Mat originalImage2;
	cv::Mat resultImage;
	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");

	switch (saving)
	{
	case true:
		switch (argc)
		{
		case 4:
			resultImage = addImage(originalImage, originalImage2);
			break;
		case 5:
			originalImage = cv::imread(argv[3]);
			originalImage2 = cv::imread(argv[4]);
			resultImage = addImage(originalImage, originalImage2);
			cv::imwrite("../../img/add_image.jpg", resultImage);
			break;

		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;

	case false:
		originalImage = cv::imread(argv[2]);
		originalImage2 = cv::imread(argv[3]);
		resultImage = addImage(originalImage, originalImage2);
		break;

	default:
		break;
	}

	cv::namedWindow("Add Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Add Image", resultImage);
	cv::waitKey(0);
}

void subtractParser(int argc, const char** argv)
{
	cv::Mat originalImage;
	cv::Mat originalImage2;
	cv::Mat resultImage;
	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");

	switch (saving)
	{
	case true:
		switch (argc)
		{
		case 4:
			resultImage = subtractImage(originalImage, originalImage2);
			break;
		case 5:
			originalImage = cv::imread(argv[3]);
			originalImage2 = cv::imread(argv[4]);
			resultImage = subtractImage(originalImage, originalImage2);
			cv::imwrite("../../img/subtract_image.jpg", resultImage);
			break;

		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;

	case false:
		originalImage = cv::imread(argv[2]);
		originalImage2 = cv::imread(argv[3]);
		resultImage = subtractImage(originalImage, originalImage2);
		break;

	default:
		break;
	}

	cv::namedWindow("Subtract Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Subtract Image", resultImage);
	cv::waitKey(0);
}

void multiplyParser(int argc, const char** argv)
{
	cv::Mat originalImage;
	cv::Mat originalImage2;
	cv::Mat resultImage;
	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");

	switch (saving)
	{
	case true:
		switch (argc)
		{
		case 4:
			resultImage = multiplyImage(originalImage, originalImage2);
			break;
		case 5:
			originalImage = cv::imread(argv[3]);
			originalImage2 = cv::imread(argv[4]);
			resultImage = multiplyImage(originalImage, originalImage2);
			cv::imwrite("../../img/multiply_image.jpg", resultImage);
			break;

		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;

	case false:
		originalImage = cv::imread(argv[2]);
		originalImage2 = cv::imread(argv[3]);
		resultImage = multiplyImage(originalImage, originalImage2);
		break;

	default:
		break;
	}

	cv::namedWindow("Multiply Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Multiply Image", resultImage);
	cv::waitKey(0);
}

void divideParser(int argc, const char** argv)
{
	cv::Mat originalImage;
	cv::Mat originalImage2;
	cv::Mat resultImage;
	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");

	switch (saving)
	{
	case true:
		switch (argc)
		{
		case 4:
			resultImage = divideImage(originalImage, originalImage2);
			break;
		case 5:
			originalImage = cv::imread(argv[3]);
			originalImage2 = cv::imread(argv[4]);
			resultImage = divideImage(originalImage, originalImage2);
			cv::imwrite("../../img/divide_image.jpg", resultImage);
			break;

		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;

	case false:
		originalImage = cv::imread(argv[2]);
		originalImage2 = cv::imread(argv[3]);
		resultImage = divideImage(originalImage, originalImage2);
		break;

	default:
		break;
	}

	cv::namedWindow("Divide Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Divide Image", resultImage);
	cv::waitKey(0);
}

cv::Mat addImage(cv::Mat image, cv::Mat image2) 
{
	if (image.empty() || image2.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat result(250, 250, CV_8UC1);
		cv::putText(result, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		return result;
	}

	cv::Mat resultImage;
	cv::addWeighted(image, 0.5, image2, 0.5, 0.0, resultImage);
	return resultImage;
}

cv::Mat subtractImage(cv::Mat image, cv::Mat image2) 
{
	if (image.empty() || image2.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat result(250, 250, CV_8UC1);
		cv::putText(result, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		return result;
	}

	cv::Mat resultImage;
	cv::subtract(image, image2, resultImage);
	return resultImage;
}

cv::Mat multiplyImage(cv::Mat image, cv::Mat image2) 
{
	if (image.empty() || image2.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat result(250, 250, CV_8UC1);
		cv::putText(result, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		return result;
	}

	cv::Mat resultImage;
	cv::multiply(image, image2, resultImage, 1);
	return resultImage;
}

cv::Mat divideImage(cv::Mat image, cv::Mat image2) 
{
	if (image.empty() || image2.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat result(250, 250, CV_8UC1);
		cv::putText(result, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		return result;
	}

	cv::Mat resultImage;
	cv::divide(image, image2, resultImage, 1);
	return resultImage;
}
