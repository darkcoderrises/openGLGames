//
// Created by harshil on 21/1/16.
//

#include "DrawHelper.h"
#include "Globals.h"

void DrawHelper::drawReact(float color1, float color2, float color3, float x, float y) {
    float size = 1, factor = 1;
    glPushMatrix();
    glTranslatef(x, y, -2*(8.0f));

    glColor3f(color1, color2, color3);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);

    glVertex2f(-size / factor, -size / factor);
    glVertex2f(size  / factor, -size / factor);
    glVertex2f(size  / factor, size  / factor);
    glVertex2f(-size / factor, size  / factor);

    glEnd();

    glPopMatrix();
}

void DrawHelper::drawReactEmpty(float color1, float color2, float color3, float x, float y) {
    float size = 1, factor = 1;
    glPushMatrix();
    glTranslatef(x, y, -2*(8.0f));

    glColor3f(color1, color2, color3);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);

    glVertex2f(-size / factor, -size / factor);
    glVertex2f(size  / factor, -size / factor);
    glVertex2f(size  / factor, size  / factor);
    glVertex2f(-size / factor, size  / factor);

    glEnd();

    glPopMatrix();
}

void DrawHelper::drawEllipse(float color1, float color2, float color3, float x, float y, float radx, float rady) {
    glPushMatrix();
    glTranslatef(x, y, -2*(8.0f));
    int i;
    const float DEG2RAD = 0.01745327;

    glColor3f(color1, color2, color3);
    glBegin(GL_LINE_LOOP);

    for(i=0;i<360;i++)
    {
        float rad = i*DEG2RAD;
        glVertex2f((GLfloat) cos(rad)*radx, (GLfloat) sin(rad)*rady);
    }

    glEnd();
    glPopMatrix();
}
