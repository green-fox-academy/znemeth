**MEGALOTIS OpenCV-SAPPHIRE**
======
_created by_ Lilla Tóth, László Bogár, Tamás Németh, Zoltán Németh, Márton Porkoláb

## **Project documentation**

We have been creating a program that is able to detect and modify shapes and text on images.<br/> <br/>
We use the dollowing technologies:
* C++14
* MySQL
* OpenCV library
* Google Test<br/>

List of available features, their functions, and short descriptions:

- detect corners

`cv::Mat corners(cv::Mat image)`<br/>
Corners function iterates through an image, and looks for corners. First, cornerHarris() function is working on grayscale images. It computes the horizontal and vertical edges of an image, and then it performs cross correlation on the edges to highlight corners. As a result, all pixel values become less than 1 and you get a black image, however cv::normalise function helps to show the result. It divides every pixel value by the sum of absolute values of all the pixels in the image. After that the main function draws circles around the corners.  <br/>

