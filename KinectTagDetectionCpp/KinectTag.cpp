#include <iostream>
#include <vector>
#include <string>
#include <opencv2/highgui.hpp>
//#include <opencv2/aruco.hpp>

using namespace cv;
using namespace std;
//using namespace aruco;

int main(int argc, char* argv[])
{
	//cout << cv::getBuildInformation() << endl;

	//CV_CAP_OPENNI is for the Kinect camera
	//TODO -- Implement the multithreaded system
	VideoCapture cap(CV_CAP_OPENNI);
	if(!cap.isOpened())
	{
		cout<<"Cannot open video camera"<<endl;
		return -1;
	}

	//Need a pointer to the Dictionary for the detectMarkerk method to work
	//Ptr<Dictionary> dictionary = getPredefinedDictionary(DICT_6X6_250);

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Frame size : " << dWidth << " x " << dHeight << endl;

	namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

	//Main loop for getting video
	while (cap.grab())
	{
		Mat image, imageCopy;
		cap.retrieve(image, CV_CAP_OPENNI_BGR_IMAGE);
		image.copyTo(imageCopy);

		/*
		vector<int> ids;
		vector< vector< Point2f > > corners;
		detectMarkers(image, dictionary, corners, ids);

		if (ids.size() > 0)
			drawDetectedMarkers(imageCopy, corners, ids);
		*/

		imshow("MyVideo", imageCopy); //show the frame in "MyVideo" window

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break; 
		}
	}
	return 0;
}
