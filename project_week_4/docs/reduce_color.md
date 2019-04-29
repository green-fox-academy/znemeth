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

- reduceColor

`cv::Mat reduceColor(cv::Mat originalImage)`<br/>
Input and output are three-color-channel image. The function reduces the number of different colors of the input image. The maximum value of the reduced color number is 27. <br/>
