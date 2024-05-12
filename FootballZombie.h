//
// Created by admin on 5/12/2024.
//

#ifndef SFMLTEST_FOOTBALLZOMBIE_H
#define SFMLTEST_FOOTBALLZOMBIE_H
#include "Zombie.h"
#include "SFML/Graphics.hpp"
#include <ctime>

class FootballZombie: public Zombie{

    Clock animationClock;

    Clock upDownClock;

    bool clockEnabled;

public:
    FootballZombie();

    virtual void eatingAnimation(RenderWindow& window);

    virtual void moveZombie(RenderWindow& window,Time &ZombTime);

    virtual void spawn(int y);





};



#endif //SFMLTEST_FOOTBALLZOMBIE_H
