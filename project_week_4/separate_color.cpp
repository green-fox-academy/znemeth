#include "separate_color.h"

cv::Mat separateColor(cv::Mat image);

void separateParser(int argc, const char** argv)
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
			resultImage = separateColor(originalImage);
			break;
		
		case 4:
			originalImage = cv::imread(argv[3]);
			resultImage = separateColor(originalImage);
			cv::imwrite("../../img/colored_image.jpg", resultImage);
			break;

		default:
			std::cout << "Unexpected error!" << std::endl;
			std::cin.get();
			break;
		}
		break;
		
	case false:
		originalImage = cv::imread(argv[2]);
		resultImage = separateColor(originalImage);
		break;
	
	default:
		break;
	}
	
	cv::namedWindow("Separate Color", cv::WINDOW_AUTOSIZE);
	cv::imshow("Separate Color", resultImage);
	cv::waitKey(0);
}

cv::Mat separateColor(cv::Mat image)
{
	cv::Mat blue_img;
	cv::Mat green_img;
	cv::Mat red_img;
	cv::Mat images;
	cv::Mat g = cv::Mat::zeros(cv::Size(image.cols, image.rows), CV_8UC1);
	
	if (image.empty()) {
		std::string error = "Could not open or find the image!";
		cv::Mat errorImage(250, 250, CV_8UC1);
		cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
		return errorImage;
	}

	std::vector<cv::Mat> RGBchannels(3);
	cv::split(image, RGBchannels);

	{
		std::vector<cv::Mat> channels;
		channels.push_back(RGBchannels[0]);
		channels.push_back(g);
		channels.push_back(g);
		merge(channels, blue_img);
	}

	{
		std::vector<cv::Mat> channels;
		channels.push_back(g);
		channels.push_back(RGBchannels[1]);
		channels.push_back(g);
		merge(channels, green_img);
	}

	{
		std::vector<cv::Mat> channels;
		channels.push_back(g);
		channels.push_back(g);
		channels.push_back(RGBchannels[2]);
		merge(channels, red_img);
	}
		
	cv::hconcat(blue_img, green_img, images);
	cv::hconcat(images, red_img, images);
	
	return images;
}
