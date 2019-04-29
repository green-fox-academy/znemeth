#include "image_geometry.h"

cv::Mat resizerotateImage(cv::Mat image, double scale, int angle);

void geometryParser(int argc, const char** argv) {
	cv::Mat originalImage;
	cv::Mat resultImage;

	switch (argc)
	{
	case 8:
		{
		std::string additionalArgumentFirst = argv[3];
		double additionalArgumentSecond = std::stod(argv[4]);
		std::string additionalArgumentThird = argv[5];
		int additionalArguemntFourth = std::stoi(argv[6]);
		std::string additionalArgumentFifth = argv[7];

		if (((std::string)argv[3]).find("-resize") != std::string::npos &&
			((std::string)argv[5]).find("-rotate") != std::string::npos &&
			((std::string)argv[7]).find("-s") != std::string::npos) {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, additionalArgumentSecond, additionalArguemntFourth);
			cv::imwrite("../../img/resizerotated_image.jpg", resultImage);
			break;
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		}

	case 7:
		{
		std::string additionalArgumentFirst = argv[3];
		double additionalArgumentSecond = std::stod(argv[4]);
		std::string additionalArgumentThird = argv[5];
		int additionalArguemntFourth = std::stoi(argv[6]);

		if (((std::string)argv[3]).find("-resize") != std::string::npos &&
			((std::string)argv[5]).find("-rotate") != std::string::npos) {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, additionalArgumentSecond, additionalArguemntFourth);
			break;
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		}

	case 6:
		{
		std::string additionalArgumentFirst = argv[3];
		double additionalArgumentSecond = std::stod(argv[4]);
		std::string additionalArgumentThird = argv[5];

		if (((std::string)argv[3]).find("-resize") != std::string::npos &&
			((std::string)argv[5]).find("-s") != std::string::npos) {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, additionalArgumentSecond, 0);
			cv::imwrite("../../img/resizerotated_image.jpg", resultImage);
			break;
		} else if (((std::string)argv[3]).find("-rotate") != std::string::npos &&
		((std::string)argv[5]).find("-s") != std::string::npos) {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, 1, additionalArgumentSecond);
			cv::imwrite("../../img/resizerotated_image.jpg", resultImage);
			break;
		} else {
		std::cout << "Unexpected error!" << std::endl;
		std::cin.get();
		break;
		}
		}

	case 5:
		{
		std::string additionalArgumentFirst = argv[3];
		double additionalArgumentSecond = std::stod(argv[4]);

		if (((std::string)argv[3]).find("-resize") != std::string::npos) {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, additionalArgumentSecond, 0);
			break;
		} else if (((std::string)argv[3]).find("-rotate") != std::string::npos) {
			originalImage = cv::imread(argv[2]);
			resultImage = resizerotateImage(originalImage, 1, additionalArgumentSecond);
			break;
		} else {
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
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
