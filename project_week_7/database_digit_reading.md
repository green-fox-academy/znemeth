**MEGALOTIS OpenCV-SAPPHIRE**
======
_created by_ László Bogár, Tamás Németh, Zoltán Németh, Márton Porkoláb, Lilla Tóth

## **Project documentation**

We have been creating a program that is able to detect and modify shapes and text on images.<br/> <br/>
We use the following technologies:
* C++14
* SQLite
* OpenCV library
* Google Test<br/>

List of available features, their functions, and short descriptions:

- database for digit reading

`void databaseDigitReading(std::string imagePath, int digitValue)`<br/>
This function is called at the end of digit reading feature. It creates a database if does not exist and stores the image path as a primary key and the number that can be seen in the image. <br/>
