//
// Created by harshil on 21/1/16.
//

#ifndef ANGRYBIRDS_GLOBALS_H
#define ANGRYBIRDS_GLOBALS_H

#include <cstdio>
#include <iostream>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>

#define COL_BLACK 0
#define COL_WHITE 1
#define COL_RED 2
#define COL_BLUE 3
#define COL_GRAY 4

#define PI 3.1415926f
#define DEG2RAD(deg) (deg * PI / 180.0f)
#define RAD2DEG(rad) (rad * 180 / PI)

#define RGB_BACKGROUND 0.0f,0.0f,0.0f

#define RGB_BLACK 0.1f,0.1f,0.1f
#define RGB_WHITE 1.0f,1.0f,1.0f
#define RGB_RED 1.0f,0.0f,0.0f
#define RGB_BLUE 0.0f,0.0f,1.0f
#define RGB_YELLOW 1.0f,1.0f,0.0f

#define RGB_GRAY 0.18431f,0.30980f,0.30980f

#define RGB_TRON_CYAN 0.46666f,0.53333f,0.6f
#define RGB_BASE_STAR 0.04705f,0.17843f,0.32156f
#define RGB_TRON_ORANGE 0.54117f,0.16862f,0.88627f

#define RGB_DARK_GRAY 0.03f,0.03f,0.03f
#define RGB_LIGHT_GRAY 0.07f,0.07f,0.07f

#define FRAME_DIVISIONS 1

#define BOX_SIZE 8.0f

#define MIN_ANGLE 10.0f
#define MAX_ANGLE 70.0f

#define accY 0.005

#define frictionX 0.001
#define frictionY 0.001

#define errorY 1

#define COEFFICIENT_OF_RESTITUTION 1;

#endif //ANGRYBIRDS_GLOBALS_H
