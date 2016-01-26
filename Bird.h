//
// Created by harshil on 21/1/16.
//

#ifndef ANGRYBIRDS_BIRD_H
#define ANGRYBIRDS_BIRD_H

#include "Object.h"
#include "Map.h"

class Bird : public Object {
    public:
        Bird();
        ~Bird();

        bool moving;
        bool stop;

        void drawBird();
        void moveBird();
        void setBird(float angle, float x, float y);

        void checkCollision(Map map);

};


#endif //ANGRYBIRDS_BIRD_H
