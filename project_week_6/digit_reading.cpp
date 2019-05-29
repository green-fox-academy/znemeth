#include "digit_reading.h"
#include "database_digit_reading.h"

int digitReading(cv::Mat image);
void digitNumber();

void digitParser(const char** argv)
{
	cv::Mat originalImage = cv::imread(argv[2]);
	int resultValue;
	
	switch (originalImage.empty())
	{
	case false:
		resultValue = digitReading(originalImage);
		std::cout << resultValue << std::endl;
		databaseDigitReading(argv[2], resultValue);
		std::cin.get();
		break;
	case true:
		std::cout << "Could not open or find the image!" << std::endl;
		std::cin.get();
		break;
	default:
		std::cout << "Unexpected error" << std::endl;
		std::cin.get();
		break;
	}
}

int digitReading(cv::Mat image) 
{
	if (image.empty()) {
		std::cout << "Could not open or find the image!" << std::endl;
		std::cin.get();
	}

	cv::Mat colortemp;
	cv::cvtColor(image, colortemp, cv::COLOR_BGR2GRAY);
	cv::Mat bintemp;
	cv::threshold(colortemp, bintemp, 100, 255, cv::THRESH_BINARY);

	int countBlack = 0;
	int countWhite = 0;

	for (int i = 0; i < bintemp.cols; i++)
	{
		for (int j = 0; j < bintemp.rows; j++)
		{
			int k = bintemp.at<uchar>(j, i);
			
			if (k == 0) {
				countBlack++;
			} else if (k == 255) {
				countWhite++;
			}
		}
	}

	float ratio = ((float)countWhite / (float)countBlack);
	digitNumber();

	cv::FileStorage fs;
	fs.open("IMAGE_and_NUMBER.xml", cv::FileStorage::READ);
	cv::FileNode n = fs["Digit_BlackWhitePixelRatio"];
	n = fs["Digit_BlackWhitePixelRatio"];
	
	std::vector<float> numbers;
	numbers.push_back((float)(n["Zero"]));
	numbers.push_back((float)(n["One"]));
	numbers.push_back((float)(n["Two"]));
	numbers.push_back((float)(n["Three"]));
	numbers.push_back((float)(n["Four"]));
	numbers.push_back((float)(n["Five"]));
	numbers.push_back((float)(n["Six"]));
	numbers.push_back((float)(n["Seven"]));
	numbers.push_back((float)(n["Eight"]));
	numbers.push_back((float)(n["Nine"]));
	
	int resultNumber = 0;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == ratio) {
			resultNumber = i;
		}
	}

	fs.release();
	
	return resultNumber;
}

void digitNumber()
{
	std::vector<cv::Mat> imageVector(10);
	std::vector<cv::Mat> imageVectorGray(10);
	std::vector<float> ratio(10);
	int countBlack = 0;
	int countWhite = 0;
	cv::Mat temp;
	cv::Mat colortemp;
	cv::Mat bintemp;
	
	for (int m = 0; m < 10; m++)
	{
		countBlack = 0;
		countWhite = 0;

		std::string path = "../../img/" + std::to_string(m) + ".jpg";
		imageVector[m] = cv::imread(path);

		if (imageVector[m].empty()) {
			std::cout << "Empty image" << std::endl;
		}
		
		colortemp = imageVector[m];
		cv::cvtColor(colortemp, temp, cv::COLOR_BGR2GRAY);
		cv::threshold(temp, bintemp, 100, 255, cv::THRESH_BINARY);
		
		imageVectorGray[m] = bintemp;
		
		for (int i = 0; i < imageVectorGray[m].cols; i++)
		{
			for (int j = 0; j < imageVectorGray[m].rows; j++)
			{
				
				int k = imageVectorGray[m].at<uchar>(j, i);

				if (k == 0){
					countBlack++;
				} else if (k == 255) {
					countWhite++;
				}
			}
		}
		
		ratio[m] = ((float)countWhite / (float)countBlack);
	}
	
	cv::FileStorage fs("IMAGE_and_NUMBER.xml", cv::FileStorage::WRITE);
	fs << "Digit_BlackWhitePixelRatio";
	fs << "{" << "Zero" << ratio[0];
	fs << "One" << ratio[1];
	fs << "Two" << ratio[2];
	fs << "Three" << ratio[3];
	fs << "Four" << ratio[4];
	fs << "Five" << ratio[5];
	fs << "Six" << ratio[6];
	fs << "Seven" << ratio[7];
	fs << "Eight" << ratio[8];
	fs << "Nine" << ratio[9] << "}";

	fs.release();
}
