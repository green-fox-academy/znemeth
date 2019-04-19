#include "image_geometry.h"

cv::Mat resizerotateImage(cv::Mat image, double scale);

void resizerotateParser(int argc, const char** argv) {
	cv::Mat originalImage;
	cv::Mat resultImage;
	
	std::string additionalArgumentFirst = argv[2];
	double additionalArgumentSecond = std::stod(argv[3]);
	//int additionalArgumentThird = std::stoi(argv[4]);
	bool method1 = (additionalArgumentFirst == "-resize");

	switch (method1)
	{
	case true:
		switch (argc)
		{ 
		case 4:
			originalImage = cv::imread(argv[1]);
			resultImage = resizerotateImage(originalImage, additionalArgumentSecond);
			cv::imwrite("../../img/resizerotated_image.jpg", resultImage);
			break;

		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;

	case false:
		originalImage = cv::imread(argv[1]);
		resultImage = resizerotateImage(originalImage, additionalArgumentSecond);
		break;

	default:
		break;
	}

	cv::namedWindow("ResizeRotate Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("ResizeRotate Image", resultImage);
	cv::waitKey(0);
}

cv::Mat resizerotateImage(cv::Mat image, double scale) {
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		return errorImage;
	}
	cv::Mat resultImage;
	cv::resize(image, resultImage, cv::Size(), scale, scale);

	cv::Point2f pt(resultImage.cols / 2., resultImage.rows / 2.);
	cv::Mat r = cv::getRotationMatrix2D(pt, 0, 1.0);
	cv::warpAffine(resultImage, resultImage, r, cv::Size(resultImage.cols, resultImage.rows));
	
	return resultImage;
}