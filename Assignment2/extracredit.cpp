#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

void insertionSort(int w[])
{
	int temp, i, j;
	for (i = 0; i <=24; i++){
		temp = w[i];
		for (j = i - 1; j >= 0 && temp < w[j]; j--){
			w[j + 1] = w[j];
		}
		w[j + 1] = temp;
	}
}

int main()
{
	Mat src, dst;

	// Load an image
	src = imread("statue.bmp");

	
	//create a sliding window
	int w[25];

	dst = src.clone();
	for (int a = 0; a < src.rows; a++)
		for (int b = 0; b < src.cols; b++)
			dst.at<uchar>(a, b) = 0.0;

	for (int a = 1; a <= src.rows-1; a++){
		for (int b = 1; b <= src.cols-1; b++){
			
			
			w[0] = src.at<uchar>(a-2,b-2);
			w[1] = src.at<uchar>(a - 2, b - 1);
			w[2] = src.at<uchar>(a - 2, b);
			w[3] = src.at<uchar>(a - 2, b + 1);
			w[4] = src.at<uchar>(a - 2, b + 2);
			w[5] = src.at<uchar>(a - 1, b - 2);
			w[6] = src.at<uchar>(a - 1, b-1);
			w[7] = src.at<uchar>(a-1, b);
			w[8] = src.at<uchar>(a - 1, b+1);
			w[9] = src.at<uchar>(a - 1, b + 2);
			w[10] = src.at<uchar>(a, b -2);
			w[11] = src.at<uchar>(a, b- 1);
			w[12] = src.at<uchar>(a , b);
			w[13] = src.at<uchar>(a , b + 1);
			w[14] = src.at<uchar>(a , b + 2);
			w[15] = src.at<uchar>(a + 1, b - 2);
			w[16] = src.at<uchar>(a + 1, b - 1);
			w[17] = src.at<uchar>(a + 1, b);
			w[18] = src.at<uchar>(a + 1, b + 1);
			w[19] = src.at<uchar>(a + 1, b + 2);
			w[20] = src.at<uchar>(a + 2, b - 2);
			w[21] = src.at<uchar>(a + 2, b - 1);
			w[22] = src.at<uchar>(a + 2, b );
			w[23] = src.at<uchar>(a + 2, b + 1);
			w[24] = src.at<uchar>(a + 2, b + 2);
			// sort the window to find median
			insertionSort(w);
			
			// assign the median to centered element of the matrix
			dst.at<uchar>(a, b) = w[12];
		}
	}

	namedWindow("Median");
	imshow("Median", dst);


	waitKey();


	return 0;
}
