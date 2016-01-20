//
// Created by harshil on 21/1/16.
//
#include "Board.h"

void Board::makeBoard() {
    float size = 10, factor = 1;
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -2*(8.0f));

    glColor3f(RGB_RED);
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