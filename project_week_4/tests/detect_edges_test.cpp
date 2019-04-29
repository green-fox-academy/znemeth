#include "pch.h"
#include "gtest/gtest.h"
#include "../opencv/detect_edges.cpp"

class TestDetectEdges : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestDetectEdges, countBlackPixels)
{

	cv::Mat resultImage = detectEdges(originalImage);
	cv::Scalar numberOfBlackPixels = sum(resultImage) / 255;
	int blackPixelCounter = 0;
	for (int i = 0; i < resultImage.rows; ++i) {
		for (int j = 0; j < resultImage.cols; ++j) {
			if (resultImage.at<uchar>(i, j) == 255) {
				blackPixelCounter++;
			}
		}
	}

	EXPECT_EQ(numberOfBlackPixels[0], blackPixelCounter);
}

TEST_F(TestDetectEdges, notGrayscaleImage)
{
	cv::Mat resultImage = detectEdges(originalImage);
	cv::Mat grayScaleImage;
	cv::cvtColor(originalImage, grayScaleImage, cv::COLOR_BGR2GRAY);
	EXPECT_NE(sum(resultImage), sum(grayScaleImage));
}

TEST_F(TestDetectEdges, readFileTrue)
{
	cv::Mat resultImage = detectEdges(originalImage);
	EXPECT_TRUE(!resultImage.empty());
}

TEST_F(TestDetectEdges, wrongImagePath)
{
	std::string error = "Could not open or find the image!";
	cv::Mat errorImage = cv::Mat(250, 250, CV_8UC1);
	cv::putText(errorImage, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	originalImage = cv::imread("../../../img/wrong_image_path.jpg");
	cv::Mat resultImage = detectEdges(originalImage);
	bool correctErrorImage = sum(errorImage) == sum(resultImage);

	EXPECT_TRUE(correctErrorImage);
}

TEST_F(TestDetectEdges, colNumberTestTrue)
{
	cv::Mat resultImage = detectEdges(originalImage);
	bool isSameCols = originalImage.cols == resultImage.cols;
	EXPECT_TRUE(isSameCols);
}

TEST_F(TestDetectEdges, rowNumberTestTrue)
{
	cv::Mat resultImage = detectEdges(originalImage);
	bool isSameRows = originalImage.rows == resultImage.rows;
	EXPECT_TRUE(isSameRows);
}

TEST_F(TestDetectEdges, pixelNumberTestTrue)
{
	cv::Mat resultImage = detectEdges(originalImage);
	int numberOfWhitePixels = 0;
	int numberOfBlackPixels = 0;
	int numberOfAllPixel = 0;
	for (int y = 0; y < resultImage.rows; y++) 
	{
		for (int x = 0; x < resultImage.cols; x++)
		{
			if (resultImage.at<uchar>(y, x) == 255) {
				numberOfWhitePixels++;
			} else if (resultImage.at<uchar>(y, x) == 0) {
				numberOfBlackPixels++;
			} else {
				numberOfAllPixel++;
			}
			numberOfAllPixel++;
		}
	}
	bool isSamePixel = numberOfAllPixel == (numberOfWhitePixels + numberOfBlackPixels);
	EXPECT_TRUE(isSamePixel);
}
