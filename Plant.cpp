//
// Created by admin on 5/13/2024.
//
#include "Plant.h"

void Plant::spawn(int X, int Y){

    x = X;
    y = Y;

    plantsprite.setPosition(x, y);

}

bool Plant::isBomb() const {
    return bomb;
}

void Plant::setBomb(bool bomb) {
    Plant::bomb = bomb;
}

int Plant::getColnum() const {
    return colnum;
}

void Plant::setColnum(int colnum) {
    Plant::colnum = colnum;
}
