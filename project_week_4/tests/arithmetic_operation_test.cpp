#include "gtest/gtest.h"
#include "../opencv/arithmetic_operations.cpp"

class TestAddImage : public testing::Test
{
protected:

	cv::Mat originalImage;
	cv::Mat originalImage2;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/new_york.jpg");
		originalImage2 = cv::imread("../../../img/speaker.jpg");
	}
};

class TestSubtractImage : public TestAddImage 
{
};

class TestMultiplyImage : public TestSubtractImage 
{
};

class TestDivideImage : public TestMultiplyImage 
{
};

TEST_F(TestAddImage, fileReadAdd) {
	cv::Mat resultImage = addImage(originalImage, originalImage2);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestSubtractImage, fileReadSubtract) {
	cv::Mat resultImage = subtractImage(originalImage, originalImage2);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestMultiplyImage, fileReadMultiply) {
	cv::Mat resultImage = multiplyImage(originalImage, originalImage2);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestDivideImage, fileReadDivide) {
	cv::Mat resultImage = divideImage(originalImage, originalImage2);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestAddImage, sizeOfOriginalAndOutputFileAdd) {
	cv::Mat resultImage = addImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestSubtractImage, sizeOfOriginalAndOutputFileSubtract) {
	cv::Mat resultImage = subtractImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestMultiplyImage, sizeOfOriginalAndOutputFileMultiply) {
	cv::Mat resultImage = multiplyImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestDivideImage, sizeOfOriginalAndOutputFileDivide) {
	cv::Mat resultImage = divideImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestAddImage, rowsOfOriginalAndOutputFileAdd) {
	cv::Mat resultImage = addImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestSubtractImage, rowsOfOriginalAndOutputFileSubtract) {
	cv::Mat resultImage = subtractImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestMultiplyImage, rowsOfOriginalAndOutputFileMultiply) {
	cv::Mat resultImage = multiplyImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestDivideImage, rowsOfOriginalAndOutputFileDivide) {
	cv::Mat resultImage = divideImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestAddImage, colsOfOriginalAndOutputFileAdd) {
	cv::Mat resultImage = addImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.cols == originalImage.cols);
}

TEST_F(TestSubtractImage, colsOfOriginalAndOutputFileSubtract) {
	cv::Mat resultImage = subtractImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.cols == originalImage.cols);
}

TEST_F(TestMultiplyImage, colsOfOriginalAndOutputFileMultiply) {
	cv::Mat resultImage = multiplyImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.cols == originalImage.cols);
}

TEST_F(TestDivideImage, colsOfOriginalAndOutputFileDivide) {
	cv::Mat resultImage = divideImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.cols == originalImage.cols);
}
