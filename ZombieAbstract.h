//
// Created by admin on 5/6/2024.
//

#ifndef SFMLTEST_ZOMBIEABSTRACT_H
#define SFMLTEST_ZOMBIEABSTRACT_H
#include <SFML/Graphics.hpp>
#include "Zombie.h"
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

class ZombieAbstract{

public:

    Image zombspritesheet;
    Texture zombtexture;
    Sprite zombsprite;

    float velocity;

    int health;

    float x,y;

public:

    virtual void moveZombie(RenderWindow& window,Time &ZombTime) = 0;
    virtual void spawn(int y) = 0;

    bool isOutside(){

        if(x > windowSizeX){
            return true;
        }
        else{
            return false;
        }


    }







};

#endif //SFMLTEST_ZOMBIEABSTRACT_H
