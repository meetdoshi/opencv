#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <iostream>
using namespace cv;
using namespace std;


int main(){

	
	Mat image = imread("lena_std.tif");

	namedWindow("orginal image");
	imshow("orginal image", image);

	/*Mat newimage = image.clone();*/

	Mat colorPlanes[] = { Mat(image.rows, image.cols, CV_8UC1),
		Mat(image.rows, image.cols, CV_8UC1), Mat(image.rows, image.cols,
		CV_8UC1) };
	split(image, colorPlanes);

	Mat BImage(colorPlanes[0].rows, colorPlanes[0].cols, CV_8UC1, Scalar(0, 0, 0));

	Mat BImage1(colorPlanes[1].rows, colorPlanes[1].cols, CV_8UC1, Scalar(0, 0, 0));

	Mat BImage2(colorPlanes[2].rows, colorPlanes[2].cols, CV_8UC1, Scalar(0, 0, 0));

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			int r, g, b,d,m,n,o,p,e,q,l;
			int cr = 145, cg = 101, cb = 152;
			b = colorPlanes[0].at<uchar>(i, j);
			g = colorPlanes[1].at<uchar>(i, j);
			r = colorPlanes[2].at<uchar>(i, j);
			m = b - cb;
			n = g - cg;
			o = r - cr;
			p = m*m;
			e = n*n;
			q = o*o;
			l = p + e + q;
			d = sqrt(l);
			if (d > 50)
			{
				b = g = r = 0;
			}

			colorPlanes[0].at<uchar>(i, j)=b;
			colorPlanes[1].at<uchar>(i, j)=g;
			colorPlanes[2].at<uchar>(i, j)=r;

		}
	}
	Mat newimage = image.clone();

	merge(colorPlanes, 3, newimage);
	imshow("color image", newimage);

	waitKey(-1);
	return 0;
}
