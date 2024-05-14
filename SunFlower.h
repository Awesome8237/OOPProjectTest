//
// Created by admin on 5/10/2024.
//

#ifndef SFMLTEST_SUNFLOWER_H
#define SFMLTEST_SUNFLOWER_H
#include <SFML/Graphics.hpp>
#include "Plant.h"
#include "Sun.h"

class SunFlower: public Plant{



    Sun** suns;

    int currentsuns;

    Clock animationClock;

    Clock generationClock;

public:

    SunFlower(Sun** suns,int lane, int colnum);

    void idleAnimation(RenderWindow& window);

    void virtual update();

    ~SunFlower(){}






};




#endif //SFMLTEST_SUNFLOWER_H
