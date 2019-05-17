**MEGALOTIS OpenCV-SAPPHIRE**
======
_created by_ László Bogár, Tamás Németh, Zoltán Németh, Márton Porkoláb, Lilla Tóth

## **Project documentation**

We have been creating a program that is able to detect and modify shapes and text on images.<br/> <br/>
We use the following technologies:
* C++14
* SQLite
* OpenCV library
* Google Test<br/>

List of available features, their functions, and short descriptions:

- remove motion from video

`cv::Mat motion(cv::VideoCapture video)`<br/>
The function takes a video as input that removes all the motions from the video. It returns a grayscale image that contains only the background (static part) of the video.<br/>