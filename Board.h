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
#include "Obstacle.h"

class Board {
    public:
        Board();
        ~Board();

        float zoom;
        float x, y;
        bool in_progress;
        int level;

        Cannon cannon;
        std::vector<Bird> birds;
        std::vector<Blocks> blocks;
        Meters powerMeter;
        Meters lives;
        Map map;
        std::vector<Obstacle> obstacles;

        void makeBoard();
        void handleCollision();
        void handleCollisionBetweenObjects();
        void fireBird();
        void killBird();

};


#endif //ANGRYBIRDS_BOARD_H
