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

    for (int i=0;i<3;i++) {
        this->birds.push_back(Bird());
        this->birds[i].setBird(this->cannon.angle, -BOX_SIZE / 2 - 2, -BOX_SIZE / 2 - 1);
    }

    for(int i=0;i<5;i++){
        this->obstacles.push_back(Obstacle());
    }

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
    this->blocks.push_back(Blocks(this->map.setObj()));

    this->zoom = 7;
    this->x = 0;
    this->y = 0;
    this->level = 1;
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
        this->blocks[i].drawBlock();
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

        //std::cout<< this->map.checkColl(this->birds[0].x, this->birds[0].y, this->birds[0].rad) <<std::endl;
        it->checkCollision(this->map);
        it->moveBird();
    }

    if (erase)
        this->birds.erase(this->birds.begin());

    this->powerMeter.drawMeter();
    this->lives.drawMeter();

    for(int i=0;i<(signed) this->obstacles.size();i++){
        this->obstacles[i].moveObstacle();
        this->obstacles[i].drawObstacle();
    }

    if (this->birds.size()>0)
        this->birds[0].drawBird();

}

float dist(float x1, float y1, float x2, float y2){
    return ((float) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}

void Board::handleCollisionBetweenObjects() {
    int size = (signed) this->obstacles.size();
    for(int i=0;i<size; i++){
        Obstacle o1 = this->obstacles[i];

        if (this->birds[0].moving and !this->birds[0].stop) {
            Bird b1 = this->birds[0];
            if (dist(o1.x, o1.y, b1.x, b1.y) <= (o1.rad + b1.rad)) {
                o1.velX = (o1.velX * 2 + b1.velX) / 3;
                b1.velX = o1.velX;

                o1.velY = (o1.velY * 2 + b1.velY) / 3;
                b1.velY = o1.velY;
            }
            this->birds[0] = b1;
        }

        for(int j=i+1;j<size;j++){
            Obstacle o2=this->obstacles[j];
            if (dist(o1.x, o1.y, o2.x, o2.y)<=(o1.rad+o2.rad)){
                float velx, vely;
                velx = o1.velX;
                vely = o1.velY;

                o1.velX = o2.velX;
                o1.velY = o2.velY;

                o2.velX = velx;
                o2.velY = vely;
            }
            this->obstacles[j] = o2;

        }
        this->obstacles[i] = o1;
    }
}

void Board::handleCollision() {
    if(this->birds.size()==0)return;
    Blocks block = this->blocks[0];
    Bird bird = this->birds[0];

    if(dist(bird.x, bird.y, block.x, block.y) <= (bird.rad + block.rad)){
        this->level+=1;
        this->map = Map();
        this->birds[0] = Bird();
        this->blocks[0] = Blocks(this->map.setObj());
        this->obstacles.push_back(Obstacle());
        this->in_progress = false;
    }
    this->handleCollisionBetweenObjects();
}

void Board::fireBird() {
    if (this->in_progress) return;

    if (this->birds.size()>0) {
        this->birds[0].setBird(this->cannon.angle, -BOX_SIZE/2-2 , -BOX_SIZE/2-1);
        this->birds[0].moving = true;
        this->in_progress = true;

        this->birds[0].velX *= this->powerMeter.currLevel * this->powerMeter.currLevel * cos(DEG2RAD(this->cannon.angle));
        this->birds[0].velY *= this->powerMeter.currLevel * this->powerMeter.currLevel * sin(DEG2RAD(this->cannon.angle));
    }
}

void Board::killBird(){
    if (this->birds.size()==0)return;
    this->in_progress = false;
    this->birds.erase(this->birds.begin());
    this->lives.decreaseLevel();
}