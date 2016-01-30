//
// Created by harshil on 30/1/16.
//

#include "Board.h"
#include "DrawHelper.h"

Board::Board() {
    this->x = -3;
    this->y = -3;

    for (int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cells[i][j] = Cell();
            cells[i][j].x =i*(float)2.1;
            cells[i][j].y =j*(float)2.1;

            cells[i][j].l=2;
            cells[i][j].b=2;
            cells[i][j].h=2;
        }
    }
}

Board::~Board() {

}

void Board::drawBoard() {
    DrawHelper a = DrawHelper();
    a.push(0,0);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cells[i][j].drawCell();
        }
    }
    a.pop();
}