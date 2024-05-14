//
// Created by admin on 5/13/2024.
//
#include "PlantFactory.h"


PlantFactory::PlantFactory(Plant** plantArr, Bullet*** bulletArr, Sun*** sunArr, Zombie** zombieArr, Time& deltaTime){

plants = plantArr;

bullet = bulletArr;

sun = sunArr;

zombie = zombieArr;

this->deltaTime = deltaTime;

currentplant = 0;
currentshooter = 0;
currentflower = 0;

}

void PlantFactory::createPlant(int i, int j,int iconNum) {

    if (iconNum == 0) {


        bullet[currentshooter] = new Bullet *[10];

        for (int k = 0; k < 10; k++)
            bullet[currentshooter][k] = nullptr;

        plants[currentplant] = new Peashooter(bullet[currentshooter], zombie, i);

        plants[currentplant]->spawn((246 / 9) * j + 5,
                                    (169 / 5) * i + 17);
        currentshooter++;
        currentplant++;

    } else if (iconNum == 1) {


        sun[currentflower] = new Sun *[5];

        for (int k = 0; k < 5; k++)
            sun[currentflower][k] = nullptr;

        plants[currentplant] = new SunFlower(sun[currentflower], i);

        plants[currentplant]->spawn((246 / 9) * j + 5,
                                    (169 / 5) * i + 17);

        currentflower++;
        currentplant++;


    } else if (iconNum == 2) {


        plants[currentplant] = new CherryBomb(zombie, i);

        plants[currentplant]->spawn((246 / 9) * j + 5,
                                    (169 / 5) * i + 17);

        currentplant++;


    } else if (iconNum == 3) {

        plants[currentplant] = new WallNut(zombie, i, deltaTime);

        plants[currentplant]->spawn((246 / 9) * j + 5,
                                    (169 / 5) * i + 17);

        currentplant++;


    } else if (iconNum == 4) {


        bullet[currentshooter] = new Bullet *[10];

        for (int k = 0; k < 10; k++)
            bullet[currentshooter][k] = nullptr;

        plants[currentplant] = new FrozenPeashooter(bullet[currentshooter], zombie, i);

        plants[currentplant]->spawn((246 / 9) * j + 5,
                                    (169 / 5) * i + 17);
        currentshooter++;
        currentplant++;
    } else if (iconNum == 5) {


        bullet[currentshooter] = new Bullet *[10];

        for (int k = 0; k < 10; k++)
            bullet[currentshooter][k] = nullptr;

        plants[currentplant] = new Repeater(bullet[currentshooter], zombie, i);

        plants[currentplant]->spawn((246 / 9) * j + 5,
                                    (169 / 5) * i + 17);
        currentshooter++;
        currentplant++;
    }
}