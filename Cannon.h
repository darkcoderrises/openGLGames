//
// Created by harshil on 21/1/16.
//

#ifndef ANGRYBIRDS_CANNON_H
#define ANGRYBIRDS_CANNON_H

#include "Globals.h"

class Cannon {
    public:
        float angle;

        Cannon();
        ~Cannon();
        void drawCannon();
        void changeAngle();
};


#endif //ANGRYBIRDS_CANNON_H
