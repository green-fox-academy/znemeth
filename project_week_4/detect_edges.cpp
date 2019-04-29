#include "detect_edges.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <iostream> 

cv::Mat detectEdges(cv::Mat image);

void detectEdgesParser(int argc, const char** argv)
{
	cv::Mat originalImage;
	cv::Mat resultImage;
	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");

	switch (saving)
	{	
	case true:
		switch(argc) 
		{
		case 3:
			resultImage = detectEdges(originalImage);
			break;
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = detectEdges(originalImage);
			imwrite("../../img/detect_edge_image.jpg", resultImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = detectEdges(originalImage);
		break;
	default:
		break;
	}

	cv::namedWindow("Canny image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Canny image", resultImage);
	cv::waitKey(0);
}
	
cv::Mat detectEdges(cv::Mat image)
{
	cv::Mat resultImage;
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage = cv::Mat(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}
	cv::Canny(image, resultImage, 90, 270, 3);

	return resultImage;
}
