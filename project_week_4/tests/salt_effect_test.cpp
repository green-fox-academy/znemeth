#include "gtest/gtest.h"
#include "../opencv/salt_effect.cpp"

class TestSaltEffect : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestSaltEffect, goodImagePath) {
	cv::Mat resultImage = saltEffect(originalImage);

	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestSaltEffect, wrongImagePath) {
	cv::Mat wrongImage = cv::imread("wrong_image_path");
	cv::Mat resultImage = saltEffect(wrongImage);

	std::string errorMessage = "Could not open or find the image!";
	cv::Mat errorImage(250, 250, CV_8UC1);
	cv::putText(errorImage, errorMessage, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	bool imagesAreEqual = (cv::sum(errorImage != resultImage) == cv::Scalar(0, 0, 0));
	
	EXPECT_TRUE(imagesAreEqual);
}

TEST_F(TestSaltEffect, resultIsDifferent) {
	cv::Mat resultImage = saltEffect(originalImage);
	bool imagesAreEqual = (cv::sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_FALSE(imagesAreEqual);
}

TEST_F(TestSaltEffect, pixelValueIncrease) {
	cv::Mat result = saltEffect(originalImage);
	cv::Scalar originalColors = cv::sum(originalImage);
	cv::Scalar resultColors = cv::sum(result);
	
	bool resultBlueIsBigger = resultColors[0] > originalColors[0];
	bool resultGreenIsBigger = resultColors[1] > originalColors[1];
	bool resultRedIsBigger = resultColors[2] > originalColors[2];

	EXPECT_TRUE(resultBlueIsBigger);
	EXPECT_TRUE(resultGreenIsBigger);
	EXPECT_TRUE(resultRedIsBigger);
}

TEST_F(TestSaltEffect, whitePixelsOnBlackImage)
{
	cv::Mat blackImage(20, 20, CV_8UC3, cv::Scalar(0, 0, 0));
	cv::Mat resultImage = saltEffect(blackImage);
	int numberOfColoredPixels = 0;
	cv::Vec<uchar, 3> whitePixel = { 255, 255, 255 };
	cv::Vec<uchar, 3> blackPixel = { 0, 0, 0 };
	for (int y = 0; y < resultImage.rows; y++)
	{
		for (int x = 0; x < resultImage.cols; x++)
		{
			if (resultImage.at<cv::Vec3b>(y, x) != whitePixel && resultImage.at<cv::Vec3b>(y, x) != blackPixel) {
				numberOfColoredPixels++;
			}
		}
	}
	EXPECT_TRUE(numberOfColoredPixels == 0);
}
