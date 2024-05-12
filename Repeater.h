//
// Created by admin on 5/12/2024.
//

#ifndef SFMLTEST_REPEATER_H
#define SFMLTEST_REPEATER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Bullet.h"
#include "Plant.h"
#include "Zombie.h"

using namespace std;
using namespace sf;


class Repeater: public Plant{


    Bullet** bullets;

    Zombie** zombies;

    int currentbullets;

    Clock animationClock;

    Clock fireClock;

    bool fired;

public:

    Repeater(Bullet**& bullets, Zombie**& zombies, int lane){

        spritesheet.loadFromFile("Images/repeater_sheet.png");

        planttexture.loadFromImage(spritesheet);

        plantsprite.setTexture(planttexture);

        plantsprite.setTextureRect(IntRect(0, 0, 34, 36));
        plantsprite.setPosition(100, 100);
        plantsprite.scale(1, 1);

        this->bullets = bullets;

        this->zombies = zombies;

        currentbullets = 0;

        lanenum = lane;

        x = 0, y = 0;

        fired = false;
    }

    void idleAnimation(RenderWindow& window){

        if(animationClock.getElapsedTime().asSeconds() > 0.2f){

            if(plantsprite.getTextureRect().left == 36*4)
                plantsprite.setTextureRect(IntRect(0, 0, 34, 35));
            else
                plantsprite.setTextureRect(IntRect(plantsprite.getTextureRect().left + 36, 0, 34, 35));


            animationClock.restart();

        }

        window.draw(plantsprite);

    }


    virtual void update(){

        for(int i = 0; i < 45; i++) {

            if(zombies[i] == nullptr || zombies[i]->getLaneNum() != lanenum)
                continue;

            if (zombies[i]->getX() < gridSizeX) {


                if (fireClock.getElapsedTime().asSeconds() > 0.5f) {

                    if (currentbullets < 10) {
                        if (bullets[currentbullets] == nullptr) {
                            bullets[currentbullets] = new Bullet();


                            bullets[currentbullets]->setX(this->x + 21);

                            bullets[currentbullets]->setY(this->y + 2);


                            bullets[currentbullets]->setVelocity(70);

                            bullets[currentbullets]->setExists(true);


                            currentbullets++;


                        }
                    } else {
                        currentbullets = 0;
                        if (bullets[currentbullets] == nullptr) {
                            bullets[currentbullets] = new Bullet();

                            bullets[currentbullets]->setX(this->x + 21);

                            bullets[currentbullets]->setY(this->y + 2);

                            bullets[currentbullets]->setVelocity(70);

                            bullets[currentbullets]->setExists(true);

                            currentbullets++;

                        }


                    }

                    fireClock.restart();
                }
            }
        }



    }








};

#endif //SFMLTEST_REPEATER_H