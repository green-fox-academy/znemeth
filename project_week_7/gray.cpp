#include "gray.h"

void gray() 
{
	cv::Mat image = cv::imread("C:\\Users\\NEMETH\\Desktop\\project_start\\img\\4.jpg");
	cv::imshow("ORIGINAL IMAGE", image);

	cv::Mat imageGray;
	cv::cvtColor(image, imageGray, cv::COLOR_BGR2GRAY);
	cv::imshow("GRAY IMAGE", imageGray);

	cv::Mat imageBinary;
	cv::threshold(imageGray, imageBinary, 10, 255, cv::THRESH_BINARY);
	cv::imshow("BINARY IMAGE", imageBinary);

	cv::waitKey(0);

	int count = 0;

	for (int i = 0; i < imageBinary.rows; i++)
	{
		for (int j = 0; j < imageBinary.cols; j++)
		{
			int k = imageBinary.at<uchar>(i, j);
			std::cout << k << "\t";
			
			if (k == 0) {
				count++;
			}
		}
		std::cout << std::endl;
	}

	std::cin.get();

	std::cout << count << std::endl;
}