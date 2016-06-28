cmake_minimum_required(VERSION 2.8)
project( CameraStreamer )
SET(CMAKE_CXX_FLAGS "-std=c++11")
find_package( OpenCV REQUIRED )
file(GLOB cam_stream_SRC
	"*.h"
	"*.cpp"
)
add_executable( MultiCamera ${cam_stream_SRC} )
target_link_libraries( MultiCamera ${OpenCV_LIBS} )