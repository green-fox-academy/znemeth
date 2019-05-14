#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	VideoCapture cap("C:\\Users\\NEMETH\\Desktop\\greenfox\\opencv_project\\megalotis-sapphire\\img\\short.avi");
	int frame_counter = 0;

	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		cin.get();
		return -1;
	}


	while (1) {

		Mat frame;
		// Capture frame-by-frame
		frame_counter += 1;
		if (frame_counter == cap.get(CAP_PROP_FRAME_COUNT)) {
			frame_counter = 0;
			cap.set(CAP_PROP_POS_FRAMES, frame_counter);
		}


		cap >> frame;


		// If the frame is empty, break immediately
		if (frame.empty())
			break;

		// Display the resulting frame
		imshow("Frame", frame);

		// Press  ESC on keyboard to exit
		char c = (char)waitKey(25);
		if (c == 27)
			break;
	}

	// When everything done, release the video capture object
	//cap.release();

	// Closes all the frames
	//destroyAllWindows();

	return 0;
}