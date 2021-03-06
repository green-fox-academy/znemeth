#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <vector> 

#ifndef H_IMAGE_GEOMETRY
#define H_IMAGE_GEOMETRY

void geometryParser(int argc, const char** argv);
cv::Mat resizerotateImage(cv::Mat image, double scale, int angle);

#endif H_IMAGE_GEOMETRY
