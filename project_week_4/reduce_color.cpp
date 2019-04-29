#include "reduce_color.h"

void reduceColorParser(int argc, const char** argv)
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
			resultImage = reduceColor(originalImage);
			cv::imwrite("../../img/reduced_color_image.jpg", resultImage);
			break;
		case 3:
			resultImage = reduceColor(originalImage);
			break;
		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false: 
		originalImage = cv::imread(argv[2]);
		resultImage = reduceColor(originalImage);	
		break;	
	default: 
		break;
	}
	
	cv::namedWindow("Reduced Color Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Reduced Color Image", resultImage);
	cv::waitKey(0);
	cv::destroyWindow("Reduced Color Image");
}

cv::Mat reduceColor(cv::Mat originalImage)
{
	cv::Mat resultImage;
	if (originalImage.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		
		return errorImage;
	} else {
		resultImage = originalImage / 127;
		resultImage *= 127;

		return resultImage;
	}
}
