cmake_minimum_required(VERSION 3.3)
project(3d)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Board.cpp Board.h Cell.cpp Cell.h)
add_executable(3d ${SOURCE_FILES})