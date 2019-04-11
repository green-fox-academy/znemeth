#include "separate_color.h"

cv::Mat separateColorWithoutSave(std::string imgPath);
cv::Mat separateColorWithSave(std::string imgPath);

void separateColor(const char** argv)
{
	cv::Mat result;
	std::string additionalArgumentFirst = argv[2];
	bool saving = (additionalArgumentFirst == "-s");

	std::cout << argv[1] << std::endl;

	switch (saving)
	{
	case true:
		result = separateColorWithSave(argv[3]);
		break;
	case false:
		result = separateColorWithoutSave(additionalArgumentFirst);
		break;
	default:
		break;
	}
	
	cv::namedWindow("separate_color", cv::WINDOW_AUTOSIZE);
	cv::imshow("separate_color", result);
	cv::waitKey(0);
}


cv::Mat separateColorWithoutSave(std::string imgPath) {

	cv::Mat img = cv::imread(imgPath);
	cv::Mat blue_img;
	cv::Mat green_img;
	cv::Mat red_img;
	cv::Mat images;
	cv::Mat g = cv::Mat::zeros(cv::Size(img.cols, img.rows), CV_8UC1);
	

	if (img.empty()) {
		std::cout << "Could not open or find the image!\n" << std::endl;
		cv::Mat result(250, 250, CV_8UC3, cv::Scalar(0, 0, 0));
		return result;
	}
	else {
		cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
		cv::imshow("image", img);

		std::vector<cv::Mat> RGBchannels(3);
		cv::split(img, RGBchannels);

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
	}
	return images;
}


cv::Mat separateColorWithSave(std::string imgPath)
{
	cv::Mat result = separateColorWithoutSave(imgPath);
	cv::imwrite("../../img/colored_image.jpg", result);
	return result;
}