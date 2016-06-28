#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <aruco/aruco.h>
#include <aruco/dictionary.h>
#include <iostream>
#include <string>
#include <thread>
 
using namespace cv;
using namespace std;
using namespace aruco;
 
void tag_detection(int camera_id){
    //cout<<"New threads created"<<endl;
    VideoCapture cap;
    cap.open(camera_id);
    
    if (!cap.isOpened()){
        cout<<"Cannot open video camera "<<camera_id<<endl;
        return;
    }
    string label = "Camera - " + to_string(camera_id);
    Mat frame;
    MarkerDetector md;
    md.setDictionary("TAG36h11");
    vector<Marker> markers;

    while(cap.grab()){
        cap.retrieve(frame, CV_CAP_OPENNI_BGR_IMAGE);
        md.detect(frame, markers);
        for (unsigned int i = 0; i < markers.size(); i++){
                cout<<markers[i]<<endl;
                markers[i].draw(frame, Scalar(0,0,255), 2);
            }
            imshow(label, frame);
            if (waitKey(30) == 27){
                break;
            }
    }
    cap.release();
    return;
}

int main(int argc, char* argv[])
{
    const uint CAM_NUM = 2;
    cout<<"Program ran"<<endl;
    //vector<thread*> camera_threads;
    //This will hold the VideoCapture objects
    vector<int> kinect_id = {CV_CAP_OPENNI, CV_CAP_OPENNI + 1};
    for (int i = 0; i < kinect_id.size(); i++){
        thread* t = new thread(&tag_detection, kinect_id[i]);
        t->detach();
    }
    return 0;
}