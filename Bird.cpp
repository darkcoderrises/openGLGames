//
// Created by harshil on 21/1/16.
//

#include "Bird.h"
#include "DrawHelper.h"

Bird::Bird() {
    this->x=0;
    this->y=0;
    this->rad=0.5;

    this->velX = 0.05;
    this->velY = 0.05;

    this->moving = false;
    this->stop = false;

    this->moveable = true;
}

Bird::~Bird() {

}

void Bird::setBird(float angle, float x, float y) {
    this->x = (float) (4 * cos(DEG2RAD(angle)) + x);
    this->y = (float) (4 * sin(DEG2RAD(angle)) + y);
}

void Bird::drawBird() {

    DrawHelper a;
    a.push(this->x, this->y);
    a.drawCircle(RGB_BLUE, 0.5);
    a.pop();
}

void Bird::moveBird() {
    if (not this->moving)
        return;

    this->x += this->velX;
    this->y += this->velY;

    this->velY -= accY;

    if (this->velY<0) this->velY+=2*frictionY; this->velY-=frictionY;
    if (this->velX<0) this->velX+=2*frictionX; this->velX-=frictionX;

    if ( fabs(this->velX) < 0.0001  and this->onGround()) {this->stop = true;}
}

class vec2 {
public:
    float x,y;
};

float length_squared1(vec2 w, vec2 p){
    return ( (w.x-p.x)*(w.x-p.x) + (w.y-p.y)*(w.y-p.y) );
}

float distance1(vec2 w, vec2 p){
    return (float) sqrt(length_squared1(w, p));
}


void Bird::checkCollision(Map map) {
    if (this->x <= (0.5-BOX_SIZE) or this->x >= (BOX_SIZE-0.5)){
        this->velX *= -1;
    }

    if (this->onGround() or (this->y + this->rad) >= BOX_SIZE){
        this->velY *= -1;
        this->velY -= accY;
    }

    if (map.checkColl(this->x + this->velX, this->y + this->velY , this->rad)){
        bool check = false;

        for (int i=0;i<4;i++){
            vec2 a,b;
            b.x = this->x, b.y = this->y;
            a.x = map.breadths[i], a.y = map.heigths[i];

            if (distance1(a, b) <= this->rad)
                check = true;
        }


        velY *= -1;
        if (check) velX *= -1;

    }
}