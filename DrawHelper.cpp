//
// Created by harshil on 21/1/16.
//

#include "DrawHelper.h"
#include "Globals.h"

void DrawHelper::drawReact(float color1, float color2, float color3) {
    float size = 10, factor = 1;
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);

    glColor3f(color1, color2, color3);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_QUADS);

    glVertex2f(-size / factor, -size / factor);
    glVertex2f(size  / factor, -size / factor);
    glVertex2f(size  / factor, size  / factor);
    glVertex2f(-size / factor, size  / factor);

    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glPopMatrix();
}

