//
// Created by harshil on 21/1/16.
//
#include "Board.h"
#include "DrawHelper.h"

Board::Board() {
    this->cannon = Cannon();
    this->birds.push_back(Bird());
}

Board::~Board() {

}

void Board::makeBoard() {
    DrawHelper a;

    a.push(0,0);
    a.drawReact(RGB_LIGHT_GRAY, BOX_SIZE);
    a.pop();

    this->cannon.drawCannon();

    for (int i=0; i<(signed) this->birds.size(); i++){
        this->birds[i].checkCollision();
        this->birds[i].moveBird();
    }

    this->birds[0].drawBird();
}
