//
// Created by harshil on 22/1/16.
//

#include "Object.h"
#include "Globals.h"

Object::Object() {

}

Object::~Object() {

}

bool Object::onGround() {
    if ((this->y - this->rad) <= -1 * BOX_SIZE) {std::cout<<"onGround\n";}
    return ((this->y - this->rad) == (-1*BOX_SIZE));
}