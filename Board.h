//
// Created by harshil on 21/1/16.
//

#ifndef ANGRYBIRDS_BOARD_H
#define ANGRYBIRDS_BOARD_H

#include "Globals.h"
#include "Cannon.h"

class Board {
    public:
        Board();
        ~Board();

        Cannon cannon;

        void init();
        void makeBoard();

};


#endif //ANGRYBIRDS_BOARD_H
