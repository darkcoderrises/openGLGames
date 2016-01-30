//
// Created by harshil on 30/1/16.
//

#ifndef INC_3D_BOARD_H
#define INC_3D_BOARD_H

#include "Globals.h"
#include "Cell.h"

class Board {
public:
    Board();
    ~Board();
    float x, y;

    Cell cells[10][10];
    void drawBoard();
};


#endif //INC_3D_BOARD_H
