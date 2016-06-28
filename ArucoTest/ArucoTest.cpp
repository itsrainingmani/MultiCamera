//saves all the images of the dictionary indicated to a dicrectory

#include <aruco/aruco.h>
#include <aruco/dictionary.h>
#include <opencv2/highgui/highgui.hpp>
#include <string>

using namespace std;
using namespace cv;
using namespace aruco;

int main(int argc,char **argv){

	VideoCapture cap(0);
	if(!cap.isOpened())
	{
		cout<<"Cannot open video camera"<<endl;
		return -1;
	}

	MarkerDetector Md;
	vector<Marker> Markers;
	Md.setDictionary("TAG36h11");

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
		cap.retrieve(image);
		image.copyTo(imageCopy);

		Md.detect(image, Markers);

		for (unsigned int i = 0;i < Markers.size(); i++){
			cout<<Markers[i]<<endl;
			Markers[i].draw(imageCopy, Scalar(0,0,255), 2);
		}

		imshow("MyVideo", imageCopy); //show the frame in "MyVideo" window

		if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		{
			cout << "esc key is pressed by user" << endl;
			break; 
		}
	}
    return 0;
}