//
// Created by admin on 5/13/2024.
//
#include "ZombieFactory.h"

ZombieFactory::ZombieFactory(Zombie** zombieArr){

zombie = zombieArr;


}

void ZombieFactory::createZombie() {

    int lane = rand() % 5;

    if (NormalZombieTimer.getElapsedTime().asSeconds() > 5.0f) {

        if (zombie[currentzombie] == nullptr) {

            zombie[currentzombie] = new NormalZombie();

            zombie[currentzombie]->spawn((169 / 5) * lane + 17);
            zombie[currentzombie]->setLaneNum(lane);
            currentzombie++;

            NormalZombieTimer.restart();

        }

        if (currentzombie >= 45)
            currentzombie = 0;
    }

    if(FBZombieTimer.getElapsedTime().asSeconds() > 15.f){

        if (zombie[currentzombie] == nullptr) {

            zombie[currentzombie] = new FootballZombie();

            zombie[currentzombie]->spawn((169 / 5) * lane + 17);
            zombie[currentzombie]->setLaneNum(lane);
            currentzombie++;

            FBZombieTimer.restart();

        }

        if (currentzombie >= 45)
            currentzombie = 0;

    }
    if(DZTimer.getElapsedTime().asSeconds() > 20.f){
        if (zombie[currentzombie] == nullptr) {

            zombie[currentzombie] = new DancingZombie();

            zombie[currentzombie]->spawn((169 / 5) * lane + 17);
            zombie[currentzombie]->setLaneNum(lane);
            currentzombie++;

            DZTimer.restart();

        }

        if (currentzombie >= 45)
            currentzombie = 0;

    }


}

void ZombieFactory::summonZombie(int i){

    int col = (((zombie[i]->getX()*scale - 5 * scale) / (246 * scale / 9)));
    int row = (((zombie[i]->getY()*scale - 17 * scale) / (169 * scale / 5)));

    if (zombie[currentzombie] == nullptr) {

        zombie[currentzombie] = new NormalZombie();

        zombie[currentzombie]->spawn((169 / 5) * row + 17);

        zombie[currentzombie]->setX((246 / 9) * col + 5 + (246 / 9));

        zombie[currentzombie]->setY((169 / 5) * row + 17);

        zombie[currentzombie]->setLaneNum(col);
        currentzombie++;

    }

    if (currentzombie >= 45)
        currentzombie = 0;

    if (zombie[currentzombie] == nullptr) {

        zombie[currentzombie] = new NormalZombie();

        zombie[currentzombie]->spawn((169 / 5) * row + 17);

        zombie[currentzombie]->setX((246 / 9) * col + 5 - (246 / 9));

        zombie[currentzombie]->setY((169 / 5) * row + 17);

        zombie[currentzombie]->setLaneNum(col);
        currentzombie++;

    }

    if (currentzombie >= 45)
        currentzombie = 0;

    if (zombie[currentzombie] == nullptr) {

        zombie[currentzombie] = new NormalZombie();

        zombie[currentzombie]->spawn((169 / 5) * row + 17);

        zombie[currentzombie]->setX((246 / 9) * col + 5);

        zombie[currentzombie]->setY((169 / 5) * row + 17 + (169 / 5));

        zombie[currentzombie]->setLaneNum(col);
        currentzombie++;

    }

    if (currentzombie >= 45)
        currentzombie = 0;

    if (zombie[currentzombie] == nullptr) {

        zombie[currentzombie] = new NormalZombie();

        zombie[currentzombie]->spawn((169 / 5) * row + 17);

        zombie[currentzombie]->setX((246 / 9) * col + 5);

        zombie[currentzombie]->setY((169 / 5) * row + 17 - (169 / 5));

        zombie[currentzombie]->setLaneNum(col);
        currentzombie++;

    }

    if (currentzombie >= 45)
        currentzombie = 0;




}