//
// Created by harshil on 24/1/16.
//

#ifndef ANGRYBIRDS_MAP_H
#define ANGRYBIRDS_MAP_H

#include "Globals.h"
#include "Object.h"

class Map {
    public:
        int level, max_level;
        std::vector<float> heigths;
        std::vector<float> breadths;

        Map();
        ~Map();

        void drawRandom();
        bool checkColl(float x, float y, float rad);
        Object setObj();

};


#endif //ANGRYBIRDS_MAP_H
