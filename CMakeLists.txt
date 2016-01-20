cmake_minimum_required(VERSION 3.3)
project(angrybirds)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Board.cpp Board.h Globals.h)
add_executable(angrybirds ${SOURCE_FILES})