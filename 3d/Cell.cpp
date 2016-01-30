//
// Created by harshil on 30/1/16.
//

#include "Cell.h"

Cell::Cell(){
    this->x=0;
    this->y=0;
    this->z=-10.0f;
};

Cell::~Cell() {

};

void Cell::drawCell() {
    DrawHelper a = DrawHelper();
    a.push(this->x, this->y, this->z);
        a.drawCuboid(this->color, this->l, this->b, this->h);
    a.pop();
}