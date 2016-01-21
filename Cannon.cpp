//
// Created by harshil on 21/1/16.
//

#include "Cannon.h"
#include "DrawHelper.h"

Cannon::Cannon(){
    //std::cerr<<"Cannon gets"<<std::endl;
    this->angle = 1.0f;
    //std::cerr<<this->angle<<std::endl;
}

Cannon::~Cannon(){

}

void Cannon::drawCannon() {
    DrawHelper a;

    a.push(5,0);

    //std::cerr<<this->angle<<std::endl;
    //glRotatef(this->angle, 0, 0, 1);
    a.drawReact(RGB_BLUE, 4);

    a.pop();
}

void Cannon::changeAngle() {
    //std::cerr<<"Change angle "<<this->angle<<std::endl;
    //this->angle += 1.0f;
}