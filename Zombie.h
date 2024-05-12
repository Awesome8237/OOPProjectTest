//
// Created by admin on 5/6/2024.
//

#ifndef SFMLTEST_ZOMBIE_H
#define SFMLTEST_ZOMBIE_H
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const int scale = 3;

const int windowSizeX = 256;
const int windowSizeY = 192;
const int gridSizeX = 246;
const int gridSizeY = 169;
const int windowLocationX = 71;
const int windowLocationY = 2;
const int gridLocationX = 5;
const int gridLocationY = 17;

class Zombie{


protected:
    Image zombspritesheet;
    Texture zombtexture;
    Sprite zombsprite;

    bool dancing;

    bool summonTimeup;
public:
    bool isSummonTimeup() const {
        return summonTimeup;
    }

    void setSummonTimeup(bool summonTimeup) {
        Zombie::summonTimeup = summonTimeup;
    }


public:
    bool isDancing() const {
        return dancing;
    }

    void setDancing(bool d) {
        Zombie::dancing = d;
    }

protected:

    float velocity;

public:
    bool isSlowed() const {
        return slowed;
    }

    void setSlowed(bool slowed) {
        Zombie::slowed = slowed;
    }

protected:
    bool slowed;

    Clock slowClock;
public:
    float getVelocity() const {
        return velocity;
    }

    void setVelocity(float velocity) {
        Zombie::velocity = velocity;
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int health) {
        Zombie::health = health;
    }

    int getLaneNum() const {
        return laneNum;
    }

    void setLaneNum(int laneNum) {
        Zombie::laneNum = laneNum;
    }

    float getX() const {
        return x;
    }

    void setX(float x) {
        Zombie::x = x;
    }

    float getY() const {
        return y;
    }

    void setY(float y) {
        Zombie::y = y;
    }

protected:

    int health;

    int laneNum;

    float x,y;

public:

    virtual void moveZombie(RenderWindow& window,Time &ZombTime) = 0;
    virtual void spawn(int y) = 0;
    virtual void eatingAnimation(RenderWindow& window) = 0;



    bool isOutside(){

        if(x > windowSizeX){
            return true;
        }
        else{
            return false;
        }


    }

    virtual ~Zombie(){}










};

#endif //SFMLTEST_ZOMBIE_H
