//
// Created by harshil on 30/1/16.
//

#include "Board.h"
#include "DrawHelper.h"

Board::Board() {

}

Board::~Board() {

}

void Board::drawBoard() {
    DrawHelper a = DrawHelper();
    a.push(0,0);
    float color[6][3] = {
            {RGB_BLUE},
            {RGB_RED},
            {RGB_TRON_ORANGE},
            {RGB_YELLOW},
            {RGB_GRAY},
            {RGB_BLACK}
    };
    a.drawCuboid(color, 2, 2, 2);
    a.pop();
}