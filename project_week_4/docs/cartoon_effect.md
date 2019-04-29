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

- cartoon effect

`cv::Mat cartoonEffect(cv::Mat image)`<br/>
First of all it blurs the original image a bit, than detects the edges, and it saves the inverted stronger edges into  a mask image. After that it makes it more blurrier, and reduce the avaliable pixel's colors and puts the mask with the edges on that. <br/>
