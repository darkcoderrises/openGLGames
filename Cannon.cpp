//
// Created by harshil on 21/1/16.
//

#include "Cannon.h"
#include "DrawHelper.h"

Cannon::Cannon(){
    this->angle = 30.0f;
}

Cannon::~Cannon(){

}

void Cannon::drawCannon() {
    DrawHelper a;

    a.push(-BOX_SIZE/2-2, -BOX_SIZE/2-1);
    glRotatef(this->angle, 0, 0, 1);

    glColor3f(RGB_RED);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);

    int radius = 1;
    for(int i=98;i>=-98;i--)
    {
        float rad = DEG2RAD(i);
        glVertex2f(-1 * (GLfloat) cos(rad)*radius, (GLfloat) sin(rad)*radius);
    }
    glVertex2f(3.0f, -0.5f);
    glVertex2f(3.0f, 0.5f);

    glEnd();
    a.pop();
}

void Cannon::changeAngle(float change) {
    this->angle += change;
    if (angle>MAX_ANGLE or angle<MIN_ANGLE)
        this->angle -= change;
}
