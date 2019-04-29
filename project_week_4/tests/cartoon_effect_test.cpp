#include "gtest/gtest.h"
#include "../opencv/cartoon_effect.cpp"

class TestCartoonEffect : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestCartoonEffect, wrongImagePath) {
	cv::Mat wrongImage = cv::imread("wrong_image_path");
	cv::Mat resultImage = cartoonEffect(wrongImage);

	std::string errorMessage = "Could not open or find the image!";
	cv::Mat errorImage(250, 250, CV_8UC1);
	cv::putText(errorImage, errorMessage, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	bool imagesAreEqual = (cv::sum(errorImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_TRUE(imagesAreEqual);
}

TEST_F(TestCartoonEffect, resultIsDifferent) {
	cv::Mat resultImage = cartoonEffect(originalImage);
	bool imagesAreEqual = (cv::sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_FALSE(imagesAreEqual);
}

TEST_F(TestCartoonEffect, moreBlackPixelOnOutput) {
	cv::Mat resultImage = cartoonEffect(originalImage);

	int blackOnOriginal = 0;
	int blackOnResult = 0;
	cv::Vec<uchar, 3> blackPixel = { 0, 0, 0 };
	for (int i = 0; i < originalImage.rows; i++) {
		for (int j = 0; j < originalImage.cols;j++) {
			if (originalImage.at<cv::Vec3b>(i, j) == blackPixel) {
				blackOnOriginal++;
			}
			if (resultImage.at<cv::Vec3b>(i, j) == blackPixel) {
				blackOnResult++;
			}
		}
	}

	EXPECT_TRUE(blackOnOriginal < blackOnResult);
}

TEST_F(TestCartoonEffect, expectedRemainderValue) {
	cv::Mat resultImage = cartoonEffect(originalImage);
	cv::Vec<uchar, 3> blackPixel = { 0, 0, 0 };
	cv::Scalar sumChannels = sum(resultImage != blackPixel);
	int remainderOfAllChannels = ((int)sumChannels[0] + (int)sumChannels[1] + (int)sumChannels[2]) % 34;
	
	EXPECT_EQ(0, remainderOfAllChannels);
}
