#include "image_geometry.h"

cv::Mat resizerotateImage(cv::Mat image, double scale, int angle);

void geometryParser(int argc, const char** argv) {
	cv::Mat originalImage;
	cv::Mat resultImage;

	// argv[0] - *.exe
	// argv[1] - -geometry
	// argv[2] - ../../img/speed_sign.jpg

	std::string additionalArgumentFirst = argv[3];			// feature
	double additionalArgumentSecond = std::stod(argv[4]);	// double || int evaluated as double
	std::string additionalArgumentThird = argv[5];			// -s || feature
	int additionalArguemntFourth = std::stoi(argv[6]);		// int
	std::string additionalArgumentFifth = argv[7];			// -s

	/*
	SYNTAX EXAMPLE:
	*.exe -geometry ../../img/speed_sign.jpg +
	-resize 1.9
	-resize 1.9 -s
	-rotate 40
	-rotate 40 -s
	-resize 1.9 -rotate 40
	-resize 1.9 -rotate 40 -s
	*/

	switch (argc)
	{
	case 8:
		if (argv[3] == "-resize" && argv[5] == "-rotate" && argv[7] == "-s") {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, additionalArgumentSecond, additionalArguemntFourth);
			cv::imwrite("../../img/resizerotated_image.jpg", resultImage);
			break;
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}

	case 7:
		if (argv[3] == "-resize" && argv[5] == "-rotate") {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, additionalArgumentSecond, additionalArguemntFourth);
			break;
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}

	case 6:
		if (argv[3] == "-resize" && argv[5] == "-s") {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, additionalArgumentSecond, 0);
			cv::imwrite("../../img/resizerotated_image.jpg", resultImage);
		} else if (argv[3] == "-rotate" && argv[5] == "-s") {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, 1, additionalArguemntFourth);
			cv::imwrite("../../img/resizerotated_image.jpg", resultImage);
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}

	case 5:
		if (argv[3] == "-resize") {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, additionalArgumentSecond, 0);
		} else if (argv[3] == "-rotate") {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, 1, additionalArguemntFourth);
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}

	default:
		std::cout << "Unexpected error!" << std::endl;
		std::cin.get();
		break;
	}
	
	cv::namedWindow("Geometry Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Geometry Image", resultImage);
	cv::waitKey(0);
}

cv::Mat resizerotateImage(cv::Mat image, double scale, int angle) {
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		return errorImage;
	}
	cv::Mat resultImage;
	cv::resize(image, resultImage, cv::Size(), scale, scale);

	cv::Point2f pt(resultImage.cols / 2., resultImage.rows / 2.);
	cv::Mat r = cv::getRotationMatrix2D(pt, angle, 1.0);
	cv::warpAffine(resultImage, resultImage, r, cv::Size(resultImage.cols, resultImage.rows));
	
	return resultImage;
}