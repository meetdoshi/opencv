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

	Mat colorPlanes[] = { Mat(image.rows, image.cols, CV_8UC1),
		Mat(image.rows, image.cols, CV_8UC1), Mat(image.rows, image.cols,
		CV_8UC1) };
	split(image, colorPlanes);

	

	Mat BImage(colorPlanes[0].rows, colorPlanes[0].cols, CV_8UC1);

	Mat BImage1(colorPlanes[1].rows, colorPlanes[1].cols, CV_8UC1);

	Mat BImage2(colorPlanes[2].rows, colorPlanes[2].cols, CV_8UC1);

	int histogram[256];
	hist(BImage, histogram);
	hist(BImage1, histogram);
	hist(BImage2, histogram);

	

	Mat image2[] = { BImage, BImage1, BImage2 };
	namedWindow("Original Image");
	imshow("Original Image", image);

	
	Mat newimage = image.clone();

	merge(image2, 3, newimage);


	namedWindow("Histogram Equalized");
	imshow("Histogram Equalized", newimage);
			



	waitKey();
	return 0;
}