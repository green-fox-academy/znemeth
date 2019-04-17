#include "gtest/gtest.h"
#include "../opencv/separate_color.cpp"

class TestSeparateColor : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestSeparateColor, fileRead) {
	cv::Mat resultImage = separateColor(originalImage);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestSeparateColor, sizeOfOriginalAndOutputFile) {
	cv::Mat resultImage = separateColor(originalImage);
	EXPECT_FALSE(resultImage.size == originalImage.size);
}

TEST_F(TestSeparateColor, rowsOfOriginalAndOutputFile) {
	cv::Mat resultImage = separateColor(originalImage);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestSeparateColor, colsOfOriginalAndOutputFile) {
	cv::Mat resultImage = separateColor(originalImage);
	EXPECT_FALSE(resultImage.cols == originalImage.cols);
}

TEST_F(TestSeparateColor, exactNumberOfCols) {
	cv::Mat resultImage = separateColor(originalImage);
	EXPECT_TRUE(resultImage.cols == originalImage.cols * 3);
}

TEST_F(TestSeparateColor, blueColorChannel) {
	cv::Mat resultImage = separateColor(originalImage);

	for (int i = 0; i < originalImage.cols; i++)
	{
		for (int j = 0; j < originalImage.rows; j++)
		{
			EXPECT_TRUE(int(resultImage.at<cv::Vec3b>(j, i)[0]) == int(originalImage.at<cv::Vec3b>(j, i)[0]));
		}
	}
}

TEST_F(TestSeparateColor, greenColorChannel) {
	cv::Mat resultImage = separateColor(originalImage);

	for (int i = 0; i < originalImage.cols; i++)
	{
		for (int j = 0; j < originalImage.rows; j++)
		{
			EXPECT_TRUE(int(resultImage.at<cv::Vec3b>(j, i + originalImage.cols)[1]) == int(originalImage.at<cv::Vec3b>(j, i)[1]));
		}
	}
}

TEST_F(TestSeparateColor, redColorChannel) {
	cv::Mat resultImage = separateColor(originalImage);

	for (int i = 0; i < originalImage.cols; i++)
	{
		for (int j = 0; j < originalImage.rows; j++)
		{
			EXPECT_TRUE(int(resultImage.at<cv::Vec3b>(j, i + originalImage.cols * 2)[2]) == int(originalImage.at<cv::Vec3b>(j, i)[2]));
		}
	}
}
