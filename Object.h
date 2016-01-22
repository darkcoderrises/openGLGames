//
// Created by harshil on 22/1/16.
//

#ifndef ANGRYBIRDS_OBJECT_H
#define ANGRYBIRDS_OBJECT_H


class Object {
    public:
        Object();
        ~Object();

        float x, y, rad;
        bool moveable;

        bool onGround();
};


#endif //ANGRYBIRDS_OBJECT_H
