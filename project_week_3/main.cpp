#include "reduce_color.h"
#include "salt_effect.h"
#include "input_parameter_inspection.h"
#include "separate_color.h"
#include "detect_edges.h"
#include "img_sharpening.h"
#include "arithmetic_operations.h"

int main(int argc, const char** argv)
{
	switch (parameterNumberInspection(argc, argv[1]))
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
	case WRONG_FEATURE:
		std::cout << "There is no this kind of feature" << std::endl;
		std::cin.get();
		break;
	default:
		break;
	}

	return 0;
}
