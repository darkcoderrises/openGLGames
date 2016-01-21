//
// Created by harshil on 21/1/16.
//

#include "DrawHelper.h"
#include "Globals.h"

void DrawHelper::drawReact(float color1, float color2, float color3, float size) {
    glColor3f(color1, color2, color3);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);

    glVertex2f(-size, -size);
    glVertex2f(size, -size);
    glVertex2f(size, size);
    glVertex2f(-size, size);

    glEnd();
}

void DrawHelper::drawReactEmpty(float color1, float color2, float color3, float size) {
    glColor3f(color1, color2, color3);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);

    glVertex2f(-size, -size);
    glVertex2f(size, -size);
    glVertex2f(size, size);
    glVertex2f(-size, size);

    glEnd();

}

void DrawHelper::drawEllipse(float color1, float color2, float color3, float radx, float rady) {

    int i;

    glColor3f(color1, color2, color3);
    glBegin(GL_LINE_LOOP);

    for(i=0;i<360;i++)
    {
        float rad = DEG2RAD(i);
        glVertex2f((GLfloat) cos(rad)*radx, (GLfloat) sin(rad)*rady);
    }

    glEnd();

}

void DrawHelper::drawCircle(float color1, float color2, float color3, float rad) {
    this->drawEllipse(color1, color2, color3, rad, rad);
}

void DrawHelper::push(float x, float y){
    glPushMatrix();
    glTranslatef(x, y, -2*(8.0f));
}

void DrawHelper::pop(){
    glPopMatrix();
}
