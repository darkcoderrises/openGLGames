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
    return ((this->y - this->rad) <= (errorY-BOX_SIZE));
}