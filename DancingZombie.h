//
// Created by admin on 5/5/2024.
//

#ifndef SFMLTEST_DANCINGZOMBIE_H
#define SFMLTEST_DANCINGZOMBIE_H
#include "Zombie.h"
#include <iostream>
using namespace std;
class DancingZombie: public Zombie{

    Clock animationClock;

    Clock summonClock;

    float y_velocity;

public:

    DancingZombie();
    virtual void moveZombie(RenderWindow& window,Time &ZombTime) ;

    virtual void eatingAnimation(RenderWindow& window);

    virtual void spawn(int y);



};




#endif //SFMLTEST_DANCINGZOMBIE_H
