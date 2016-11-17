#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <iostream>
using namespace cv;
using namespace std;


int main(){

	int mask[3][3] = { { 1, 2, 1 }, { 2, 4, 2 }, { 1, 2, 1 } };
	// loading the image
	Mat image = imread("lena_std.tif");

	namedWindow("orginal image");
	imshow("orginal image", image);

	Mat colorPlanes[] = { Mat(image.rows, image.cols, CV_8UC1),
		Mat(image.rows, image.cols, CV_8UC1), Mat(image.rows, image.cols,
		CV_8UC1) };
	split(image, colorPlanes);

	/*namedWindow("split blue");
	imshow("split blue", colorPlanes[0]);

	namedWindow("split green");
	imshow("split green", colorPlanes[1]);

	namedWindow("split red");
	imshow("split red", colorPlanes[2]);*/
	Mat BImage(colorPlanes[0].rows, colorPlanes[0].cols, CV_8UC1, Scalar(0, 0, 0));

	Mat BImage1(colorPlanes[1].rows, colorPlanes[1].cols, CV_8UC1, Scalar(0, 0, 0));

	Mat BImage2(colorPlanes[2].rows, colorPlanes[2].cols, CV_8UC1, Scalar(0, 0, 0));


	for (int m = 0; m <= 14;m++){
	
	for (int i = 1; i < colorPlanes[0].rows - 1; i++){
		for (int j = 1; j < colorPlanes[0].cols - 1; j++){
			BImage.at<uchar>(i, j) = (colorPlanes[0].at<uchar>(i, j) * 4 + colorPlanes[0].at<uchar>(i - 1, j - 1) * 1 + colorPlanes[0].at<uchar>(i - 1, j) * 2 + colorPlanes[0].at<uchar>(i - 1, j + 1) * 1
				+ colorPlanes[0].at<uchar>(i, j - 1) * mask[1][0] + colorPlanes[0].at<uchar>(i, j + 1) * 2 + colorPlanes[0].at<uchar>(i + 1, j - 1) * 1 + colorPlanes[0].at<uchar>(i + 1, j) * 2 + colorPlanes[0].at<uchar>(i + 1, j + 1) * 1) / 16;

		}
	}

	

	for (int i = 1; i < colorPlanes[1].rows - 1; i++){
		for (int j = 1; j < colorPlanes[1].cols - 1; j++){
			BImage1.at<uchar>(i, j) = (colorPlanes[1].at<uchar>(i, j) * 4 + colorPlanes[1].at<uchar>(i - 1, j - 1) * 1 + colorPlanes[1].at<uchar>(i - 1, j) * 2 + colorPlanes[1].at<uchar>(i - 1, j + 1) * 1
				+ colorPlanes[1].at<uchar>(i, j - 1) * mask[1][0] + colorPlanes[1].at<uchar>(i, j + 1) * 2 + colorPlanes[1].at<uchar>(i + 1, j - 1) * 1 + colorPlanes[1].at<uchar>(i + 1, j) * 2 + colorPlanes[1].at<uchar>(i + 1, j + 1) * 1) / 16;

		}
	}

	

	for (int i = 1; i < colorPlanes[2].rows - 1; i++){
		for (int j = 1; j < colorPlanes[2].cols - 1; j++){
			BImage2.at<uchar>(i, j) = (colorPlanes[2].at<uchar>(i, j) * 4 + colorPlanes[2].at<uchar>(i - 1, j - 1) * 1 + colorPlanes[2].at<uchar>(i - 1, j) * 2 + colorPlanes[2].at<uchar>(i - 1, j + 1) * 1
				+ colorPlanes[2].at<uchar>(i, j - 1) * mask[1][0] + colorPlanes[2].at<uchar>(i, j + 1) * 2 + colorPlanes[2].at<uchar>(i + 1, j - 1) * 1 + colorPlanes[2].at<uchar>(i + 1, j) * 2 + colorPlanes[2].at<uchar>(i + 1, j + 1) * 1) / 16;

		}
	}

	
	for (int i = 0; i < 1; i++)
	{
		for (int j = 1; j<colorPlanes[0].cols - 1; j++){
			BImage.at<uchar>(i, j) = (colorPlanes[0].at<uchar>(i, j) * mask[1][1] + colorPlanes[0].at<uchar>(i, j - 1) *
				mask[1][0] + colorPlanes[0].at<uchar>(i, j + 1) * mask[1][2] + colorPlanes[0].at<uchar>(i + 1, j - 1) *
				mask[2][0] + colorPlanes[0].at<uchar>(i + 1, j) * mask[2][1] + colorPlanes[0].at<uchar>(i + 1, j + 1) * mask[2][2]) / 16;
		}

		
	}

	for (int i = 0; i < 1; i++)
	{
		for (int j = 1; j<colorPlanes[1].cols - 1; j++){
			BImage1.at<uchar>(i, j) = (colorPlanes[1].at<uchar>(i, j) * mask[1][1] + colorPlanes[1].at<uchar>(i, j - 1) *
				mask[1][0] + colorPlanes[1].at<uchar>(i, j + 1) * mask[1][2] + colorPlanes[1].at<uchar>(i + 1, j - 1) *
				mask[2][0] + colorPlanes[1].at<uchar>(i + 1, j) * mask[2][1] + colorPlanes[1].at<uchar>(i + 1, j + 1) * mask[2][2]) / 16;
		}

		
	}

	for (int i = 0; i < 1; i++)
	{
		for (int j = 1; j<colorPlanes[2].cols - 1; j++){
			BImage2.at<uchar>(i, j) = (colorPlanes[2].at<uchar>(i, j) * mask[1][1] + colorPlanes[2].at<uchar>(i, j - 1) *
				mask[1][0] + colorPlanes[2].at<uchar>(i, j + 1) * mask[1][2] + colorPlanes[2].at<uchar>(i + 1, j - 1) *
				mask[2][0] + colorPlanes[2].at<uchar>(i + 1, j) * mask[2][1] + colorPlanes[2].at<uchar>(i + 1, j + 1) * mask[2][2]) / 16;
		}

		
	}

	for (int i = 1; i < colorPlanes[0].rows - 1; i++)

	{
		for (int j = 0; j <= 0; j++){
			BImage.at<uchar>(i, j) = (colorPlanes[0].at<uchar>(i, j) * mask[1][1] + colorPlanes[0].at<uchar>(i - 1, j) *
				mask[0][1] + colorPlanes[0].at<uchar>(i - 1, j + 1) * mask[0][2] + colorPlanes[0].at<uchar>(i, j + 1) *
				mask[1][2] + colorPlanes[0].at<uchar>(i + 1, j) * mask[2][1] + colorPlanes[0].at<uchar>(i + 1, j + 1) * mask[2][2]) / 16;
		}

		
	}

	for (int i = 1; i < colorPlanes[1].rows - 1; i++)

	{
		for (int j = 0; j <= 0; j++){
			BImage1.at<uchar>(i, j) = (colorPlanes[1].at<uchar>(i, j) * mask[1][1] + colorPlanes[1].at<uchar>(i - 1, j) *
				mask[0][1] + colorPlanes[1].at<uchar>(i - 1, j + 1) * mask[0][2] + colorPlanes[1].at<uchar>(i, j + 1) *
				mask[1][2] + colorPlanes[1].at<uchar>(i + 1, j) * mask[2][1] + colorPlanes[1].at<uchar>(i + 1, j + 1) * mask[2][2]) / 16;
		}

		
	}

	for (int i = 1; i < colorPlanes[2].rows - 1; i++)

	{
		for (int j = 0; j <= 0; j++){
			BImage2.at<uchar>(i, j) = (colorPlanes[2].at<uchar>(i, j) * mask[1][1] + colorPlanes[2].at<uchar>(i - 1, j) *
				mask[0][1] + colorPlanes[2].at<uchar>(i - 1, j + 1) * mask[0][2] + colorPlanes[2].at<uchar>(i, j + 1) *
				mask[1][2] + colorPlanes[2].at<uchar>(i + 1, j) * mask[2][1] + colorPlanes[2].at<uchar>(i + 1, j + 1) * mask[2][2]) / 16;
		}

		
	}
	for (int i = colorPlanes[0].rows; i < colorPlanes[0].rows; i++)
	{
		for (int j = 1; j< colorPlanes[0].cols - 1; j++){
			BImage.at<uchar>(i, j) = (colorPlanes[0].at<uchar>(i, j) * mask[1][1] + colorPlanes[0].at<uchar>(i - 1, j - 1) *
				mask[0][0] + colorPlanes[0].at<uchar>(i - 1, j) * mask[0][1] + colorPlanes[0].at<uchar>(i - 1, j + 1) *
				mask[0][2] + colorPlanes[0].at<uchar>(i, j - 1) * mask[1][0] + colorPlanes[0].at<uchar>(i, j + 1) * mask[1][2]);
		}
	}

	for (int i = colorPlanes[1].rows; i < colorPlanes[1].rows; i++)
	{
		for (int j = 1; j< colorPlanes[1].cols - 1; j++){
			BImage1.at<uchar>(i, j) = (colorPlanes[1].at<uchar>(i, j) * mask[1][1] + colorPlanes[1].at<uchar>(i - 1, j - 1) *
				mask[0][0] + colorPlanes[1].at<uchar>(i - 1, j) * mask[0][1] + colorPlanes[1].at<uchar>(i - 1, j + 1) *
				mask[0][2] + colorPlanes[1].at<uchar>(i, j - 1) * mask[1][0] + colorPlanes[1].at<uchar>(i, j + 1) * mask[1][2]);
		}
	}

	for (int i = colorPlanes[2].rows; i < colorPlanes[2].rows; i++)
	{
		for (int j = 1; j< colorPlanes[2].cols - 1; j++){
			BImage2.at<uchar>(i, j) = (colorPlanes[2].at<uchar>(i, j) * mask[1][1] + colorPlanes[2].at<uchar>(i - 1, j - 1) *
				mask[0][0] + colorPlanes[2].at<uchar>(i - 1, j) * mask[0][1] + colorPlanes[2].at<uchar>(i - 1, j + 1) *
				mask[0][2] + colorPlanes[2].at<uchar>(i, j - 1) * mask[1][0] + colorPlanes[2].at<uchar>(i, j + 1) * mask[1][2]);
		}
	}

	for (int i = 1; i<colorPlanes[0].rows - 1; i++){
		int	j = colorPlanes[0].cols - 1;
		BImage.at<uchar>(i, j) = (colorPlanes[0].at<uchar>(i, j) * 4 + colorPlanes[0].at<uchar>(i - 1, j - 1) * 1 + colorPlanes[0].at<uchar>(i - 1, j) * 2 + colorPlanes[0].at<uchar>(i, j - 1) * mask[1][0] + colorPlanes[0].at<uchar>(i + 1, j) * 2) / 16;
		}
	for (int i = 1; i<colorPlanes[1].rows - 1; i++){
		int	j = colorPlanes[1].cols - 1;
		BImage1.at<uchar>(i, j) = (colorPlanes[1].at<uchar>(i, j) * 4 + colorPlanes[1].at<uchar>(i - 1, j - 1) * 1 + colorPlanes[1].at<uchar>(i - 1, j) * 2 + colorPlanes[1].at<uchar>(i, j - 1) * mask[1][0] + colorPlanes[1].at<uchar>(i + 1, j) * 2) / 16;
	}
	for (int i = 1; i<colorPlanes[2].rows - 1; i++){
		int	j = colorPlanes[2].cols - 1;
		BImage2.at<uchar>(i, j) = (colorPlanes[2].at<uchar>(i, j) * 4 + colorPlanes[2].at<uchar>(i - 1, j - 1) * 1 + colorPlanes[2].at<uchar>(i - 1, j) * 2 + colorPlanes[2].at<uchar>(i, j - 1) * mask[1][0] + colorPlanes[2].at<uchar>(i + 1, j) * 2) / 16;
	}

	BImage.at<uchar>(0, 0) = (colorPlanes[0].at<uchar>(0, 0) * mask[1][1] + colorPlanes[0].at<uchar>(0, 1) *
		mask[1][2] + colorPlanes[0].at<uchar>(1, 0) * mask[2][1] + colorPlanes[0].at<uchar>(1, 1) *
		mask[2][2]) / 16;
	BImage.at<uchar>(0, colorPlanes[0].cols - 1) = (colorPlanes[0].at<uchar>(0, colorPlanes[0].cols - 1) * mask[1][1] + colorPlanes[0].at<uchar>(0, colorPlanes[0].cols - 2) *
		mask[1][0] + colorPlanes[0].at<uchar>(1, colorPlanes[0].cols - 2) * mask[2][0] + colorPlanes[0].at<uchar>(1, colorPlanes[0].cols - 2) *
		mask[2][1]) / 16;
	BImage.at<uchar>(colorPlanes[0].rows - 1, 0) = (colorPlanes[0].at<uchar>(colorPlanes[0].rows - 1, 0) * mask[1][1] + colorPlanes[0].at<uchar>(colorPlanes[0].rows - 2, 0) *
		mask[0][1] + colorPlanes[0].at<uchar>(colorPlanes[0].rows - 2, 1) * mask[0][2] + colorPlanes[0].at<uchar>(colorPlanes[0].rows - 1, 1) *
		mask[1][2]) / 16;
	BImage.at<uchar>(colorPlanes[0].rows - 1, colorPlanes[0].cols - 1) = (colorPlanes[0].at<uchar>(colorPlanes[0].rows - 1, colorPlanes[0].cols - 1) * mask[1][1] + colorPlanes[0].at<uchar>(colorPlanes[0].rows - 2, colorPlanes[0].cols - 1) *
		mask[0][1] + colorPlanes[0].at<uchar>(colorPlanes[0].rows - 2, colorPlanes[0].cols - 2) * mask[0][0] + colorPlanes[0].at<uchar>(colorPlanes[0].rows - 1, colorPlanes[0].cols - 2) *
		mask[1][0]) / 16;

	BImage1.at<uchar>(0, 0) = (colorPlanes[1].at<uchar>(0, 0) * mask[1][1] + colorPlanes[1].at<uchar>(0, 1) *
		mask[1][2] + colorPlanes[1].at<uchar>(1, 0) * mask[2][1] + colorPlanes[1].at<uchar>(1, 1) *
		mask[2][2]) / 16;
	BImage1.at<uchar>(0, colorPlanes[1].cols - 1) = (colorPlanes[1].at<uchar>(0, colorPlanes[1].cols - 1) * mask[1][1] + colorPlanes[1].at<uchar>(0, colorPlanes[1].cols - 2) *
		mask[1][0] + colorPlanes[1].at<uchar>(1, colorPlanes[1].cols - 2) * mask[2][0] + colorPlanes[1].at<uchar>(1, colorPlanes[1].cols - 2) *
		mask[2][1]) / 16;
	BImage1.at<uchar>(colorPlanes[1].rows - 1, 0) = (colorPlanes[1].at<uchar>(colorPlanes[1].rows - 1, 0) * mask[1][1] + colorPlanes[1].at<uchar>(colorPlanes[1].rows - 2, 0) *
		mask[0][1] + colorPlanes[1].at<uchar>(colorPlanes[1].rows - 2, 1) * mask[0][2] + colorPlanes[1].at<uchar>(colorPlanes[1].rows - 1, 1) *
		mask[1][2]) / 16;
	BImage1.at<uchar>(colorPlanes[1].rows - 1, colorPlanes[1].cols - 1) = (colorPlanes[1].at<uchar>(colorPlanes[1].rows - 1, colorPlanes[1].cols - 1) * mask[1][1] + colorPlanes[1].at<uchar>(colorPlanes[1].rows - 2, colorPlanes[1].cols - 1) *
		mask[0][1] + colorPlanes[1].at<uchar>(colorPlanes[1].rows - 2, colorPlanes[1].cols - 2) * mask[0][0] + colorPlanes[1].at<uchar>(colorPlanes[1].rows - 1, colorPlanes[1].cols - 2) *
		mask[1][0]) / 16;

	BImage2.at<uchar>(0, 0) = (colorPlanes[2].at<uchar>(0, 0) * mask[1][1] + colorPlanes[2].at<uchar>(0, 1) *
		mask[1][2] + colorPlanes[2].at<uchar>(1, 0) * mask[2][1] + colorPlanes[2].at<uchar>(1, 1) *
		mask[2][2]) / 16;
	BImage2.at<uchar>(0, colorPlanes[2].cols - 1) = (colorPlanes[2].at<uchar>(0, colorPlanes[2].cols - 1) * mask[1][1] + colorPlanes[2].at<uchar>(0, colorPlanes[2].cols - 2) *
		mask[1][0] + colorPlanes[2].at<uchar>(1, colorPlanes[2].cols - 2) * mask[2][0] + colorPlanes[2].at<uchar>(1, colorPlanes[2].cols - 2) *
		mask[2][1]) / 16;
	BImage2.at<uchar>(colorPlanes[2].rows - 1, 0) = (colorPlanes[2].at<uchar>(colorPlanes[2].rows - 1, 0) * mask[1][1] + colorPlanes[2].at<uchar>(colorPlanes[2].rows - 2, 0) *
		mask[0][1] + colorPlanes[2].at<uchar>(colorPlanes[2].rows - 2, 1) * mask[0][2] + colorPlanes[2].at<uchar>(colorPlanes[2].rows - 1, 1) *
		mask[1][2]) / 16;
	BImage2.at<uchar>(colorPlanes[2].rows - 1, colorPlanes[2].cols - 1) = (colorPlanes[2].at<uchar>(colorPlanes[2].rows - 1, colorPlanes[2].cols - 1) * mask[1][1] + colorPlanes[2].at<uchar>(colorPlanes[2].rows - 2, colorPlanes[2].cols - 1) *
		mask[0][1] + colorPlanes[2].at<uchar>(colorPlanes[2].rows - 2, colorPlanes[2].cols - 2) * mask[0][0] + colorPlanes[2].at<uchar>(colorPlanes[2].rows - 1, colorPlanes[2].cols - 2) *
		mask[1][0]) / 16;

	BImage.copyTo(colorPlanes[0]);
		BImage1.copyTo(colorPlanes[1]);
		BImage2.copyTo(colorPlanes[2]);

}

	
	/*imshow("gaussian image", BImage);
	imshow("gaussian image1", BImage1);
	imshow("gaussian image2", BImage2);*/

	/*Mat image2[] = { BImage, BImage1, BImage2 };*/
	Mat newimage = image.clone();

	merge(colorPlanes, 3, newimage);
	imshow("Blur image", newimage);

	waitKey(-1);
	return 0;
}