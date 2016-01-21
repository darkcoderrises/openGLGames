//
// Created by harshil on 21/1/16.
//

#include "Bird.h"
#include "DrawHelper.h"
#include "Globals.h"

Bird::Bird() {

}

Bird::~Bird() {

}

void Bird::drawBird() {

    DrawHelper a;
    a.push(0,0);
    a.drawCircle(RGB_BLUE, 2);
    a.pop();

}

