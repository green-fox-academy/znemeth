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

- detectEdges

`cv::Mat detectEdges(cv::Mat image)`<br/>
Input is a three-color-channel image, the output image is saveable. If the image path is not correct, the function creates a picture with an error message. The function detects the main edges on the input picture by setting two threshold parameters, which determine the distance between detected edges. In this function the ratio of threshold parameters is 3:1 constantly. The function uses three-times-three kernel matrix for image manipulation.<br/>
