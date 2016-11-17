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

void histDisplay(int histogram[], const char* name)
{
	int hist[256];
	for (int i = 0; i <= 255; i++)
	{
		hist[i] = histogram[i];
	}
	
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / 256);

	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(255, 255, 255));

	
	int max = hist[0];
	for (int i = 1; i <= 255; i++){
		if (max < hist[i]){
			max = hist[i];
		}
	}

	

	for (int i = 0; i <= 255; i++){
		hist[i] = ((double)hist[i] / max)*histImage.rows;
	}


	
	for (int i = 0; i <= 255; i++)
	{
		line(histImage, Point(bin_w*(i), hist_h),
			Point(bin_w*(i), hist_h - hist[i]),
			Scalar(0, 0, 0), 1, 8, 0);
	}

	
	namedWindow(name, WINDOW_AUTOSIZE);
	imshow(name, histImage);
}


int main()
{
	
	
	Mat image = imread("guide.tif", IMREAD_GRAYSCALE);

	int histogram[256];
	hist(image, histogram);
	
	int size = image.rows * image.cols;
	float alpha = 255.0 / size;

	float Prbl[256];
	for (int i = 0; i <= 255; i++)
	{
		Prbl[i] = (double)histogram[i] / size;
	}

	int cdf[256];
	cumhist(histogram, cdf);

	int S[256];
	for (int i = 0; i <= 255; i++)
	{
		S[i] = cvRound((double)cdf[i] * alpha);
	}


	float PsSk[256];
	for (int i = 0; i <= 255; i++)
	{
		PsSk[i] = 0;
	}

	for (int i = 0; i <= 255; i++)
	{
		PsSk[S[i]] += Prbl[i];
	}

	int final[256];
	for (int i = 0; i <= 255; i++)
	{
		final[i] = cvRound(PsSk[i] * 255);
	}


	Mat new_image = image.clone();

	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			new_image.at<uchar>(y, x) = saturate_cast<uchar>(S[image.at<uchar>(y, x)]);
		}
	}

	namedWindow("Original Image");
	imshow("Original Image", image);
	
	histDisplay(histogram, "Original Histogram");



	namedWindow("Equilized Image");
	imshow("Equilized Image", new_image);

	histDisplay(final, "Equilized Histogram");

	Mat str_image = new_image.clone();

	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			str_image.at<uchar>(y, x) = saturate_cast<uchar>(S[new_image.at<uchar>(y, x)]);
		}
	}

	namedWindow("Equilized Streched Image");
	imshow("Equilized Streched Image", str_image);

	histDisplay(final, "Equilized Streched Histogram");

	Mat cv_image = str_image.clone();

	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			cv_image.at<uchar>(y, x) = saturate_cast<uchar>(S[str_image.at<uchar>(y, x)]);
		}
	}

	namedWindow("Equilized Streched Cv Image");
	imshow("Equilized Streched Cv Image", cv_image);

	histDisplay(final, "Equilized Streched Cv Histogram");

	waitKey();
	return 0;
}