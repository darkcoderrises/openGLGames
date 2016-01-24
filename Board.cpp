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
    this->birds.push_back(Bird());
    this->birds.push_back(Bird());

    for (int i=0;i<3;i++)
        this->birds[i].setBird(this->cannon.angle, -BOX_SIZE/2-2 , -BOX_SIZE/2-1);

    this->blocks.push_back(Blocks());

    this->in_progress = false;

    std::vector<float> colors[3];
    fill(colors, RGB_BLUE);
    fill(colors, RGB_TRON_ORANGE);
    fill(colors, RGB_RED);

    std::vector<float> colors1[3];
    fill(colors1, RGB_WHITE);
    fill(colors1, RGB_RED);
    fill(colors1, RGB_BLUE);



    Meters power = Meters();
    power.init( -BOX_SIZE -1, -4, 1, 5, 3, 3, colors);

    Meters life = Meters();
    life.init( BOX_SIZE + 1, -5, 1, 3, 3, 3, colors1);

    this->powerMeter = power;
    this->lives = life;

    this->map = Map();

}

Board::~Board() {

}

void Board::makeBoard() {
    DrawHelper a;

    a.push(0,0);
    a.drawSquare(RGB_LIGHT_GRAY, BOX_SIZE);
    a.pop();

    this->cannon.drawCannon();

    this->map.drawRandom();

    for (int i=0; i<(signed) this->blocks.size(); i++){
        //this->blocks[i].drawBlock();
    }

    bool erase = false;

    for (std::vector<Bird>::iterator it = this->birds.begin();  it != this->birds.end() ; it++){
        if (it->stop) {
            this->in_progress = false;
            erase = true;
            this->lives.decreaseLevel();
            continue;
        }
        if (!it->moving)it->setBird(this->cannon.angle, -BOX_SIZE/2-2 , -BOX_SIZE/2-1);

        std::cout<< this->map.checkColl(this->birds[0].x, this->birds[0].y, this->birds[0].rad) <<std::endl;
        it->checkCollision(this->map);
        it->moveBird();
    }

    if (erase)
        this->birds.erase(this->birds.begin());
    this->powerMeter.drawMeter();
    this->lives.drawMeter();


    if (this->birds.size()>0)
        this->birds[0].drawBird();

}
