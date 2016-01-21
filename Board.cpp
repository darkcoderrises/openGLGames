//
// Created by harshil on 21/1/16.
//
#include "Board.h"
#include "DrawHelper.h"

void Board::makeBoard() {
    DrawHelper a;
    a.drawReact(1.0f, 0.0f, 0.0f);
    a.drawReact(RGB_WHITE);
}