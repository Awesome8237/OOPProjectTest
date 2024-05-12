//
// Created by admin on 5/12/2024.
//

#ifndef SFMLTEST_PLANTFACTORY_H
#define SFMLTEST_PLANTFACTORY_H
#include "Plant.h"
#include "Bullet.h"
#include "Sun.h"
#include "Zombie.h"
#include "Peashooter.h"
#include "SunFlower.h"
#include "WallNut.h"
#include "CherryBomb.h"
#include "Repeater.h"
#include "FrozenPeaShooter.h"

class PlantFactory{

    Plant** plants;

    //bool** Grid;

    Bullet*** bullet;

    Zombie** zombie;

    Sun*** sun;

    Time deltaTime;

    int currentplant;
    int currentshooter;
    int currentflower;

public:

    PlantFactory(Plant** plantArr, Bullet*** bulletArr, Sun*** sunArr, Zombie** zombieArr, Time& deltaTime);

    void createPlant(int i, int j,int iconNum);

};



#endif //SFMLTEST_PLANTFACTORY_H
