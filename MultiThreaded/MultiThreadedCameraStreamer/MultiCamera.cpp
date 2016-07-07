#include "CameraStreamer.hpp"

int main()
{
	//IP camera URLs
    vector<string> capture_source = {
        "rtsp://192.168.2.100/profile2/media.smp",
        "rtsp://192.168.0.100/profile2/media.smp"
    };
 
    //USB Camera indices
    vector<int> capture_index = { CV_CAP_OPENNI, CV_CAP_OPENNI + 1 };
 
    //Highgui window titles
    vector<string> label;
    for (int i = 0; i < capture_source.size(); i++)
    {
        string title = "CCTV " + to_string(i);
        label.push_back(title);
    }
 
    //Make an instance of CameraStreamer
    CameraStreamer cam(capture_index);
 
    while (waitKey(30) != 27)
    {
        //Retrieve frames from each camera capture thread
        for (int i = 0; i < capture_index.size(); i++)
        {
            /*
            Mat frame;
            //Pop frame from queue and check if the frame is valid
            if (cam.frame_queue[i]->try_pop(frame)){
                //Show frame on Highgui window
                imshow(label[i], frame);
            }
            */
        }
    }
    return 0;
}