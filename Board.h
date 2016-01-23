//
// Created by harshil on 21/1/16.
//

#ifndef ANGRYBIRDS_BOARD_H
#define ANGRYBIRDS_BOARD_H

#include "Globals.h"
#include "DrawHelper.h"
#include "Cannon.h"
#include "Bird.h"
#include "Blocks.h"
#include "Meters.h"

class Board {
    public:
        Board();
        ~Board();

        Cannon cannon;
        std::vector<Bird> birds;
        std::vector<Blocks> blocks;
        std::vector<Meters> meters;

        void makeBoard();

};


#endif //ANGRYBIRDS_BOARD_H
