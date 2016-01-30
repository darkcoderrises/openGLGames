//
// Created by harshil on 21/1/16.
//

#include "DrawHelper.h"
#include "Globals.h"

void DrawHelper::drawSquare(float color1, float color2, float color3, float size) {
    glColor3f(color1, color2, color3);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);

    glVertex2f(-size, -size);
    glVertex2f(size, -size);
    glVertex2f(size, size);
    glVertex2f(-size, size);

    glEnd();
}

void DrawHelper::drawRectange(float color1, float color2, float color3, float length, float breadth) {
    glColor3f(color1, color2, color3);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);

    length /= 2;
    breadth /= 2;

    glVertex2f(-length, -breadth);
    glVertex2f(length, -breadth);
    glVertex2f(length, breadth);
    glVertex2f(-length, breadth);

    glEnd();
}

void DrawHelper::drawRectangeEmpty(float color1, float color2, float color3, float length, float breadth) {
    glColor3f(color1, color2, color3);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);

    length /= 2;
    breadth /= 2;

    glVertex2f(-length, -breadth);
    glVertex2f(length, -breadth);
    glVertex2f(length, breadth);
    glVertex2f(-length, breadth);

    glEnd();
}

void DrawHelper::drawEllipse(float color1, float color2, float color3, float radX, float radY) {

    int i;

    glColor3f(color1, color2, color3);
    glBegin(GL_LINE_LOOP);

    for(i=0;i<360;i++)
    {
        float rad = DEG2RAD(i);
        glVertex2f((GLfloat) cos(rad) * radX, (GLfloat) sin(rad) * radY);
    }

    glEnd();

}

void DrawHelper::drawCircle(float color1, float color2, float color3, float rad) {
    this->drawEllipse(color1, color2, color3, rad, rad);
}

void DrawHelper::drawCircleFilled(float color1, float color2, float color3, float rad) {
    float radX = rad, radY = rad;
    int i;

    glColor3f(color1, color2, color3);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);


    for(i=0;i<360;i++)
    {
        float rad = DEG2RAD(i);
        glVertex2f((GLfloat) cos(rad) * radX, (GLfloat) sin(rad) * radY);
    }

    glEnd();
}

void DrawHelper::push(float x, float y){
    glPushMatrix();
    glTranslatef(x, y, -2*(8.0f));
}

void DrawHelper::pop(){
    glPopMatrix();
}
