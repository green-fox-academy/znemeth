#include "digit_reading.h"

int digitReading(cv::Mat image);
void digitNumber();

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

	digitNumber();
	
	cv::FileStorage fs;
	fs.open("DATABASE.xml", cv::FileStorage::READ);
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
	
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == ratio) {
			std::cout << i << std::endl;
		}
	}

	fs.release();

	std::cin.get();
	int resultValue = 10;

	return resultValue;

}

void digitNumber(){

	cv::Mat image0 = cv::imread("../../img/0.jpg");
	cv::Mat image1 = cv::imread("../../img/1.jpg");
	cv::Mat image2 = cv::imread("../../img/2.jpg");
	cv::Mat image3 = cv::imread("../../img/3.jpg");
	cv::Mat image4 = cv::imread("../../img/4.jpg");
	cv::Mat image5 = cv::imread("../../img/5.jpg");
	cv::Mat image6 = cv::imread("../../img/6.jpg");
	cv::Mat image7 = cv::imread("../../img/7.jpg");
	cv::Mat image8 = cv::imread("../../img/8.jpg");
	cv::Mat image9 = cv::imread("../../img/9.jpg");

	/*
	images.push_back(image0);
	images.push_back(image1); 
	images.push_back(image2);
	images.push_back(image3);
	images.push_back(image4);
	images.push_back(image5);
	images.push_back(image6);
	images.push_back(image7);
	images.push_back(image8);
	images.push_back(image9);
	*/

	cv::Mat grayImage0;
	cv::Mat grayImage1;
	cv::Mat grayImage2;
	cv::Mat grayImage3;
	cv::Mat grayImage4;
	cv::Mat grayImage5;
	cv::Mat grayImage6;
	cv::Mat grayImage7;
	cv::Mat grayImage8;
	cv::Mat grayImage9;

	cv::cvtColor(image0, grayImage0, cv::COLOR_BGR2GRAY);
	cv::cvtColor(image1, grayImage1, cv::COLOR_BGR2GRAY);
	cv::cvtColor(image2, grayImage2, cv::COLOR_BGR2GRAY);
	cv::cvtColor(image3, grayImage3, cv::COLOR_BGR2GRAY);
	cv::cvtColor(image4, grayImage4, cv::COLOR_BGR2GRAY);
	cv::cvtColor(image5, grayImage5, cv::COLOR_BGR2GRAY);
	cv::cvtColor(image6, grayImage6, cv::COLOR_BGR2GRAY);
	cv::cvtColor(image7, grayImage7, cv::COLOR_BGR2GRAY);
	cv::cvtColor(image8, grayImage8, cv::COLOR_BGR2GRAY);
	cv::cvtColor(image9, grayImage9, cv::COLOR_BGR2GRAY);

	int countBlack0 = 0;
	int countWhite0 = 0;

	int countBlack1 = 0;
	int countWhite1 = 0;

	int countBlack2 = 0;
	int countWhite2 = 0;

	int countBlack3 = 0;
	int countWhite3 = 0;

	int countBlack4 = 0;
	int countWhite4 = 0;

	int countBlack5 = 0;
	int countWhite5 = 0;

	int countBlack6 = 0;
	int countWhite6 = 0;

	int countBlack7 = 0;
	int countWhite7 = 0;

	int countBlack8 = 0;
	int countWhite8 = 0;

	int countBlack9 = 0;
	int countWhite9 = 0;

	for (int i = 0; i < image0.cols; i++)
	{
		for (int j = 0; j < image0.rows; j++)
		{
			int k = image0.at<uchar>(j, i);
			if (k == 0)
			{
				countBlack0++;
			}
			else if (k == 255)
			{
				countWhite0++;
			}
		}
	}
	
	for (int i = 0; i < image1.cols; i++)
	{
		for (int j = 0; j < image1.rows; j++)
		{
			int k = image1.at<uchar>(j, i);
			if (k == 0)
			{
				countBlack1++;
			}
			else if (k == 255)
			{
				countWhite1++;
			}
		}
	}

	for (int i = 0; i < image2.cols; i++)
	{
		for (int j = 0; j < image2.rows; j++)
		{
			int k = image2.at<uchar>(j, i);
			if (k == 0)
			{
				countBlack2++;
			}
			else if (k == 255)
			{
				countWhite2++;
			}
		}
	}

	for (int i = 0; i < image3.cols; i++)
	{
		for (int j = 0; j < image3.rows; j++)
		{
			int k = image3.at<uchar>(j, i);
			if (k == 0)
			{
				countBlack3++;
			}
			else if (k == 255)
			{
				countWhite3++;
			}
		}
	}

	for (int i = 0; i < image4.cols; i++)
	{
		for (int j = 0; j < image4.rows; j++)
		{
			int k = image4.at<uchar>(j, i);
			if (k == 0)
			{
				countBlack4++;
			}
			else if (k == 255)
			{
				countWhite4++;
			}
		}
	}

	for (int i = 0; i < image5.cols; i++)
	{
		for (int j = 0; j < image5.rows; j++)
		{
			int k = image5.at<uchar>(j, i);
			if (k == 0)
			{
				countBlack5++;
			}
			else if (k == 255)
			{
				countWhite5++;
			}
		}
	}

	for (int i = 0; i < image6.cols; i++)
	{
		for (int j = 0; j < image6.rows; j++)
		{
			int k = image6.at<uchar>(j, i);
			if (k == 0)
			{
				countBlack6++;
			}
			else if (k == 255)
			{
				countWhite6++;
			}
		}
	}

	for (int i = 0; i < image7.cols; i++)
	{
		for (int j = 0; j < image7.rows; j++)
		{
			int k = image7.at<uchar>(j, i);
			if (k == 0)
			{
				countBlack7++;
			}
			else if (k == 255)
			{
				countWhite7++;
			}
		}
	}

	for (int i = 0; i < image8.cols; i++)
	{
		for (int j = 0; j < image8.rows; j++)
		{
			int k = image8.at<uchar>(j, i);
			if (k == 0)
			{
				countBlack8++;
			}
			else if (k == 255)
			{
				countWhite8++;
			}
		}
	}

	for (int i = 0; i < image9.cols; i++)
	{
		for (int j = 0; j < image9.rows; j++)
		{
			int k = image9.at<uchar>(j, i);
			if (k == 0)
			{
				countBlack9++;
			}
			else if (k == 255)
			{
				countWhite9++;
			}
		}
	}

	float ratio0 = (float)countBlack0 / (float)countWhite0;
	float ratio1 = (float)countBlack1 / (float)countWhite1;
	float ratio2 = (float)countBlack2 / (float)countWhite2;
	float ratio3 = (float)countBlack3 / (float)countWhite3;
	float ratio4 = (float)countBlack4 / (float)countWhite4;
	float ratio5 = (float)countBlack5 / (float)countWhite5;
	float ratio6 = (float)countBlack6 / (float)countWhite6;
	float ratio7 = (float)countBlack7 / (float)countWhite7;
	float ratio8 = (float)countBlack8 / (float)countWhite8;
	float ratio9 = (float)countBlack9 / (float)countWhite9;

	cv::FileStorage fs("DATABASE.xml", cv::FileStorage::WRITE);
	fs << "Digit_BlackWhitePixelRatio";
	fs << "{" << "Zero" << ratio0;
	fs << "One" << ratio1;
	fs << "Two" << ratio2;
	fs << "Three" << ratio3;
	fs << "Four" << ratio4;
	fs << "Five" << ratio5;
	fs << "Six" << ratio6;
	fs << "Seven" << ratio7;
	fs << "Eight" << ratio8;
	fs << "Nine" << ratio9 << "}";

	fs.release();
}
