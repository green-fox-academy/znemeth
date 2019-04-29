#include "gtest/gtest.h"
#include "../opencv/image_morphology.cpp"

class TestErodeMorphology : public testing::Test
{
protected:

	cv::Mat originalImage;

	virtual void SetUp()
	{
		originalImage = cv::imread("../../../img/number.jpg");
	}
};

TEST_F(TestErodeMorphology, wrongImagePath) {
	cv::Mat wrongImage = cv::imread("wrong_image_path");
	cv::Mat resultImage = erodeImage(wrongImage);

	std::string errorMessage = "Could not open or find the image!";
	cv::Mat errorImage(250, 250, CV_8UC1);
	cv::putText(errorImage, errorMessage, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	bool imagesAreEqual = (cv::sum(errorImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_TRUE(imagesAreEqual);
}

TEST_F(TestErodeMorphology, resultIsDifferent) {
	cv::Mat resultImage = erodeImage(originalImage);
	bool imagesAreEqual = (cv::sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_FALSE(imagesAreEqual);
}


TEST_F(TestErodeMorphology, sizeAreTheSame) {
	cv::Mat resultImage = erodeImage(originalImage);
	bool sameSize = ((resultImage.rows == originalImage.rows) && (resultImage.cols == originalImage.cols));

	EXPECT_TRUE(sameSize);
}

class TestDilateMorphology : public TestErodeMorphology
{
};

TEST_F(TestDilateMorphology, wrongImagePath) {
	cv::Mat wrongImage = cv::imread("wrong_image_path");
	cv::Mat resultImage = dilateImage(wrongImage);

	std::string errorMessage = "Could not open or find the image!";
	cv::Mat errorImage(250, 250, CV_8UC1);
	cv::putText(errorImage, errorMessage, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	bool imagesAreEqual = (cv::sum(errorImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_TRUE(imagesAreEqual);
}
TEST_F(TestDilateMorphology, resultIsDifferent) {
	cv::Mat resultImage = dilateImage(originalImage);
	bool imagesAreEqual = (cv::sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_FALSE(imagesAreEqual);
}

TEST_F(TestDilateMorphology, sizeAreTheSame) {
	cv::Mat resultImage = dilateImage(originalImage);
	bool sameSize = ((resultImage.rows == originalImage.rows) && (resultImage.cols == originalImage.cols));

	EXPECT_TRUE(sameSize);
}

class TestClosingMorphology : public TestErodeMorphology
{
};

TEST_F(TestClosingMorphology, wrongImagePath) {
	cv::Mat wrongImage = cv::imread("wrong_image_path");
	cv::Mat resultImage = closingImage(wrongImage);

	std::string errorMessage = "Could not open or find the image!";
	cv::Mat errorImage(250, 250, CV_8UC1);
	cv::putText(errorImage, errorMessage, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	bool imagesAreEqual = (cv::sum(errorImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_TRUE(imagesAreEqual);
}
TEST_F(TestClosingMorphology, resultIsDifferent) {
	cv::Mat resultImage = closingImage(originalImage);
	bool imagesAreEqual = (cv::sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_FALSE(imagesAreEqual);
}

TEST_F(TestClosingMorphology, sizeAreTheSame) {
	cv::Mat resultImage = closingImage(originalImage);
	bool sameSize = ((resultImage.rows == originalImage.rows) && (resultImage.cols == originalImage.cols));

	EXPECT_TRUE(sameSize);
}


class TestOpeningMorphology : public TestErodeMorphology
{
};

TEST_F(TestOpeningMorphology, wrongImagePath) {
	cv::Mat wrongImage = cv::imread("wrong_image_path");
	cv::Mat resultImage = openingImage(wrongImage);

	std::string errorMessage = "Could not open or find the image!";
	cv::Mat errorImage(250, 250, CV_8UC1);
	cv::putText(errorImage, errorMessage, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);
	bool imagesAreEqual = (cv::sum(errorImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_TRUE(imagesAreEqual);
}
TEST_F(TestOpeningMorphology, resultIsDifferent) {
	cv::Mat resultImage = openingImage(originalImage);
	bool imagesAreEqual = (cv::sum(originalImage != resultImage) == cv::Scalar(0, 0, 0));

	EXPECT_FALSE(imagesAreEqual);
}

TEST_F(TestOpeningMorphology, sizeAreTheSame) {
	cv::Mat resultImage = openingImage(originalImage);
	bool sameSize = ((resultImage.rows == originalImage.rows) && (resultImage.cols == originalImage.cols));

	EXPECT_TRUE(sameSize);
}
