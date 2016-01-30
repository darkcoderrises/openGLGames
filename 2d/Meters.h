//
// Created by harshil on 23/1/16.
//

#ifndef ANGRYBIRDS_METERS_H
#define ANGRYBIRDS_METERS_H

#include "Globals.h"

class Meters {
    private:
        bool initialised;

    public:
        Meters();
        ~Meters();

        float length, breadth, x, y;
        int levels, currLevel;
        std::vector<float> colorLevel[3];

        bool init();
        void init(float x, float y, float length, float breadth, int level, int currLevel, std::vector<float> colorLevel[3]);
        void setPos(float x, float y);
        void setLength(float length);
        void setBreadth(float breadth);
        void setLevels(int level);
        void setCurrLevel(int level);
        void setColorLevel(std::vector<float> colorLevel[3]);

        void drawMeter();
        void decreaseLevel();
        void increaseLevel();

};


#endif //ANGRYBIRDS_METERS_H
