#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <iostream>
using namespace cv;
using namespace std;


int main(){

	int mask[3][3] = { { 1, 2, 1 }, { 2, 4, 2 }, { 1, 2, 1 } };
	

	Mat Image = imread("lena_std.tif");

	namedWindow("orginal image");
	imshow("orginal image", Image);



	Mat hsvimage;
	cvtColor(Image, hsvimage, COLOR_BGR2HSV);	/*namedWindow("zz");
	imshow("zz", hsvimage);*/

	Mat image[] = { Mat(hsvimage.rows, hsvimage.cols, CV_8UC1),
		Mat(hsvimage.rows, hsvimage.cols, CV_8UC1), Mat(hsvimage.rows, hsvimage.cols,
		CV_8UC1) };
	split(hsvimage, image);

	/*namedWindow("split h");
	imshow("split h", image[0]);

	namedWindow("split s");
	imshow("split s", image[1]);

	namedWindow("split v");
	imshow("split v", image[2]);*/


	Mat Bimage(image[2].rows, image[2].cols, CV_8UC1, Scalar(0, 0, 0));

	for (int m = 0; m <= 14; m++){

	for (int i = 1; i < image[2].rows - 1; i++){
		for (int j = 1; j < image[2].cols - 1; j++){
			Bimage.at<uchar>(i, j) = (image[2].at<uchar>(i, j) * 4 + image[2].at<uchar>(i - 1, j - 1) * 1 + image[2].at<uchar>(i - 1, j) * 2 + image[2].at<uchar>(i - 1, j + 1) * 1
				+ image[2].at<uchar>(i, j - 1) * mask[1][0] + image[2].at<uchar>(i, j + 1) * 2 + image[2].at<uchar>(i + 1, j - 1) * 1 + image[2].at<uchar>(i + 1, j) * 2 + image[2].at<uchar>(i + 1, j + 1) * 1) / 16;

		}
	}




	
	for (int i = 0; i < 1; i++)
	{
		for (int j = 1; j < image[2].cols - 1; j++){
			Bimage.at<uchar>(i, j) = (image[2].at<uchar>(i, j) * mask[1][1] + image[2].at<uchar>(i, j - 1) *
				mask[1][0] + image[2].at<uchar>(i, j + 1) * mask[1][2] + image[2].at<uchar>(i + 1, j - 1) *
				mask[2][0] + image[2].at<uchar>(i + 1, j) * mask[2][1] + image[2].at<uchar>(i + 1, j + 1) * mask[2][2]) / 16;
		}

		
	}

	for (int i = 1; i < image[2].rows - 1; i++)

	{
		for (int j = 0; j <= 0; j++){
			Bimage.at<uchar>(i, j) = (image[2].at<uchar>(i, j) * mask[1][1] + image[2].at<uchar>(i - 1, j) *
				mask[0][1] + image[2].at<uchar>(i - 1, j + 1) * mask[0][2] + image[2].at<uchar>(i, j + 1) *
				mask[1][2] + image[2].at<uchar>(i + 1, j) * mask[2][1] + image[2].at<uchar>(i + 1, j + 1) * mask[2][2]) / 16;
		}

		
	}


	for (int i = image[2].rows; i < image[2].rows; i++)
	{
		for (int j = 1; j < image[2].cols - 1; j++){
			Bimage.at<uchar>(i, j) = (image[2].at<uchar>(i, j) * mask[1][1] + image[2].at<uchar>(i - 1, j - 1) *
				mask[0][0] + image[2].at<uchar>(i - 1, j) * mask[0][1] + image[2].at<uchar>(i - 1, j + 1) *
				mask[0][2] + image[2].at<uchar>(i, j - 1) * mask[1][0] + image[2].at<uchar>(i, j + 1) * mask[1][2]);
		}
	}



	for (int i = 1; i < image[2].rows - 1; i++){
		int	j = image[2].cols - 1;
		Bimage.at<uchar>(i, j) = (image[2].at<uchar>(i, j) * 4 + image[2].at<uchar>(i - 1, j - 1) * 1 + image[2].at<uchar>(i - 1, j) * 2 + image[2].at<uchar>(i, j - 1) * mask[1][0] + image[2].at<uchar>(i + 1, j) * 2) / 16;


	}

	Bimage.at<uchar>(0, 0) = (image[2].at<uchar>(0, 0) * mask[1][1] + image[2].at<uchar>(0, 1) *
		mask[1][2] + image[2].at<uchar>(1, 0) * mask[2][1] + image[2].at<uchar>(1, 1) *
		mask[2][2]) / 16;
	Bimage.at<uchar>(0, image[2].cols - 1) = (image[2].at<uchar>(0, image[2].cols - 1) * mask[1][1] + image[2].at<uchar>(0, image[2].cols - 2) *
		mask[1][0] + image[2].at<uchar>(1, image[2].cols - 2) * mask[2][0] + image[2].at<uchar>(1, image[2].cols - 2) *
		mask[2][1]) / 16;
	Bimage.at<uchar>(image[2].rows - 1, 0) = (image[2].at<uchar>(image[2].rows - 1, 0) * mask[1][1] + image[2].at<uchar>(image[2].rows - 2, 0) *
		mask[0][1] + image[2].at<uchar>(image[2].rows - 2, 1) * mask[0][2] + image[2].at<uchar>(image[2].rows - 1, 1) *
		mask[1][2]) / 16;
	Bimage.at<uchar>(image[2].rows - 1, image[2].cols - 1) = (image[2].at<uchar>(image[2].rows - 1, image[2].cols - 1) * mask[1][1] + image[2].at<uchar>(image[2].rows - 2, image[2].cols - 1) *
		mask[0][1] + image[2].at<uchar>(image[2].rows - 2, image[2].cols - 2) * mask[0][0] + image[2].at<uchar>(image[2].rows - 1, image[2].cols - 2) *
		mask[1][0]) / 16;

	Bimage.copyTo(image[2]);
}

	
	/*imshow("gaussian image", Bimage);*/

	
	Mat newimage = Image.clone();

	merge(image, 3, newimage);
	/*imshow("Blur hsv image", newimage);*/

	Mat image1;
	cvtColor(newimage, image1, COLOR_HSV2BGR);
	imshow("Blur intensity image", image1);

	waitKey(-1);
	return 0;
}