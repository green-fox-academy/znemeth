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

- panorama

`cv::Mat panorama(std::vector<cv::Mat> imagesVector)`<br/>
This function is intended to create a panorama by stitching images together using OpenCV library. It is looking for common areas or shared common patch of pixels in the input images and saves the resultant stitched image.
<br/>
