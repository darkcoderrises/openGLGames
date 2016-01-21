//
// Created by harshil on 21/1/16.
//

#include "Bird.h"
#include "DrawHelper.h"
#include "Globals.h"

Bird::Bird() {
    this->x=0;
    this->y=0;

    this->velX = 0.05;
    this->velY = 0.05;

    this->moving = false;
}

Bird::~Bird() {

}

void Bird::drawBird() {

    DrawHelper a;
    a.push(this->x, this->y);
    a.drawCircle(RGB_BLUE, 0.5);
    a.pop();
}

void Bird::moveBird() {
    if (not moving)
        return;

    this->x += this->velX;
    this->y += this->velY;

    this->velY -= accY;

    if (velY<0) velY+=2*frictionY; velY-=frictionY;
    if (velX<0) velX+=2*frictionX; velX-=frictionX;
}

void Bird::checkCollision() {
    if (this->x <= (0.5-BOX_SIZE) or this->x >= (BOX_SIZE-0.5)){
        velX *= -1;
    }

    if (this->y <= (2-BOX_SIZE) or this->y >= (BOX_SIZE-2)){
        velY *= -1;
        this->velY -= accY;
    }
}


