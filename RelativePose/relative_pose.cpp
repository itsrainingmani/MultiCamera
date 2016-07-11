#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include "opencv2/calib3d.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace cv;
using namespace std;

string type2str(int type) {
  string r;

  uchar depth = type & CV_MAT_DEPTH_MASK;
  uchar chans = 1 + (type >> CV_CN_SHIFT);

  switch ( depth ) {
    case CV_8U:  r = "8U"; break;
    case CV_8S:  r = "8S"; break;
    case CV_16U: r = "16U"; break;
    case CV_16S: r = "16S"; break;
    case CV_32S: r = "32S"; break;
    case CV_32F: r = "32F"; break;
    case CV_64F: r = "64F"; break;
    default:     r = "User"; break;
  }

  r += "C";
  r += (chans+'0');

  return r;
}

int main(int argc, char** argv){

	ifstream infile1("../img1pts.txt");
	ifstream infile2("../img2pts.txt");
	
	Mat K1;
	Mat distortion_coefficients1;
	Mat P1;
	Mat rectification_matrix1;

	Mat K2;
	Mat distortion_coefficients2;
	Mat P2;
	Mat rectification_matrix2;

	FileStorage fs;
	if (!fs.isOpened()){
		fs.open("../kinect1.xml", FileStorage::READ);
		fs["camera_matrix"] >> K1;
		fs["distortion_coefficients"] >> distortion_coefficients1;
		fs["projection_matrix"] >> P1;
		fs["rectification_matrix"] >> rectification_matrix1;
		fs.release();
	}
	if (!fs.isOpened()){
		fs.open("../kinect2.xml", FileStorage::READ);
		fs["camera_matrix"] >> K2;
		fs["distortion_coefficients"] >> distortion_coefficients2;
		fs["projection_matrix"] >> P2;
		fs["rectification_matrix"] >> rectification_matrix2;
		fs.release();
	}

	// string ty = type2str(K1.type());
	// printf("Matrix: %s %dx%d \n", ty.c_str(), K1.cols, K1.rows );

	K1.convertTo(K1, CV_64FC1);
	K2.convertTo(K2, CV_64FC1);

	vector< Point2f > points1;
	vector< Point2f > points2;

	string line;
	if (infile1.is_open()){
		while (getline(infile1, line)){
			istringstream iss(line);
			float x, y;
			if (!(iss >> x >> y)){ break; }
			Point2f pt(x, y);
			points1.push_back(pt);
		}
		infile1.close();
	}
	if (infile2.is_open()){
		while (getline(infile2, line)){
			istringstream iss(line);
			float x, y;
			if (!(iss >> x >> y)){ break; }
			Point2f pt(x, y);
			points2.push_back(pt);
		}
		infile2.close();
	}
	Mat F, E, R, t, mask;

	F = findFundamentalMat(points1, points2, FM_RANSAC, 3, 0.99);
	cout<<"The Fundamental Matrix is \n"<<F<<endl;
	// ty = type2str(F.type());
	// printf("Matrix: %s %dx%d \n", ty.c_str(), F.cols, F.rows );

	E = (K2.t() * F) * K1;

	//E = findEssentialMat(points1, points2, K1, RANSAC, 0.999, 1.0, mask);
	// cout<<"The Essential Matrix is \n"<<E<<endl;

	// recoverPose(E, points1, points2, K1, R, t, mask);
	// cout<<"The Rotation Matrix is \n"<<R<<endl;
	// cout<<"The Translation Vector is \n"<<t<<endl;

	return 1;
}