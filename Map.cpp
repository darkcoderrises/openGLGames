//
// Created by harshil on 24/1/16.
//

#include "Map.h"
#include "DrawHelper.h"
#include <algorithm>

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

Map::Map(){
    this->max_level = 12;
    this->level = rand() % (max_level/3) + 1;

    float l = 2 * BOX_SIZE / this->max_level;
    srand(time(NULL));
    for (int i=0; i<4; i++){
        this->heigths.push_back(RandomFloat(l*(3*i+1), l*(3*i+2)) - BOX_SIZE);
    }

    std::sort(this->heigths.begin(), this->heigths.end());

    for (int i=0; i<4; i++){
        this->breadths.push_back(RandomFloat(0, BOX_SIZE/2));
    }

};

Map::~Map(){

}
class vec2 {
    public:
        float x,y;
};

bool Map::checkColl(float x, float y, float rad) {
    /*vec2 p=vec2(), v=vec2(), w=vec2();
    p.x = x, p.y = y;
    for (int yy=0;yy<4;yy++){
        v.y = this->heigths[yy];
        v.x = BOX_SIZE - this->breadths[yy];

        w.y = this->heigths[yy];
        w.y = BOX_SIZE;

        if(minimum_distance(v, w, p) <= rad)return true;
    }

    return false;*/

    bool check = false;
    for(int i=0; i<4; i++){
        float Y = this->heigths[i];
        float X = this->breadths[i];

        if(y+rad >= (Y+0.5) and y < (Y+0.5)){
            if(x+rad >= X){
                check = true;
            }
        }

        if(y-rad <= (Y-0.5) and y > (Y-0.5)){
            if(x+rad >= X){
                check = true;
            }
        }

    }
    return check;

}

void Map::drawRandom() {
    DrawHelper a;
    for(int i=0; i<4; i++){
        a.push((BOX_SIZE + this->breadths[i])/2, this->heigths[i]);
        a.drawRectange(RGB_BLUE, BOX_SIZE - this->breadths[i], 0.5);
        a.pop();
    }
}

Object Map::setObj() {
    Object a = Object();
    srand(time(NULL));
    int hi = rand()%3;
    a.y = this->heigths[hi] + (float)1.26;
    a.x = RandomFloat(this->breadths[hi] + 1, BOX_SIZE -1);

    a.rad=1;
    return a;
}