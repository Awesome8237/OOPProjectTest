//
// Created by admin on 5/6/2024.
//

#ifndef SFMLTEST_CHERRYBOMB_H
#define SFMLTEST_CHERRYBOMB_H

#include <SFML/Graphics.hpp>
#include "Plant.h"
#include "Zombie.h"
using namespace sf;
using namespace std;

class CherryBomb: public Plant{


    Zombie** zombie;

    Clock timer;

    bool dead;

    int frameNumber;
public:

    const Clock &getTimer() const {
        return timer;
    }

    void setTimer(const Clock &timer) {
        CherryBomb::timer = timer;
    }

    bool isExploded() const {
        return exploded;
    }

    void setExploded(bool exploded) {
        CherryBomb::exploded = exploded;
    }

private:

    bool exploded;

public:

    CherryBomb(Zombie** zombies, int lane);

    virtual void update();




    virtual void idleAnimation(RenderWindow& window);





};









#endif //SFMLTEST_CHERRYBOMB_H
