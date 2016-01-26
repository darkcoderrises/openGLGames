//
// Created by harshil on 23/1/16.
//

#include "Blocks.h"
#include "DrawHelper.h"
#include "Globals.h"

Blocks::Blocks(){
    this->moveable = false;
    this->rad = 1;

    srand ((unsigned int)time(NULL));
    this->x = rand() % ((int)BOX_SIZE-1);
    this->y = -1 * (rand() % ((int) BOX_SIZE-1));
}

Blocks::Blocks(Object object){
    this->moveable = false;
    this->rad = object.rad;
    this->x = object.x;
    this->y = object.y;
}

void Blocks::drawBlock() {
    DrawHelper a = DrawHelper();
    this->checkFall();
    a.push(this->x, this->y);

    a.drawSquare(RGB_TRON_ORANGE, this->rad);

    a.pop();
}

void Blocks::checkFall() {

}


