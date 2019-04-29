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

- erode image

`cv::Mat erodeImage(cv::Mat image)`<br/>
Increase the area of black or darker shapes and also decrease the number of white pixels on the image.<br/>

-  dilate image

`cv::Mat dilateImage(cv::Mat image)`<br/>
Increase the area of white or brighter shapes and also decrease the number of darker pixels on the image.<br/>

- opening image 

`cv::Mat openingImage(cv::Mat image)`<br/>
Find small white areas on the image and change the color of them into the color of closed pixels.<br/>

- closing image

`cv::Mat closingImage(cv::Mat image)`<br/>
Find small black areas on the image and change the color of them into the color of closed pixels.<br/>
