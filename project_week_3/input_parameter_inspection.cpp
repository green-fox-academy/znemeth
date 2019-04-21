#include "input_parameter_inspection.h"

InputFeedback parameterNumberInspection(int inputNumbers, const char* feature)
{
	std::string featureName = feature;

	if (inputNumbers < 3) {
		return FEW_PARAMETER;
	} else if (inputNumbers > 8) {
		return TOO_MUCH_PARAMETER;
	} else if (featureName == "-reduceclr") {
		return REDUCE_COLOR;
	} else if (featureName == "-salt") {
		return SALT_EFFECT;
	} else if (featureName == "-separatecolor") {
		return SEPARATE_COLOR;
	} else if (featureName == "-edges") {
		return DETECT_EDGES;
	} else if (featureName == "-sharpen") {
		return SHARPENING;
	} else if (featureName == "-geometry") {
		return GEOMETRY;
	} else {
		return WRONG_FEATURE;
	}
}
