//
// Created by harshil on 21/1/16.
//

#ifndef ANGRYBIRDS_BIRD_H
#define ANGRYBIRDS_BIRD_H

#include "Object.h"

class Bird : public Object {
    public:
        Bird();
        ~Bird();

        float velX, velY;

        bool moving;

        void drawBird();
        void moveBird();

        void checkCollision();

};


#endif //ANGRYBIRDS_BIRD_H
