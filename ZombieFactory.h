//
// Created by admin on 5/12/2024.
//

#ifndef SFMLTEST_ZOMBIEFACTORY_H
#define SFMLTEST_ZOMBIEFACTORY_H
#include "SFML/Graphics.hpp"
#include "Zombie.h"
#include "NormalZombie.h"
#include "FootballZombie.h"
#include "DancingZombie.h"
#include <ctime>


class ZombieFactory{

    Zombie** zombie;

    Clock timer;

    Clock NormalZombieTimer, FBZombieTimer, DZTimer;

    int currentzombie = 0;


public:

    ZombieFactory(Zombie** zombieArr);

    void createZombie();

    void summonZombie(int i);






};

#endif //SFMLTEST_ZOMBIEFACTORY_H
