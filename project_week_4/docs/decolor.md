**MEGALOTIS OpenCV-SAPPHIRE**
======
_created by_ Lilla Tóth, László Bogár, Tamás Németh, Zoltán Németh, Márton Porkoláb

## **Project documentation**

We have been creating a program that is able to detect and modify shapes and text on images.<br/> <br/>
We use the following technologies:
* C++14
* MySQL
* OpenCV library
* Google Test<br/>

List of available features, their functions, and short descriptions:

- decolor

`cv::Mat decolorImage(cv::Mat image)`<br/>
Input is a three-color-channel image, the output image is saveable. If the image path is not correct, the function creates a picture with an error message. The function create a one-channel grayscale image, but it is not equal with cv::cvtColor(image, grayscaleImage, cv::COLOR_BGR2GRAY) function.<br/>
