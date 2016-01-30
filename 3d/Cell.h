//
// Created by harshil on 30/1/16.
//

#ifndef INC_3D_CELL_H
#define INC_3D_CELL_H

#include "Globals.h"
#include "DrawHelper.h"

class Cell {
public:
    float l, b, h;
    float x, y, z;
    bool collapse;
    float color[6][3] ={
            {RGB_BLUE},
            {RGB_RED},
            {RGB_TRON_ORANGE},
            {RGB_YELLOW},
            {RGB_GRAY},
            {RGB_BLACK}
    };

    Cell();
    ~Cell();
    void drawCell();
};


#endif //INC_3D_CELL_H
