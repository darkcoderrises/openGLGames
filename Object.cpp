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

bool Object::checkCollide(Object o1, Object o2) {
    float dist = (float) sqrt((o1.x-o2.x)*(o1.x-o2.x)+(o1.y-o2.y)*(o1.y-o2.y));
    return (dist<=(o1.rad + o2.rad));
}