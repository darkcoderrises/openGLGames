//
// Created by harshil on 21/1/16.
//
#include "Board.h"

void fill(std::vector<float> *color, float color1, float color2, float color3){
    color[0].push_back(color1);
    color[1].push_back(color2);
    color[2].push_back(color3);
}

Board::Board() {
    this->cannon = Cannon();
    this->birds.push_back(Bird());
    this->blocks.push_back(Blocks());

    std::vector<float> colors[3];
    fill(colors, RGB_BLUE);
    fill(colors, RGB_TRON_ORANGE);
    fill(colors, RGB_RED);

    Meters power = Meters();
    power.init( -BOX_SIZE -1, -4, 1, 5, 3, 3, colors);
    this->meters.push_back(power);

}

Board::~Board() {

}

void Board::makeBoard() {
    DrawHelper a;

    a.push(0,0);
    a.drawSquare(RGB_LIGHT_GRAY, BOX_SIZE);
    a.pop();

    this->cannon.drawCannon();

    for (int i=0; i<(signed) this->blocks.size(); i++){
        this->blocks[i].drawBlock();
    }

    for (std::vector<Bird>::iterator it = this->birds.begin();  it != this->birds.end() ; it++){
        if (it->onGround()) continue;
        it->checkCollision();
        it->moveBird();
    }

    for (int i=0; i<(signed) this->meters.size(); i++){
        this->meters[i].drawMeter();
    }

    this->birds[0].drawBird();
}
