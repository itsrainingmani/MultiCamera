import freenect
import cv2
import numpy as np
from matplotlib import pyplot as plt

#Function to get rgb image from kinect
def get_video():
	array,_ = freenect.sync_get_video()
	array = cv2.cvtColor(array,cv2.COLOR_RGB2BGR)
	return array

#function to get depth image from kinect
def get_depth():
	array,_ = freenect.sync_get_depth()
	array = array.astype(np.uint8)
	return array

#Obtain the face and eye classifiers
face_cascade = cv2.CascadeClassifier('/home/money/opencv/data/haarcascades/haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier('/home/money/opencv/data/haarcascades/haarcascade_eye.xml')

if __name__ == "__main__":
	while 1:
		#get a frame from RGB camera
		frame = get_video()
		#get a frame from depth sensor

		#Convert the fram to grayscale
		gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

		#Detect faces
		faces = face_cascade.detectMultiScale(gray, 1.2, 3)

		#Loop for drawing rectangles around faces and eyes
		for (x,y,w,h) in faces:
			cv2.rectangle(frame, (x,y), (x+w, y+h), (255,0,0), 2)
			roi_gray = gray[y:y+h, x:x+w]
			roi_color = frame[y:y+h, x:x+w]
			eyes = eye_cascade.detectMultiScale(roi_gray)
			for (ex,ey,ew,eh) in eyes:
				cv2.rectangle(roi_color, (ex,ey), (ex+ew, ey+eh), (0,255,0), 2)
		cv2.imshow('Frame', frame)
 
		# quit program when 'esc' key is pressed
		k = cv2.waitKey(5) & 0xFF
		if k == 27:
			break
	cv2.destroyAllWindows()