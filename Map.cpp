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

float length_squared(vec2 w, vec2 p){
    return ( (w.x-p.x)*(w.x-p.x) + (w.y-p.y)*(w.y-p.y) );
}

float distance(vec2 w, vec2 p){
    return (float) sqrt(length_squared(w, p));
}

float dot(vec2 w, vec2 p){
    return w.x*p.x + w.y*p.y;
}

vec2 mul(float t, vec2 w){
    w.x *= t;
    w.y *= t;

    return w;
}

vec2 add(vec2 w, vec2 p){
    vec2 a;
    a.x = w.x + p.x;
    a.y = w.y + p.y;

    return a;
}

vec2 sub(vec2 w, vec2 p){
    vec2 a = vec2();
    a.x = w.x - p.x;
    a.y = w.y - p.y;

    return a;
}

float minimum_distance(vec2 v, vec2 w, vec2 p) {
    // Return minimum distance between line segment vw and point p
    const float l2 = length_squared(v, w);  // i.e. |w-v|^2 -  avoid a sqrt
    if (l2 == 0.0) return distance(p, v);   // v == w case
    // Consider the line extending the segment, parameterized as v + t (w - v).
    // We find projection of point p onto the line.
    // It falls where t = [(p-v) . (w-v)] / |w-v|^2
    const float t = dot(sub(p,v), sub(w,v)) / l2;
    if (t < 0.0) return distance(p, v);       // Beyond the 'v' end of the segment
    else if (t > 1.0) return distance(p, w);  // Beyond the 'w' end of the segment
    const vec2 projection = add(v, mul(t, sub(w, v)));  // Projection falls on the segment
    return distance(p, projection);
}


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

    return a;
}