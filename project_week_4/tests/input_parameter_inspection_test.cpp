#include "pch.h"
#include "../opencv/input_parameter_inspection.cpp"

TEST(TestInputParameterInspection, withFewParameter) {
	int result = parameterNumberInspection(2, "Does not matter what you write in command line");
	ASSERT_EQ(FEW_PARAMETER, result);
}

TEST(TestInputParameterInspection, withTooMuchParameter) {
	int result = parameterNumberInspection(9, "Does not matter what you write in command line");
	ASSERT_EQ(TOO_MUCH_PARAMETER, result);
}

TEST(TestInputParameterInspection, reduceColorWithThreeParameter) {
	int result = parameterNumberInspection(3, "-reduceclr");
	ASSERT_EQ(REDUCE_COLOR, result);
}

TEST(TestInputParameterInspection, reduceColorWithFourParameter) {
	int result = parameterNumberInspection(4, "-reduceclr");
	ASSERT_EQ(REDUCE_COLOR, result);
}

TEST(TestInputParameterInspection, functionCallWithWrongFeature) {
	int result = parameterNumberInspection(3, "-wrongfeature");
	ASSERT_EQ(WRONG_FEATURE, result);
}
