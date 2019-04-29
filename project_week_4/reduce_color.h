#ifndef H_REDUCE_COLOR
#define H_REDUCE_COLOR

#include <string>
#include <vector> 
#include <iostream> 
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>

void reduceColorParser(int argc, const char** argv);

cv::Mat reduceColor(cv::Mat originalImage);

#endif
