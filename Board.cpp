//
// Created by harshil on 21/1/16.
//
#include "Board.h"
#include "DrawHelper.h"

void Board::init() {
}

Board::Board() {
    this->cannon = Cannon();
}

Board::~Board() {

}

void Board::makeBoard() {
    DrawHelper a;

    a.push(0,0);
    a.drawReact(RGB_LIGHT_GRAY, BOX_SIZE);
    a.pop();

    this->cannon.drawCannon();
    //this->cannon.changeAngle();
}