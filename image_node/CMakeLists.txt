cmake_minimum_required(VERSION 2.8.3)
project(image_node)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


find_package(catkin REQUIRED COMPONENTS
 roscpp
 rospy
 std_msgs
 sensor_msgs
 cv_bridge
 image_transport
 OpenCV
)

catkin_package(CATKIN_DEPENDS
  roscpp
  std_msgs
  sensor_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
include_directories(include ${OpenCV_INCLUDE_DIRS})

add_executable(node_a src/node_a.cpp) 
target_link_libraries(node_a ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} ) 

add_executable(node_b src/node_b.cpp) 
target_link_libraries(node_b ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} ) 
