#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include "opencv2/bgsegm.hpp"

int main() {

	auto bgSub = cv::bgsegm::createBackgroundSubtractorCNT();

	cv::VideoCapture cap("C:\\Users\\NEMETH\\Desktop\\greenfox\\opencv_project\\megalotis-sapphire\\img\\360p.avi");
	
	int frame_counter = 0;
	cv::Mat frame;
	cv::Mat fgMaskMOG2;
	cv::Ptr<cv::BackgroundSubtractor> pMOG2;
	pMOG2 = cv::createBackgroundSubtractorMOG2();
	int fps = cap.get(cv::CAP_PROP_FPS);

	if (!cap.isOpened()) {
		std::cout << "Error opening video stream or file" << std::endl;
		std::cin.get();
		return -1;
	}

	while (1)
	{
		frame_counter += 1;
	
		if (frame_counter == cap.get(cv::CAP_PROP_FRAME_COUNT)) {
			frame_counter = 0;
			cap.set(cv::CAP_PROP_POS_FRAMES, frame_counter);
		}

		cap >> frame;

		if (frame.empty()) {
			break;
		}

		cv::namedWindow("Original video", cv::WINDOW_AUTOSIZE);
		cv::imshow("Original video", frame);

		pMOG2->apply(frame, fgMaskMOG2);
		cv::namedWindow("MOG2 Method", cv::WINDOW_AUTOSIZE);
		cv::imshow("MOG2 Method", fgMaskMOG2);

		cv::Mat gray;
		cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

		cv::Mat fgMask;
		bgSub->apply(gray, fgMask);
		cv::namedWindow("FG Mask Method", cv::WINDOW_AUTOSIZE);
		cv::imshow("FG Mask Method", fgMask);

		cv::Mat bckgr;
		bgSub->getBackgroundImage(bckgr);
		cv::namedWindow("Background", cv::WINDOW_AUTOSIZE);
		cv::imshow("Background", bckgr);

		char exit = (char)cv::waitKey(25);
		if (exit == 27) {
			break;
		}
	}

	cap.release();
	cv::destroyAllWindows();

	return 0;
}
