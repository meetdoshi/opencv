#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstring>
#include <opencv/highgui.h>



using namespace cv;

void hist(Mat image, int histogram[])
{


	for (int i = 0; i <= 255; i++)
	{
		histogram[i] = 0;
	}


	for (int y = 0; y < image.rows; y++)
		for (int x = 0; x < image.cols; x++)
			histogram[(int)image.at<uchar>(y, x)]++;



}

void cumhist(int histogram[], int cumhistogram[])
{
	cumhistogram[0] = histogram[0];

	for (int i = 1; i <= 255; i++)
	{
		cumhistogram[i] = histogram[i] + cumhistogram[i - 1];
	}
}




int main()
{


	Mat image = imread("lena_std.tif");


	Mat hsvimage;
	cvtColor(image, hsvimage, COLOR_BGR2HSV);


	Mat colorPlanes[] = { Mat(hsvimage.rows, hsvimage.cols, CV_8UC1),
		Mat(hsvimage.rows, hsvimage.cols, CV_8UC1), Mat(hsvimage.rows, hsvimage.cols,
		CV_8UC1) };
	split(hsvimage, colorPlanes);



	

	Mat BImage2(colorPlanes[2].rows, colorPlanes[2].cols, CV_8UC1);

	int histogram[256];
	
	hist(BImage2, histogram);


	BImage2.copyTo(colorPlanes[2]);
	namedWindow("Original Image");
	imshow("Original Image", image);


	Mat newimage = image.clone();

	merge(colorPlanes, 3, newimage);
	Mat image1;
	cvtColor(newimage, image1, COLOR_HSV2BGR);

	namedWindow("Histogram Equalized");
	imshow("Histogram Equalized", image1);


	waitKey();
	return 0;
}