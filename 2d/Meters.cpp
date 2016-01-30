//
// Created by harshil on 23/1/16.
//

#include "Meters.h"
#include "DrawHelper.h"

Meters::Meters() {
    this->initialised = false;
}

Meters::~Meters() {

}

bool Meters::init() {
    return this->initialised ;
}

void Meters::init(float x, float y, float length, float breadth, int level, int currLevel,
                  std::vector<float> *colorLevel) {

    this->setBreadth(breadth);
    this->setLength(length);
    this->setPos(x, y);
    this->setLevels(level);
    this->setCurrLevel(currLevel);
    this->setColorLevel(colorLevel);

    this->initialised = true;
}

void Meters::setBreadth(float breadth) {
    this->breadth = breadth;
}

void Meters::setLength(float length) {
    this->length = length;
}

void Meters::setColorLevel(std::vector<float> *colorLevel) {
    for (int i=0; i<3; i++){
        this->colorLevel[i] = colorLevel[i];
    }
}

void Meters::setLevels(int level) {
    this->levels = level;
}

void Meters::setCurrLevel(int level) {
    this->currLevel = level;
}

void Meters::setPos(float x, float y) {
    this->x = x, this->y =y ;
}

void Meters::decreaseLevel() {
    if (this->currLevel == 0) return;
    this->currLevel--;
}

void Meters::increaseLevel() {
    if (this->currLevel == this->levels) return;
    this->currLevel++;
}

void Meters::drawMeter() {
    if (!this->init()) return;

    float color1 = this->colorLevel[0][this->currLevel-1],
        color2 = this->colorLevel[1][this->currLevel-1],
        color3 = this->colorLevel[2][this->currLevel-1];

    DrawHelper a;
    a.push(this->x, this->y);
    a.drawRectangeEmpty(1, 1, 1, this->length, this->breadth);
    a.pop();

    a.push(this->x, this->y - (this->breadth * (this->levels - this->currLevel) / (2 * this->levels)));
    a.drawRectange(color1, color2, color3, this->length, this->breadth*this->currLevel/this->levels);
    a.pop();
}