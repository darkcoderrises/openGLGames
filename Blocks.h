//
// Created by harshil on 23/1/16.
//

#ifndef ANGRYBIRDS_BLOCKS_H
#define ANGRYBIRDS_BLOCKS_H


#include "Object.h"

class Blocks : public Object{
    public:
        Blocks();

        void drawBlock();
        void checkFall();
};

#endif //ANGRYBIRDS_BLOCKS_H
