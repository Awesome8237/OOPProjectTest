//
// Created by admin on 5/10/2024.
//

#ifndef SFMLTEST_PLANT_H
#define SFMLTEST_PLANT_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Plant{
protected:
    Image spritesheet;
    Texture planttexture;
    Sprite plantsprite;

    int lanenum;

    bool bomb;
public:
    bool isBomb() const;

    void setBomb(bool bomb);

protected:

    float x,y;
public:
    int getLanenum() const {
        return lanenum;
    }

    void setLanenum(int lanenum) {
        Plant::lanenum = lanenum;
    }

    float getX() const {
        return x;
    }

    void setX(float x) {
        Plant::x = x;
    }

    float getY() const {
        return y;
    }

    void setY(float y) {
        Plant::y = y;
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int health) {
        Plant::health = health;
    }

protected:

    int health;

public:
    void spawn(int X, int Y);

    virtual void update() = 0;
    virtual void idleAnimation(RenderWindow& window) = 0;



};


#endif //SFMLTEST_PLANT_H
