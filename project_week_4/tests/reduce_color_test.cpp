#include "pch.h"
#include "../opencv/reduce_color.cpp"

class TestReduceColor : public testing::Test
{
protected:

	const char* wrongPath = "Wrong path";
	const char* correctPath = "../../../img/speed_sign.jpg";
	cv::Mat originalImage;
	cv::Mat resultImage;
	int originalImageRowNumber;
	int originalImageColumnNumber;
	int resultImageRowNumber;
	int resultImageColumnNumber;

	virtual void SetUp()
	{
		originalImage = cv::imread("C:\\img\\highway.jpg");
	}
};


TEST_F(TestReduceColor, isEmptyImageWithWrongPath) {
	
	originalImage = cv::imread(wrongPath);
	 resultImage = reduceColor(originalImage);
	bool isEmpty = resultImage.empty();
	ASSERT_EQ(false, isEmpty);
}

TEST_F(TestReduceColor, isNotEmptyImageWithCorrectPath) {
	originalImage = cv::imread(correctPath);
	resultImage = reduceColor(originalImage);
	bool isEmpty = resultImage.empty();
	ASSERT_EQ(false, isEmpty);
}

TEST_F(TestReduceColor, isDifferentFromOriginalImage) {
	originalImage = cv::imread(correctPath);
	resultImage = reduceColor(originalImage);
	bool imagesAreSame = (sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));
	ASSERT_EQ(false, imagesAreSame);
}

TEST_F(TestReduceColor, isSameNumberOfRows) {
	originalImage = cv::imread(correctPath);
	originalImageRowNumber = originalImage.rows;
	resultImage = reduceColor(originalImage);
	resultImageRowNumber = resultImage.rows;
	bool isEqualRows = (originalImageRowNumber == resultImageRowNumber);
	ASSERT_EQ(true, isEqualRows);
}

TEST_F(TestReduceColor, isSameNumberOfColumns) {
	originalImage = cv::imread(correctPath);
	originalImageColumnNumber = originalImage.cols;
	resultImage = reduceColor(originalImage);
	resultImageColumnNumber = resultImage.cols;
	bool isEqualColumns = (originalImageColumnNumber == resultImageColumnNumber);
	ASSERT_EQ(true, isEqualColumns);
}

TEST_F(TestReduceColor, expectedRemainderValue) {
	originalImage = cv::imread(correctPath);
	resultImage = reduceColor(originalImage);
	cv::Scalar sumChannels = sum(resultImage);
	int remainderOfAllChannels = ((int)sumChannels[0] + (int)sumChannels[1] + (int)sumChannels[2]) % 127;
	ASSERT_EQ(0, remainderOfAllChannels);
}
