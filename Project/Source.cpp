#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


void detect(Mat image);
void recognize(Mat image);

string face_cascade_name = "haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;
string window_name = "Capture - Face detection";
int filenumber; 
string filename;


int main(void)
{
	
	if (!face_cascade.load(face_cascade_name))
	{
		printf("--(!)Error loading\n");
		return (-1);
	};

	Mat image = imread("main.JPG");
	
	for (;;)
	{
		
		if (!image.empty())
		{
			detect(image);
			recognize(image);
		}
		else
		{
			printf(" --(!) No captured frame -- Break!");
			break;
		}

		int m = waitKey(10);

		if (27 == char(m))
		{
			break;
		}
	}

	return 0;
}


void detect(Mat image)
{
	std::vector<Rect> faces;
	Mat image_gray;
	Mat crop;
	Mat re;
	Mat gray;
	

	cvtColor(image, image_gray, COLOR_BGR2GRAY);
	equalizeHist(image_gray, image_gray);

	
	face_cascade.detectMultiScale(image_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

	
	cv::Rect roi1;
	cv::Rect roi2;

	size_t c = 0; 
	int ac = 0; 

	size_t b = 0; 
	int ab = 0; 

	for (c = 0; c < faces.size(); c++) 

	{
		roi2.x = faces[c].x;
		roi2.y = faces[c].y;
		roi2.width = (faces[c].width);
		roi2.height = (faces[c].height);

		ac = roi2.width * roi2.height; 

		roi1.x = faces[b].x;
		roi1.y = faces[b].y;
		roi1.width = (faces[b].width);
		roi1.height = (faces[b].height);

		ab = roi1.width * roi1.height; 

		if (ac > ab)
		{
			b = c;
			roi1.x = faces[b].x;
			roi1.y = faces[b].y;
			roi1.width = (faces[b].width);
			roi1.height = (faces[b].height);
		}

		crop = image(roi1);
		resize(crop, re, Size(128, 128), 0, 0, INTER_LINEAR); 
		cvtColor(crop, gray, COLOR_BGR2GRAY); 

		
		filename = "";
		stringstream ssfn;
		ssfn << filenumber << ".png";
		filename = ssfn.str();
		filenumber++;

		imwrite(filename, gray);

		

		Point pt1(faces[c].x, faces[c].y);
		Point pt2((faces[c].x + faces[c].height), (faces[c].y + faces[c].width));
		rectangle(image, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
	}
	
}


void recognize(Mat image)
{
	Mat n[] = { imread("0.png"), imread("1.png") };
	Mat m[] = { imread("priyank.png"), imread("meet.png") };

	
	
	stringstream name,nm;
	String text,text1;

	if (m[0].rows == n[0].rows && m[0].cols == n[0].cols)
	{
		for (int i = 0; i < m[0].rows; i++)
		{
			for (int j = 0; j < m[0].cols; j++)
			{
				String m_ref = m[0].at<uchar>(i, j).Str();
				String n_ref = n[0].at<uchar>(i, j).Str();
				if (m_ref != n_ref)
				{
					bool flag = false;
					break;
				}
			}
		}
		if (bool flag=false())
	{
		name << "Meet";
		nm << "Priyank";
		text = name.str();
		text1 = nm.str();
		putText(image, text, Point(20, 250), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(0, 0, 255), 1, LINE_AA);
		putText(image, text1, Point(150, 250), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(0, 0, 255), 1, LINE_AA);
		imshow("original", image);

	}
		
	else
	{
		name << "Priyank";
		nm << "Meet";
		text = name.str();
		text1 = nm.str();
		putText(image, text, Point(20, 250), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(0, 0, 255), 1, LINE_AA);
		putText(image, text1, Point(150, 250), FONT_HERSHEY_COMPLEX_SMALL, 0.8, Scalar(0, 0, 255), 1, LINE_AA);
		imshow("original", image);
	}
	
}