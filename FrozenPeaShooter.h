//
// Created by admin on 5/12/2024.
//

#ifndef SFMLTEST_FROZENPEASHOOTER_H
#define SFMLTEST_FROZENPEASHOOTER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Bullet.h"
#include "Plant.h"
#include "Zombie.h"

using namespace std;
using namespace sf;


class FrozenPeashooter: public Plant{


    Bullet** bullets;

    Zombie** zombies;

    int currentbullets;

    Clock animationClock;

    Clock fireClock;

public:

    FrozenPeashooter(Bullet**& bullets, Zombie**& zombies, int lane){

        spritesheet.loadFromFile("Images/fps_sheet.png");

        planttexture.loadFromImage(spritesheet);

        plantsprite.setTexture(planttexture);

        plantsprite.setTextureRect(IntRect(0, 0, 30, 32));
        plantsprite.setPosition(100, 100);
        plantsprite.scale(1, 1);

        this->bullets = bullets;

        this->zombies = zombies;

        currentbullets = 0;

        lanenum = lane;

        x = 0, y = 0;
    }

    void idleAnimation(RenderWindow& window){

        if(animationClock.getElapsedTime().asSeconds() > 0.1f){

            if(plantsprite.getTextureRect().left == 30*7)
                plantsprite.setTextureRect(IntRect(0, 0, 30, 32));
            else
                plantsprite.setTextureRect(IntRect(plantsprite.getTextureRect().left + 30, 0, 30, 32));


            animationClock.restart();

        }

        window.draw(plantsprite);

    }


    virtual void update(){

        for(int i = 0; i < 45; i++) {

            if(zombies[i] == nullptr || zombies[i]->getLaneNum() != lanenum)
                continue;

            if (zombies[i]->getX() < gridSizeX) {


                if (fireClock.getElapsedTime().asSeconds() > 1.0f) {

                    if (currentbullets < 10) {
                        if (bullets[currentbullets] == nullptr) {
                            bullets[currentbullets] = new Bullet();


                            bullets[currentbullets]->setX(this->x + 21);

                            bullets[currentbullets]->setY(this->y + 2);



                            bullets[currentbullets]->setVelocity(70);

                            bullets[currentbullets]->setSnow(true);

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

                            bullets[currentbullets]->setSnow(true);

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

#endif //SFMLTEST_FROZENPEASHOOTER_H
