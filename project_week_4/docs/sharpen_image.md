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

- sharpen image

`cv::Mat sharpen(cv::Mat image);` <br/>
GaussianBlur and addWeighted functions are needed together to get a sharper image. Those functions are substruct the smoother image from the original one. To get sharper image, in addWeighted increase alpha as well as reduce beta. The sum of them has to be 1.<br/>
