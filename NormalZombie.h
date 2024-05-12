//
// Created by admin on 4/30/2024.
//

#ifndef SFMLTEST_NORMALZOMBIE_H
#define SFMLTEST_NORMALZOMBIE_H

#include <SFML/Graphics.hpp>
#include "Zombie.h"

using namespace sf;
using namespace std;

/*const int scale = 3;

const int windowSizeX = 256;
const int windowSizeY = 192;
const int gridSizeX = 246;
const int gridSizeY = 169;
const int windowLocationX = 71;
const int windowLocationY = 2;
const int gridLocationX = 5;
const int gridLocationY = 17;*/

class NormalZombie: public Zombie{


    Clock animationClock;
    bool clockEnabled;


public:
    NormalZombie();


    virtual void moveZombie(RenderWindow& window,Time &ZombTime);



    virtual void eatingAnimation(RenderWindow& window);

    /*bool isOutside(){

        if(x > windowSizeX){
            return true;
        }
        else{
            return false;
        }


    }*/

    virtual void spawn(int y);

    ~NormalZombie(){}

};

#endif //SFMLTEST_NORMALZOMBIE_H
