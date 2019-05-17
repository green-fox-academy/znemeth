#include "gtest/gtest.h"
#include "../opencv/remove_motion.cpp"

class TestRemoveMotion : public testing::Test
{
protected:

	cv::VideoCapture originalVideo;

	virtual void SetUp()
	{
		cv::VideoCapture originalVideo("../../../img/360p.avi");
	}
};

TEST_F(TestRemoveMotion, outputFileRead) {
	cv::Mat resultImage = motion(originalVideo);
	EXPECT_FALSE(resultImage.empty());
}
