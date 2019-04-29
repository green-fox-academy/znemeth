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

- parameterNumberInspection

`InputFeedback parameterNumberInspection(int inputNumbers, const char* feature)`<br/>
This function handles whether the user gave an adequate number of arguments to command line or not. If yes, it also handles whether the feature argument is existed or not.