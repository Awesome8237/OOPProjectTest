//
// Created by admin on 5/1/2024.
//

#ifndef SFMLTEST_PEASHOOTER_H
#define SFMLTEST_PEASHOOTER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "Bullet.h"

using namespace std;
using namespace sf;


class Peashooter{

public:

    Image spritesheet;
    Texture peashootertexture;
    Sprite peashootersprite;

    Bullet** bullets;

    int currentbullets;

    Clock animationClock;

    Clock fireClock;

    int lanenum;

    float x,y;

    Peashooter(Bullet**& bullets, int lane){

        spritesheet.loadFromFile("Images/shooter_sheet_ds.png");

        peashootertexture.loadFromImage(spritesheet);

        peashootersprite.setTexture(peashootertexture);

        peashootersprite.setTextureRect(IntRect(0,0,27,33));
        peashootersprite.setPosition(100,100);
        peashootersprite.scale(1,1);

        this->bullets = bullets;

        currentbullets = 0;

        lanenum = lane;

        x = 0, y = 0;
    }

    void idleAnimation(RenderWindow& window){

        if(animationClock.getElapsedTime().asSeconds() > 0.1f){

            if(peashootersprite.getTextureRect().left == 189)
                peashootersprite.setTextureRect(IntRect(0,0,27,33));
            else
                peashootersprite.setTextureRect(IntRect(peashootersprite.getTextureRect().left + 27,0,27,33));


            animationClock.restart();

        }

        window.draw(peashootersprite);

    }

    void spawn(int X, int Y){

        x = X;
        y = Y;

        peashootersprite.setPosition(x,y);



    }

    void fire(){

        if(fireClock.getElapsedTime().asSeconds() > 1.0f) {

            if (currentbullets < 10) {
                if (bullets[currentbullets] == nullptr) {
                    bullets[currentbullets] = new Bullet();


                    bullets[currentbullets]->x = this->x + 21;

                    bullets[currentbullets]->y = this->y + 2;

                    bullets[currentbullets]->bulletsprite.setPosition(this->x, this->y);

                    bullets[currentbullets]->velocity = 70;

                    bullets[currentbullets]->exists = true;


                    currentbullets++;


                }
            } else {
                currentbullets = 0;
                if (bullets[currentbullets] == nullptr) {
                    bullets[currentbullets] = new Bullet();

                    bullets[currentbullets]->x = this->x + 21;

                    bullets[currentbullets]->y = this->y + 2;

                    bullets[currentbullets]->bulletsprite.setPosition(this->x, this->y);

                    bullets[currentbullets]->velocity = 70;

                    bullets[currentbullets]->exists = true;

                    currentbullets++;

                }


            }

            fireClock.restart();
        }




    }






};






#endif //SFMLTEST_PEASHOOTER_H
