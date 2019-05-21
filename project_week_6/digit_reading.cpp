#include "digit_reading.h"

int digitReading(cv::Mat image);

void digitParser(const char** argv)
{
	cv::Mat originalImage = cv::imread(argv[2]);;
	int resultValue = digitReading(originalImage);
}

int digitReading(cv::Mat image) {
	if (image.empty()) {
		std::cout << "Could not open or find the image!" << std::endl;
		std::cin.get();
	}
	
	cv::Mat grayImage;
	cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

	int countBlack = 0;
	int countWhite = 0;

	for (int i = 0; i < image.cols; i++)
	{
		for (int j = 0; j < image.rows; j++)
		{
			int k = image.at<uchar>(j, i);
			if (k == 0)
			{
				countBlack++;
			}
			else if (k == 255)
			{
				countWhite++;
			}
		}
	}

	float ratio = (float)countBlack / (float)countWhite;
	
	cv::FileStorage fs("DATA.xml", cv::FileStorage::WRITE);	
	fs << "Mapping";
	fs << "{" << "Zero" << ratio;
	fs << "One" << 1;
	fs << "Two" << 2;
	fs << "Three" << 3;
	fs << "Four" << 4;
	fs << "Five" << 5;
	fs << "Six" << 6;
	fs << "Seven" << 7;
	fs << "Eight" << 8;
	fs << "Nine" << 9 << "}";
	
	fs.release();


	

	std::cout << ratio << ", " << countWhite << ", " << countBlack << "\n";



	std::cout << image.size << ", " <<image.cols << ", " << image.rows << std::endl;
	std::cin.get();
	int resultValue = 10;

	return resultValue;

}