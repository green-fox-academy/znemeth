#include "pch.h"
#include "gtest/gtest.h"
#include "../opencv/waving_effect.cpp"

class TestWavingEffect : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestWavingEffect, readFileFalse)
{
	cv::Mat resultImage = waveEffect(originalImage);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestWavingEffect, readFileEqual)
{
	cv::Mat resultImage = waveEffect(originalImage);
	EXPECT_EQ(0, resultImage.empty());
}

TEST_F(TestWavingEffect, readFileNotEqual)
{
	cv::Mat resultImage = waveEffect(originalImage);
	EXPECT_NE(1, resultImage.empty());
}

TEST_F(TestWavingEffect, readFileTrue)
{
	cv::Mat resultImage = waveEffect(originalImage);
	EXPECT_TRUE(!resultImage.empty());
}

TEST_F(TestWavingEffect, wrongImagePath)
{
	std::string error = "Could not open or find the image!";
	cv::Mat errorImage = cv::Mat(250, 250, CV_8UC1);
	cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	originalImage = cv::imread("../../../img/wrong_image_path.jpg");
	cv::Mat resultImage = waveEffect(originalImage);
	bool correctErrorImage = sum(errorImage) == sum(resultImage);

	EXPECT_TRUE(correctErrorImage);
}

TEST_F(TestWavingEffect, colNumberTestTrue)
{
	cv::Mat resultImage = waveEffect(originalImage);
	bool isSameCols = originalImage.cols == resultImage.cols;
	EXPECT_TRUE(isSameCols);
}

TEST_F(TestWavingEffect, rowNumberTestTrue)
{
	cv::Mat resultImage = waveEffect(originalImage);
	bool isSameRows = originalImage.rows == resultImage.rows;
	EXPECT_TRUE(isSameRows);
}

TEST_F(TestWavingEffect, sameImageTrue)
{
	cv::Mat resultImage = waveEffect(originalImage);
	bool  isSameImage = sum(resultImage) == sum(resultImage);
	EXPECT_TRUE(isSameImage);
}

TEST_F(TestWavingEffect, sameImageFalse)
{
	cv::Mat resultImage = waveEffect(originalImage);
	bool  isSameImage = sum(originalImage) == sum(resultImage);
	EXPECT_FALSE(isSameImage);
}
