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

- image geometry

`cv::Mat resizerotateImage(cv::Mat image);`<br/>
The color image as input is resized, or rotated, or resized and rotated at the same time by user-defined values. Due to the complexity of the parser, the command line argument sytaxis:
use the following technologies:
* -geometry ../../img/speed_sign.jpg -resize 1.8 -rotate 35 -s
* -geometry ../../img/speed_sign.jpg -resize 1.8 -rotate 35
* -geometry ../../img/speed_sign.jpg -resize 1.8 -s
* -geometry ../../img/speed_sign.jpg -rotate 35 -s
* -geometry ../../img/speed_sign.jpg -resize 1.8
* -geometry ../../img/speed_sign.jpg -rotate 35<br/>