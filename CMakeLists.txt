cmake_minimum_required(VERSION 3.3)
project(angrybirds)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Board.cpp Board.h Globals.h DrawHelper.cpp DrawHelper.h Cannon.cpp Cannon.h Bird.cpp Bird.h Object.cpp Object.h Blocks.cpp Blocks.h Meters.cpp Meters.h)
add_executable(angrybirds ${SOURCE_FILES})