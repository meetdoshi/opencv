#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>

using namespace cv;

int main(int argc, char** argv)
{
	

	// Load the source image
	Mat image = imread("statue.bmp");

	// Create a destination Mat object
	Mat dst;

	Mat  dst1, dst2;
	Mat src(3, 3, CV_32F);
	Point anchor;
	double delta;
	int ddepth;

	anchor = Point(-1, -1);
	delta = 0;
	ddepth = -1;

	




	src.at<double>(0, 0) = 1 / 16;
	src.at<double>(0, 1) = 2 / 16;
	src.at<double>(0, 2) = 1 / 16;
	src.at<double>(1, 0) = 2 / 16;
	src.at<double>(1, 1) = 4 / 16;
	src.at<double>(1, 2) = 2 / 16;
	src.at<double>(2, 0) = 1 / 16;
	src.at<double>(2, 1) = 2 / 16;
	src.at<double>(2, 2) = 1 / 16;


	filter2D(image, dst1, ddepth, src, anchor, delta, BORDER_DEFAULT);

	GaussianBlur(image, dst2, Size(3, 3), 1.0);

	
	imshow("result2", dst2);

	waitKey(0);
	return 0;


}