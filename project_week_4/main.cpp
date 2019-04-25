#include "reduce_color.h"
#include "salt_effect.h"
#include "input_parameter_inspection.h"
#include "separate_color.h"
#include "detect_edges.h"
#include "img_sharpening.h"
#include "image_geometry.h"
#include "arithmetic_operations.h"
#include "panorama.h"
#include "cartoon_effect.h"
#include "image_morphology.h"
#include "decolor.h"
#include "waving_effect.h"
#include "detect_corners.h"
#include "selection_sort.h"

int main(int argc, const char** argv)
{
/*	switch (parameterNumberInspection(argc, argv[1]))
	{
	case FEW_PARAMETER:
		std::cout << "More input parameter is necessary" << std::endl;
		std::cin.get();
		break;
	case TOO_MUCH_PARAMETER:
		std::cout << "Too much input parameter is given" << std::endl;
		std::cin.get();
		break;
	case REDUCE_COLOR:
		reduceColorParser(argc, argv);
		break;
	case SALT_EFFECT:
		saltParser(argc, argv);
		break;
	case SEPARATE_COLOR:
		separateParser(argc, argv);
		break;
	case DETECT_EDGES:
		detectEdgesParser(argc, argv);
		break;
	case SHARPENING:
		sharpenParser(argc, argv);
		break;
	case GEOMETRY:
		geometryParser(argc, argv);
		break;
	case ADD_IMAGE:
		addParser(argc, argv);
		break;
	case SUBTRACT_IMAGE:
		subtractParser(argc, argv);
		break;
	case MULTIPLY_IMAGE:
		multiplyParser(argc, argv);
		break;
	case DIVIDE_IMAGE:
		divideParser(argc, argv);
		break;
	case PANORAMA:
		panoramaParser(argc, argv);
		break;
	case CARTOON:
		cartoonParser(argc, argv);
		break;
	case ERODE:
		erodeParser(argc, argv);
		break;
	case DILATE:
		dilateParser(argc, argv);
		break;
	case OPENING:
		closingParser(argc, argv);
		break;
	case CLOSING:
		openingParser(argc, argv);
		break;
	case DECOLOR:
		decolorParser(argc, argv);
		break;
	case WAVING_EFFECT:
		waveParser(argc, argv);
		break;
	case DETECT_CORNERS:
		cornersParser(argc, argv);
		break;
	case WRONG_FEATURE:
		std::cout << "There is no this kind of feature" << std::endl;
		std::cin.get();
		break;
	default:
		break;
	}
*/
	std::vector<int> list = {5, 8, 45, 51, 100}; // , 1000, 10000, 63456, 456400, 9999999};
	selectionSort(list, 0);
	return 0;
}
