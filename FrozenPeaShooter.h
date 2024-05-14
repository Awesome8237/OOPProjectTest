//
// Created by admin on 5/12/2024.
//

#ifndef SFMLTEST_FROZENPEASHOOTER_H
#define SFMLTEST_FROZENPEASHOOTER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Bullet.h"
#include "Plant.h"
#include "Zombie.h"

using namespace std;
using namespace sf;


class FrozenPeashooter: public Plant{


    Bullet** bullets;

    Zombie** zombies;

    int currentbullets;

    Clock animationClock;

    Clock fireClock;

public:

    FrozenPeashooter(Bullet**& bullets, Zombie**& zombies, int lane, int colnum);

    void idleAnimation(RenderWindow& window);


    virtual void update();

    ~FrozenPeashooter(){}










};

#endif //SFMLTEST_FROZENPEASHOOTER_H
