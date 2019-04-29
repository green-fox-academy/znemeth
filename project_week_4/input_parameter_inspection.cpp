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
	} else if (featureName == "-cartoon") {
		return CARTOON;
	} else if (featureName == "-add") {
		return ADD_IMAGE;
	} else if (featureName == "-subtract") {
		return SUBTRACT_IMAGE;
	} else if (featureName == "-multiply") {
		return MULTIPLY_IMAGE;
	} else if (featureName == "-divide") {
		return DIVIDE_IMAGE;
	} else if (featureName == "-panorama") {
		return PANORAMA;
	} else if (featureName == "-erode") {
		return ERODE;
	} else if (featureName == "-dilate") {
		return DILATE;
	} else if (featureName == "-open") {
		return CLOSING;
	} else if (featureName == "-close") {
		return OPENING;
	} else if (featureName == "-decolor") {
		return DECOLOR;
	} else if (featureName == "-wave") {
		return WAVING_EFFECT;
	} else if (featureName == "-corners") {
		return DETECT_CORNERS;
	} else {
		return WRONG_FEATURE;
	}
}
