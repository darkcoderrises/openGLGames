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
        bool stop;

        void drawBird();
        void moveBird();
        void setBird(float angle, float x, float y);

        void checkCollision();

};


#endif //ANGRYBIRDS_BIRD_H
