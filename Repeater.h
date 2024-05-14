//
// Created by admin on 5/12/2024.
//

#ifndef SFMLTEST_REPEATER_H
#define SFMLTEST_REPEATER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Bullet.h"
#include "Plant.h"
#include "Zombie.h"

using namespace std;
using namespace sf;


class Repeater: public Plant{


    Bullet** bullets;

    Zombie** zombies;

    int currentbullets;

    Clock animationClock;

    Clock fireClock;

    bool fired;

public:

    Repeater(Bullet**& bullets, Zombie**& zombies, int lane, int colnum);

    void idleAnimation(RenderWindow& window);


    virtual void update();

    ~Repeater(){}







};

#endif //SFMLTEST_REPEATER_H
