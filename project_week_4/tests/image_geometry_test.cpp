#include "gtest/gtest.h"
#include "../opencv/image_geometry.cpp"

class TestGeometryImage : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/speed_sign.jpg");
	}
};

TEST_F(TestGeometryImage, fileRead) {
	cv::Mat resultImage = resizerotateImage(originalImage, 1, 0);
	EXPECT_FALSE(resultImage.empty());
}

TEST_F(TestGeometryImage, sizeOfOriginalAndOutputFileResize1) {
	cv::Mat resultImage = resizerotateImage(originalImage, 1, 0);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestGeometryImage, sizeOfOriginalAndOutputFileResize2) {
	cv::Mat resultImage = resizerotateImage(originalImage, 2, 0);
	EXPECT_FALSE(resultImage.size == originalImage.size);
}

TEST_F(TestGeometryImage, sizeOfOriginalAndOutputFileRotate) {
	cv::Mat resultImage = resizerotateImage(originalImage, 1, 30);
	EXPECT_TRUE(resultImage.size == originalImage.size);
}

TEST_F(TestGeometryImage, ratioOfOriginalAndOutputFileResize) {
	cv::Mat resultImage = resizerotateImage(originalImage, 2, 0);
	EXPECT_TRUE(resultImage.cols / resultImage.rows == originalImage.cols / originalImage.rows);
}

TEST_F(TestGeometryImage, ratioOfOriginalAndOutputFileRotate) {
	cv::Mat resultImage = resizerotateImage(originalImage, 1, 40);
	EXPECT_TRUE(resultImage.cols / resultImage.rows == originalImage.cols / originalImage.rows);
}
