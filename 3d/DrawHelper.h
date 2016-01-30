//
// Created by harshil on 21/1/16.
//

#ifndef ANGRYBIRDS_DRAWHELPER_H
#define ANGRYBIRDS_DRAWHELPER_H


class DrawHelper {
public:
    void drawSquare(float color1, float color2, float color3, float size);
    void drawRectange(float color1, float color2, float color3, float length, float breadth);
    void drawRectangeEmpty(float color1, float color2, float color3, float length, float breadth);
    void drawEllipse(float color1, float color2, float color3, float radX, float radY);
    void drawCircleEmpty(float color1, float color2, float color3, float rad);
    void drawCircle(float color1, float color2, float color3, float rad);

    void drawCuboid(float color[][3], float l, float b, float h);
    void drawCube(float color[][3], float size);

    void push(float x, float y);
    void pop();
};


#endif //ANGRYBIRDS_DRAWHELPER_H
