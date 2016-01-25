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
#include "Map.h"

class Board {
    public:
        Board();
        ~Board();

        float zoom;
        bool in_progress;

        Cannon cannon;
        std::vector<Bird> birds;
        std::vector<Blocks> blocks;
        Meters powerMeter;
        Meters lives;
        Map map;

        void makeBoard();

};


#endif //ANGRYBIRDS_BOARD_H
