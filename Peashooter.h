//
// Created by admin on 5/1/2024.
//

#ifndef SFMLTEST_PEASHOOTER_H
#define SFMLTEST_PEASHOOTER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Bullet.h"
#include "Plant.h"
#include "Zombie.h"

using namespace std;
using namespace sf;


class Peashooter: public Plant{


    Bullet** bullets;

    Zombie** zombies;

    int currentbullets;

    Clock animationClock;

    Clock fireClock;

public:

    Peashooter(Bullet**& bullets, Zombie**& zombies, int lane, int colnum);

    void idleAnimation(RenderWindow& window);


    virtual void update();


    ~Peashooter(){}






};






#endif //SFMLTEST_PEASHOOTER_H
