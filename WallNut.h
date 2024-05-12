//
// Created by admin on 5/11/2024.
//

#ifndef SFMLTEST_WALLNUT_H
#define SFMLTEST_WALLNUT_H

#include <SFML/Graphics.hpp>
#include "Plant.h"
#include "Zombie.h"
using namespace sf;
using namespace std;

class WallNut: public Plant{


    Zombie** zombie;

    Clock animationClock;

    float velocity = 1;

    Time deltaTime;

public:

    WallNut(Zombie** zombies, int lane, Time &deltaTime){

        spritesheet.loadFromFile("Images/wallNut_sheet.png");

        planttexture.loadFromImage(spritesheet);

        plantsprite.setTexture(planttexture);

        plantsprite.setTextureRect(IntRect(0, 94, 28, 30));
        plantsprite.setPosition(100, 100);
        plantsprite.scale(1, 1);

        /*plantsprite.setOrigin(28/2,30/2);*/


        this->zombie = zombies;

        this->deltaTime = deltaTime;

        lanenum = lane;

    }

    virtual void update(){


            for(int i = 0; i < 45; i++){

                if(zombie[i] == nullptr)
                    continue;

                if(x <= zombie[i]->getX() + 42 && x + 28 >= zombie[i]->getX() && y <= zombie[i]->getY() + 40 && y+34 >= zombie[i]->getY())
                    zombie[i]->setHealth(0);

            }



    }

    virtual void idleAnimation(RenderWindow& window) {



        plantsprite.setPosition((x += velocity),y);

        if(animationClock.getElapsedTime().asSeconds() > 0.5f){

            if(plantsprite.getTextureRect().left == 29*7)
                plantsprite.setTextureRect(IntRect(0, 94, 29, 33));
            else
                plantsprite.setTextureRect(IntRect(plantsprite.getTextureRect().left + 29,94,29,33));


            animationClock.restart();

        }


        window.draw(plantsprite);
    }






};





#endif //SFMLTEST_WALLNUT_H
