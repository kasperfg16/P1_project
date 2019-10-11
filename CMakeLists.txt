cmake_minimum_required(VERSION 2.8.3)
project(P1_projekt)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  turtlesim
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
)

###########
## Build ##
###########
include_directories(
  ${catkin_INCLUDE_DIRS}
)

# Declare Kill Turtles C++ executable and rename to short name (in case catkin_make is used).
add_executable(${PROJECT_NAME}_make_box src/make_box.cpp)
set_target_properties(${PROJECT_NAME}_make_box PROPERTIES OUTPUT_NAME make_box PREFIX "")
# Link to Catkin libraries
target_link_libraries(${PROJECT_NAME}_make_box
  ${catkin_LIBRARIES}
)


#############
## Install ##
#############

# Mark executables for installation
install(TARGETS
  ${PROJECT_NAME}_make_box
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
