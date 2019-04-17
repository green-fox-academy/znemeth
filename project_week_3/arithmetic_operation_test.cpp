#include "gtest/gtest.h"
#include "../opencv/arithmetic_operations.cpp"

class TestArithmeticOperation : public testing::Test
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

TEST_F(TestArithmeticOperation, fileReadAdd) {
	cv::Mat resultImage = addImage(originalImage, originalImage2);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestArithmeticOperation, fileReadSubtract) {
	cv::Mat resultImage = subtractImage(originalImage, originalImage2);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestArithmeticOperation, fileReadMultiply) {
	cv::Mat resultImage = multiplyImage(originalImage, originalImage2);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestArithmeticOperation, fileReadDivide) {
	cv::Mat resultImage = divideImage(originalImage, originalImage2);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestArithmeticOperation, sizeOfOriginalAndOutputFileAdd) {
	cv::Mat resultImage = addImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestArithmeticOperation, sizeOfOriginalAndOutputFileSubtract) {
	cv::Mat resultImage = subtractImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestArithmeticOperation, sizeOfOriginalAndOutputFileMultiply) {
	cv::Mat resultImage = multiplyImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestArithmeticOperation, sizeOfOriginalAndOutputFileDivide) {
	cv::Mat resultImage = divideImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestArithmeticOperation, rowsOfOriginalAndOutputFileAdd) {
	cv::Mat resultImage = addImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestArithmeticOperation, rowsOfOriginalAndOutputFileSubtract) {
	cv::Mat resultImage = subtractImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestArithmeticOperation, rowsOfOriginalAndOutputFileMultiply) {
	cv::Mat resultImage = multiplyImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestArithmeticOperation, rowsOfOriginalAndOutputFileDivide) {
	cv::Mat resultImage = divideImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.rows == originalImage.rows);
}

TEST_F(TestArithmeticOperation, colsOfOriginalAndOutputFileAdd) {
	cv::Mat resultImage = addImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.cols == originalImage.cols);
}

TEST_F(TestArithmeticOperation, colsOfOriginalAndOutputFileSubtract) {
	cv::Mat resultImage = subtractImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.cols == originalImage.cols);
}

TEST_F(TestArithmeticOperation, colsOfOriginalAndOutputFileMultiply) {
	cv::Mat resultImage = multiplyImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.cols == originalImage.cols);
}

TEST_F(TestArithmeticOperation, colsOfOriginalAndOutputFileDivide) {
	cv::Mat resultImage = divideImage(originalImage, originalImage2);
	EXPECT_TRUE(resultImage.cols == originalImage.cols);
}
