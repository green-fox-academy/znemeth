#include "pch.h"
#include "gtest/gtest.h"
#include "../opencv/decolor.cpp"

class TestDecolor : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestDecolor, readFileTrue)
{
	cv::Mat resultImage = decolorImage(originalImage);
	EXPECT_TRUE(!resultImage.empty());
}

TEST_F(TestDecolor, wrongImagePath)
{
	std::string error = "Could not open or find the image!";
	cv::Mat errorImage = cv::Mat(250, 250, CV_8UC1);
	cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	originalImage = cv::imread("../../../img/wrong_image_path.jpg");
	cv::Mat resultImage = decolorImage(originalImage);
	bool correctErrorImage = sum(errorImage) == sum(resultImage);

	EXPECT_TRUE(correctErrorImage);
}

TEST_F(TestDecolor, colNumberTestTrue)
{
	cv::Mat resultImage = decolorImage(originalImage);
	bool isSameCols = originalImage.cols == resultImage.cols;
	EXPECT_TRUE(isSameCols);
}

TEST_F(TestDecolor, rowNumberTestTrue)
{
	cv::Mat resultImage = decolorImage(originalImage);
	bool isSameRows = originalImage.rows == resultImage.rows;
	EXPECT_TRUE(isSameRows);
}

TEST_F(TestDecolor, sameImageTrue)
{
	cv::Mat resultImage = decolorImage(originalImage);
	bool  isSameImage = sum(resultImage) == sum(resultImage);
	EXPECT_TRUE(isSameImage);
}

TEST_F(TestDecolor, sameImageFalse)
{
	cv::Mat resultImage = decolorImage(originalImage);
	bool  isSameImage = sum(originalImage) == sum(resultImage);
	EXPECT_FALSE(isSameImage);
}

TEST_F(TestDecolor, grayScaleImageFalse)
{
	cv::Mat resultImage = decolorImage(originalImage);
	cv::Mat grayScaleImage;
	cv::cvtColor(originalImage, grayScaleImage, cv::COLOR_BGR2GRAY);
	bool  isGrayScaleImage = sum(grayScaleImage) == sum(resultImage);
	EXPECT_FALSE(isGrayScaleImage);
}
