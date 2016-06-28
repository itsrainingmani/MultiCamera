#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <aruco/aruco.h>
#include <aruco/dictionary.h>
#include <iostream>
#include <string>
 
using namespace cv;
using namespace std;
using namespace aruco;
 
int main()
{
    //The number of connected USB camera(s)
    const uint CAM_NUM = 2;
 
    //This will hold the VideoCapture objects
    VideoCapture camCaptures[CAM_NUM];
 
    //This will hold the resulting frames from each camera
    Mat camFrames[CAM_NUM];

    MarkerDetector Md;
    Md.setDictionary("TAG36h11");
    vector<Marker> Markers;
 
    //This will be used for highgui window name
    string labels[CAM_NUM];

    int kinectNum[2] = {CV_CAP_OPENNI, CV_CAP_OPENNI + 1};
 
    //Initialization of VideoCaptures
    for (int i = 0; i < CAM_NUM; i++)
    {
        //Md[i].setDictionary("TAG36h11");
        //Init label for highgui window name
        labels[i] = "Camera " + to_string(i);
        //Opening camera capture stream
        camCaptures[i].open(kinectNum[i]);
    }
 
    //continous loop until 'Esc' key is pressed
    while (waitKey(1) != 27){
        for (int i = 0; i < CAM_NUM; i++)
        {
            camCaptures[i].grab();
            camCaptures[i].retrieve(camFrames[i], CV_CAP_OPENNI_BGR_IMAGE);
            Md.detect(camFrames[i], Markers);

            for (unsigned int j = 0; i < Markers.size(); j++){
                cout<<Markers[j]<<endl;
                Markers[j].draw(camFrames[i], Scalar(0,0,255), 2);
            }
            imshow(labels[i], camFrames[i]);
        }
    }
 
    //Releasing all VideoCapture resources
    for (int i = 0; i < CAM_NUM; i++)
    {
        camCaptures[i].release();
    }
    return 0;
}