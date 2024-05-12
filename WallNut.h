//
// Created by admin on 5/11/2024.
//

#ifndef SFMLTEST_WALLNUT_H
#define SFMLTEST_WALLNUT_H

#include <SFML/Graphics.hpp>
#include "Plant.h"
#include "Zombie.h"
using namespace sf;
using namespace std;

class WallNut: public Plant{


    Zombie** zombie;

    Clock animationClock;

    float velocity = 1;

    Time deltaTime;

public:

    WallNut(Zombie** zombies, int lane, Time &deltaTime);

    virtual void update();

    virtual void idleAnimation(RenderWindow& window) ;






};





#endif //SFMLTEST_WALLNUT_H
