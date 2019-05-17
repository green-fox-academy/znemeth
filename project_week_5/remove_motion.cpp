#include "remove_motion.h"

cv::Mat motion(cv::VideoCapture video);

void motionParser(const char** argv)
{	
	cv::VideoCapture originalVideo(argv[2]);
	cv::Mat resultImage;
	
	switch (originalVideo.isOpened())
	{
	case true:
		resultImage = motion(originalVideo);
		break;
	case false:
		std::cout << "Could not open or find the video!" << std::endl;
		std::cin.get();
		break;
	default:
		break;
	}

	cv::namedWindow("Remove Motion", cv::WINDOW_AUTOSIZE);
	cv::imshow("Remove Motion", resultImage);
	cv::waitKey(0);
}

cv::Mat motion(cv::VideoCapture video)
{
	if (!video.isOpened()) {
		std::string error = "Could not open or find the video!";
		cv::Mat result(250, 250, CV_8UC1);
		cv::putText(result, error, cv::Point(10, 125), cv::FONT_HERSHEY_SIMPLEX, 0.4, cv::Scalar(0, 0, 0), 1);

		return result;
	}

	auto bgSub = cv::bgsegm::createBackgroundSubtractorCNT();

	int frame_counter = 0;
	cv::Mat frame;
	cv::Mat resultImage;
	cv::Mat fgMask;
	cv::Mat fgMaskMOG2;
	cv::Mat gray;
	cv::Ptr<cv::BackgroundSubtractor> pMOG2;
	pMOG2 = cv::createBackgroundSubtractorMOG2();
	int fps = video.get(cv::CAP_PROP_FPS);

	while (1)
	{
		frame_counter += 1;

		if (frame_counter == video.get(cv::CAP_PROP_FRAME_COUNT)) {
			frame_counter = 0;
			video.set(cv::CAP_PROP_POS_FRAMES, frame_counter);
		}

		video >> frame;

		if (frame.empty()) {
			break;
		}

		cv::namedWindow("Original video", cv::WINDOW_AUTOSIZE);
		cv::imshow("Original video", frame);

		pMOG2->apply(frame, fgMaskMOG2);
		cv::namedWindow("MOG2 Method", cv::WINDOW_AUTOSIZE);
		cv::imshow("MOG2 Method", fgMaskMOG2);

		cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
		bgSub->apply(gray, fgMask);
		cv::namedWindow("FG Mask Method", cv::WINDOW_AUTOSIZE);
		cv::imshow("FG Mask Method", fgMask);

		bgSub->getBackgroundImage(resultImage);
		cv::namedWindow("Background", cv::WINDOW_AUTOSIZE);
		cv::imshow("Background", resultImage);

		char exit = (char)cv::waitKey(25);
		if (exit == 27) {
			break;
		}
	}

	video.release();
	cv::destroyAllWindows();

	return resultImage;
}
