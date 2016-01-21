//
// Created by harshil on 21/1/16.
//
#include "Board.h"
#include "DrawHelper.h"

void Board::makeBoard() {
    DrawHelper a;
    a.drawReact(RGB_RED, 0, 0);
    a.drawReactEmpty(RGB_WHITE, 1, 1);
    a.drawEllipse(RGB_RED, 3, 4, 1, 5);
}