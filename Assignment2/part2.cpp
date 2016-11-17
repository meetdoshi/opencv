#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main()
{
	Mat image = imread("statue.bmp");
	int row = image.rows;
	int col = image.cols;

	
	cout << "the output for matrix of pixels";

	
	
	for (int x = 0; x <row; x++)
	{
		Vec3b *ptr = image.ptr<Vec3b>(x);

		for (int y = 0; y < col; y++)
		{
			Vec3b pixel = ptr[y];

		}
		cout << "\n";
	}

	imshow("Image", image);
	

	Mat blur = image.clone();

	GaussianBlur(image, blur, Size(5, 5), 0, 0);


	

	
	for (int x = 0; x < row; x++)
	{
		Vec3b *ptr = blur.ptr<Vec3b>(x);

		for (int y = 0; y < col; y++)
		{
			Vec3b pixel = ptr[y];
			
		}
		cout << "\n";
	}


	imshow("Blurimg:", blur);
	
	Mat maskimg = image - blur;
	imshow("maskimg:", maskimg);
	
	Mat unsharp = image + maskimg;
	imshow("unsharpimg:", unsharp);

	Mat high = image + 10 * maskimg;
	imshow("highboostimg:", high);

	waitKey(0);

}