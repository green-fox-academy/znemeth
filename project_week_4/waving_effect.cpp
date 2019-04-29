#include "waving_effect.h"
#include <math.h>

cv::Mat waveEffect(cv::Mat image);

void waveParser(int argc, const char** argv)
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
			resultImage = waveEffect(originalImage);
			break;
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = waveEffect(originalImage);
			imwrite("../../img/waving_effect_image.jpg", resultImage);
			break;
		default:
			std::cout << "Unexpected error" << std::endl;
			std::cin.get();
			break;
		}
		break;
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = waveEffect(originalImage);
		break;
	default:
		break;
	}
	cv::namedWindow("Remapped image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Remapped image", resultImage);
	cv::waitKey(0);
}
cv::Mat waveEffect(cv::Mat image)
{
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage = cv::Mat(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return errorImage;
	}
	cv::Mat resultImage, matX, matY;
	double yo;
	resultImage.create(image.size(), image.type());
	matX.create(image.size(), CV_32FC1);
	matY.create(image.size(), CV_32FC1);
	for (int j = 0; j < image.rows; j++) {
		for (int i = 0; i < image.cols; i++) {
			yo = (8.0 * sin(2.0 * 3.14 * i / 64.0));
			matX.at<float>(j, i) = i;
			matY.at<float>(j, i) = j + yo;
		}
	}
	cv::remap(image, resultImage, matX, matY, cv::INTER_LINEAR, cv::BORDER_DEFAULT, cv::Scalar(0, 0, 0));

	return resultImage;
}
