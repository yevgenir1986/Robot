cmake_minimum_required (VERSION 3.5)

project (Robot)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

add_executable (HelloWorld ${source_files} src/RobotAlgorithm.cpp src/RobotAlgorithm.h src/Simulation.cpp src/Simulation.h src/Sensors.h src/common.h src/SimulationRobotRep.h)

