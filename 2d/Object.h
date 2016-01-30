//
// Created by harshil on 22/1/16.
//

#ifndef ANGRYBIRDS_OBJECT_H
#define ANGRYBIRDS_OBJECT_H

#include "Globals.h"

class Object {
    public:
        Object();
        ~Object();

        float x, y, rad, velX, velY;
        bool moveable;

        bool onGround();

        bool checkCollide(Object o1, Object o2);
};


#endif //ANGRYBIRDS_OBJECT_H
