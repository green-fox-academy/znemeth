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

List of available functions, their definitions, and short descriptions:

- add images

 `cv::Mat addImage(cv::Mat image, cv::Mat image2)`<br/>
The function takes 2 color images as input and adds them. This is known as blending as well.<br/>
- substract images

 `cv::Mat subtractImage(cv::Mat image, cv::Mat image2)`<br/>
The function takes 2 color images as input and substracts them.<br/>
- multiply images

`cv::Mat multiplyImage(cv::Mat image, cv::Mat image2)`<br/>
The function takes 2 color images as input and multiplies them.<br/>
- divide images

`cv::Mat divideImage(cv::Mat image, cv::Mat image2)`<br/>
The function takes 2 color images as input and divides them.<br/>