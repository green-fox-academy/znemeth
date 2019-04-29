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

- wavingEffect

`cv::Mat waveEffect(cv::Mat image)`<br/>
Input is a three-color-channel image, the output image is saveable. If the image path is not correct, the function creates a picture with an error message. The function reorganizes the values of pixels of the original image with the help of two support matrices, and returns a wave effecting image. In this function only the support matrix of rows gets new values. By changing the value of reorganizing algoritm, the amplitude of waves is variable. <br/>

