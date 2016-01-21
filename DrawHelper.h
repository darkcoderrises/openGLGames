//
// Created by harshil on 21/1/16.
//

#ifndef ANGRYBIRDS_DRAWHELPER_H
#define ANGRYBIRDS_DRAWHELPER_H


class DrawHelper {
public:
    void drawReact(float color1, float color2, float color3, float size);
    void drawReactEmpty(float color1, float color2, float color3, float size);
    void drawEllipse(float color1, float color2, float color3, float radx, float rady);
    void drawCircle(float color1, float color2, float color3, float rad);

    void push(float x, float y);
    void pop();
};


#endif //ANGRYBIRDS_DRAWHELPER_H
