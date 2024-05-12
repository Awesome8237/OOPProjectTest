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

    PlantFactory(Plant** plantArr, Bullet*** bulletArr, Sun*** sunArr, Zombie** zombieArr, Time& deltaTime){

        plants = plantArr;

        bullet = bulletArr;

        sun = sunArr;

        zombie = zombieArr;

        this->deltaTime = deltaTime;

        currentplant = 0;
        currentshooter = 0;
        currentflower = 0;

    }

    void createPlant(int i, int j,int iconNum) {

        if (iconNum == 0) {


            bullet[currentshooter] = new Bullet *[10];

            for (int k = 0; k < 10; k++)
                bullet[currentshooter][k] = nullptr;

            plants[currentplant] = new Peashooter(bullet[currentshooter], zombie, i);

            plants[currentplant]->spawn((gridSizeX / 9) * j + gridLocationX,
                                        (gridSizeY / 5) * i + gridLocationY);
            currentshooter++;
            currentplant++;

        } else if (iconNum == 1) {


            sun[currentflower] = new Sun *[5];

            for (int k = 0; k < 5; k++)
                sun[currentflower][k] = nullptr;

            plants[currentplant] = new SunFlower(sun[currentflower], i);

            plants[currentplant]->spawn((gridSizeX / 9) * j + gridLocationX,
                                        (gridSizeY / 5) * i + gridLocationY);

            currentflower++;
            currentplant++;


        } else if (iconNum == 2) {


            plants[currentplant] = new CherryBomb(zombie, i);

            plants[currentplant]->spawn((gridSizeX / 9) * j + gridLocationX,
                                        (gridSizeY / 5) * i + gridLocationY);

            currentplant++;


        } else if (iconNum == 3) {

            plants[currentplant] = new WallNut(zombie, i, deltaTime);

            plants[currentplant]->spawn((gridSizeX / 9) * j + gridLocationX,
                                        (gridSizeY / 5) * i + gridLocationY);

            currentplant++;


        } else if (iconNum == 4) {


            bullet[currentshooter] = new Bullet *[10];

            for (int k = 0; k < 10; k++)
                bullet[currentshooter][k] = nullptr;

            plants[currentplant] = new FrozenPeashooter(bullet[currentshooter], zombie, i);

            plants[currentplant]->spawn((gridSizeX / 9) * j + gridLocationX,
                                        (gridSizeY / 5) * i + gridLocationY);
            currentshooter++;
            currentplant++;
        } else if (iconNum == 5) {


            bullet[currentshooter] = new Bullet *[10];

            for (int k = 0; k < 10; k++)
                bullet[currentshooter][k] = nullptr;

            plants[currentplant] = new Repeater(bullet[currentshooter], zombie, i);

            plants[currentplant]->spawn((gridSizeX / 9) * j + gridLocationX,
                                        (gridSizeY / 5) * i + gridLocationY);
            currentshooter++;
            currentplant++;
        }
    }


};



#endif //SFMLTEST_PLANTFACTORY_H
