//
// Created by harshil on 26/1/16.
//

#ifndef ANGRYBIRDS_OBSTACLE_H
#define ANGRYBIRDS_OBSTACLE_H

#include "Object.h"
#include "Globals.h"
#include "DrawHelper.h"

class Obstacle : public Object{
    public:
        Obstacle();
        Obstacle(std::vector<Object> objects);
        ~Obstacle();

        float velX, velY;
        void checkWall();
        void drawObstacle();
        void moveObstacle();
};


#endif //ANGRYBIRDS_OBSTACLE_H
