//
// Created by admin on 5/13/2024.
//
#include "ZombieFactory.h"

ZombieFactory::ZombieFactory(Zombie** zombieArr){

zombie = zombieArr;


}

void ZombieFactory::createZombie() {

    int lane = rand() % 5;

    if (NormalZombieTimer.getElapsedTime().asSeconds() > 100.0f) {

        if (zombie[currentzombie] == nullptr) {

            zombie[currentzombie] = new NormalZombie();

            zombie[currentzombie]->spawn((gridSizeY / 5) * lane + gridLocationY);
            zombie[currentzombie]->setLaneNum(lane);
            currentzombie++;

            NormalZombieTimer.restart();

        }

        if (currentzombie >= 45)
            currentzombie = 0;
    }

    if(FBZombieTimer.getElapsedTime().asSeconds() > 100.f){

        if (zombie[currentzombie] == nullptr) {

            zombie[currentzombie] = new FootballZombie();

            zombie[currentzombie]->spawn((gridSizeY / 5) * lane + gridLocationY);
            zombie[currentzombie]->setLaneNum(lane);
            currentzombie++;

            FBZombieTimer.restart();

        }

        if (currentzombie >= 45)
            currentzombie = 0;

    }
    if(DZTimer.getElapsedTime().asSeconds() > 5.f){
        if (zombie[currentzombie] == nullptr) {

            zombie[currentzombie] = new DancingZombie();

            zombie[currentzombie]->spawn((gridSizeY / 5) * lane + gridLocationY);
            zombie[currentzombie]->setLaneNum(lane);
            currentzombie++;

            DZTimer.restart();

        }

        if (currentzombie >= 45)
            currentzombie = 0;

    }


}

void ZombieFactory::summonZombie(int i){

    int col = (((zombie[i]->getX()*scale - gridLocationX * scale) / (gridSizeX * scale / 9)));
    int row = (((zombie[i]->getY()*scale - gridLocationY * scale) / (gridSizeY * scale / 5)));

    if (zombie[currentzombie] == nullptr) {

        zombie[currentzombie] = new NormalZombie();

        zombie[currentzombie]->spawn((gridSizeY / 5) * row + gridLocationY);

        zombie[currentzombie]->setX((gridSizeX / 9) * col + gridLocationX + (gridSizeX / 9));

        zombie[currentzombie]->setY((gridSizeY / 5) * row + gridLocationY);

        zombie[currentzombie]->setLaneNum(col);
        currentzombie++;

    }

    if (currentzombie >= 45)
        currentzombie = 0;

    if (zombie[currentzombie] == nullptr) {

        zombie[currentzombie] = new NormalZombie();

        zombie[currentzombie]->spawn((gridSizeY / 5) * row + gridLocationY);

        zombie[currentzombie]->setX((gridSizeX / 9) * col + gridLocationX - (gridSizeX / 9));

        zombie[currentzombie]->setY((gridSizeY / 5) * row + gridLocationY);

        zombie[currentzombie]->setLaneNum(col);
        currentzombie++;

    }

    if (currentzombie >= 45)
        currentzombie = 0;

    if (zombie[currentzombie] == nullptr) {

        zombie[currentzombie] = new NormalZombie();

        zombie[currentzombie]->spawn((gridSizeY / 5) * row + gridLocationY);

        zombie[currentzombie]->setX((gridSizeX / 9) * col + gridLocationX);

        zombie[currentzombie]->setY((gridSizeY / 5) * row + gridLocationY + (gridSizeY / 5));

        zombie[currentzombie]->setLaneNum(col);
        currentzombie++;

    }

    if (currentzombie >= 45)
        currentzombie = 0;

    if (zombie[currentzombie] == nullptr) {

        zombie[currentzombie] = new NormalZombie();

        zombie[currentzombie]->spawn((gridSizeY / 5) * row + gridLocationY);

        zombie[currentzombie]->setX((gridSizeX / 9) * col + gridLocationX);

        zombie[currentzombie]->setY((gridSizeY / 5) * row + gridLocationY - (gridSizeY / 5));

        zombie[currentzombie]->setLaneNum(col);
        currentzombie++;

    }

    if (currentzombie >= 45)
        currentzombie = 0;




}