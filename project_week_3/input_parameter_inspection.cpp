#include "input_parameter_inspection.h"

InputFeedback parameterNumberInspection(int inputNumbers, const char* feature)
{
	std::string featureName = feature;

	if (inputNumbers < 3) {
		return FEW_PARAMETER;
	} else if (inputNumbers > 5) {
		return TOO_MUCH_PARAMETER;
	} else if (featureName == "-reduceclr") {
		return REDUCE_COLOR;
	} else if (featureName == "-salt") {
		return SALT_EFFECT;
	} else if (featureName == "-separatecolor") {
		return SEPARATE_COLOR;
	} else if (featureName == "-edges") {
		return DETECT_EDGES;
<<<<<<< HEAD
	}
	else if (featureName == "-sharpen" && inputNumbers >= 3 && inputNumbers <= 4) {
		return SHARPENING;
	}
	else if (featureName == "-add" && inputNumbers >= 4 && inputNumbers <= 5) {
		return ADD_IMAGE;
	}
	else if (featureName == "-subtract" && inputNumbers >= 4 && inputNumbers <= 5) {
		return SUBTRACT_IMAGE;
	}
	else if (featureName == "-multiply" && inputNumbers >= 4 && inputNumbers <= 5) {
		return MULTIPLY_IMAGE;
	}
	else if (featureName == "-divide" && inputNumbers >= 4 && inputNumbers <= 5) {
		return DIVIDE_IMAGE;
	}
	else {
=======
	} else if (featureName == "-sharpen") {
		return SHARPENING;
	} else {
>>>>>>> development
		return WRONG_FEATURE;
	}
}
