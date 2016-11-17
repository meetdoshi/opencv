#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <opencv\cv.h>
#include <opencv\cv.hpp>

using namespace cv;

int main1(int argc, char **argv)
{
	Mat src1 = imread("guide.tif", IMREAD_GRAYSCALE);

	Mat threshold = imread("guide.tif");
	Mat src;
	cvtColor(threshold, src1, CV_RGB2GRAY);

	Mat img_bw = src1 > 256;

	imwrite("image_bw.jpg", img_bw);

	return 0;
}