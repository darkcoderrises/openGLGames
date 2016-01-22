//
// Created by harshil on 21/1/16.
//

#include "Bird.h"
#include "DrawHelper.h"
#include "Globals.h"

Bird::Bird() {
    this->x=0;
    this->y=0;
    this->rad=0.5;

    this->velX = 0.05;
    this->velY = 0.05;

    this->moving = false;
    this->moveable = true;
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

    if (this->velY<0) this->velY+=2*frictionY; this->velY-=frictionY;
    if (this->velX<0) this->velX+=2*frictionX; this->velX-=frictionX;
}

void Bird::checkCollision() {
    if (this->x <= (this->rad - BOX_SIZE) or this->x >= (BOX_SIZE - this->rad)){
        this->velX *= -1;
    }

    if (this->onGround() or (this->y + this->rad) >= BOX_SIZE){
        this->velY *= -1;
        this->velY -= accY;
    }
}