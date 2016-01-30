//
// Created by harshil on 26/1/16.
//

#include "Obstacle.h"

float RandomFloat1(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}


Obstacle::Obstacle() {
    this->moveable = true;

    this->velX = 0;
    this->velY = 0;

    this->rad = 0.25;

    this->x = RandomFloat1(0,BOX_SIZE-this->rad);
    this->y = RandomFloat1(-BOX_SIZE+this->rad, BOX_SIZE-this->rad);
}

Obstacle::Obstacle(std::vector<Object> objects) {
    bool made = false;

    this->moveable = true;

    this->velX = 0;
    this->velY = 0;

    this->rad = 0.25;

    while(!made){
        this->x = RandomFloat1(0,BOX_SIZE-this->rad);
        this->y = RandomFloat1(-BOX_SIZE+this->rad, BOX_SIZE-this->rad);

        bool check = false;

        Object ob = Object();
        ob.x = this->x;
        ob.y = this->y;
        ob.rad = this->rad;

        for(int i=0; i<(signed) objects.size(); i++){
            Object object = objects[i];

            if (this->checkCollide(ob, object)){
                check = true;
                break;
            }
        }

        if(check)break;
        made = true;
    }
}

Obstacle::~Obstacle() {

}

void Obstacle::checkWall(){
    this->x += this->velX;
    this->y += this->velY;

    if(this->onGround() or this->y > (BOX_SIZE-this->rad-errorY)){
        this->x -= this->velX;
        this->y -= this->velY;

        this->velY *= -1;
    }

    if(this->x > (BOX_SIZE-this->rad-errorY) or this->x < (-BOX_SIZE+this->rad+errorY)){
        this->x -= this->velX;
        this->y -= this->velY;

        this->velX *= -1;
    }
}

void Obstacle::drawObstacle(){
    DrawHelper a = DrawHelper();
    a.push(this->x, this->y);
    a.drawCircleFilled(RGB_YELLOW, this->rad);
    a.pop();
}

void Obstacle::moveObstacle(){
    this->checkWall();

    this->x += this->velX;
    this->y += this->velY;
}
