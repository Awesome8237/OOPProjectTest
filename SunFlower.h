//
// Created by admin on 5/10/2024.
//

#ifndef SFMLTEST_SUNFLOWER_H
#define SFMLTEST_SUNFLOWER_H
#include <SFML/Graphics.hpp>
#include "Plant.h"
#include "Sun.h"

class SunFlower: public Plant{



    Sun** suns;

    int currentsuns;

    Clock animationClock;

    Clock generationClock;

public:

    SunFlower(Sun** suns,int lane){

        spritesheet.loadFromFile("Images/sunflower_sheet.png");

        planttexture.loadFromImage(spritesheet);

        plantsprite.setTexture(planttexture);

        plantsprite.setTextureRect(IntRect(100, 37, 30, 40));
        plantsprite.setPosition(100, 100);
        plantsprite.scale(1, 1);

        this->suns = suns;

        currentsuns = 0;

        lanenum = lane;

        x = 0, y = 0;
    }

    void idleAnimation(RenderWindow& window){

        if(animationClock.getElapsedTime().asSeconds() > 0.2f){

            if(plantsprite.getTextureRect().left == 250)
                plantsprite.setTextureRect(IntRect(100, 37, 30, 40));
            else
                plantsprite.setTextureRect(IntRect(plantsprite.getTextureRect().left + 30, 37, 30, 40));


            animationClock.restart();

        }

        window.draw(plantsprite);

    }

    void virtual update(){

        if(generationClock.getElapsedTime().asSeconds() > 3.0f) {

            if (currentsuns < 5) {
                if (suns[currentsuns] == nullptr) {
                    suns[currentsuns] = new Sun();


                    suns[currentsuns]->setX(this->x - 10);

                    suns[currentsuns]->setY(this->y) ;

                   // suns[currentsuns]->sunsprite.setPosition(suns[currentsuns]->x, suns[currentsuns]->y);


                    currentsuns++;


                }
            } else {
                currentsuns = 0;
                if (suns[currentsuns] == nullptr) {
                    suns[currentsuns] = new Sun();

                    suns[currentsuns]->setX(this->x - 10);

                    suns[currentsuns]->setY(this->y) ;

                   // suns[currentsuns]->sunsprite.setPosition(suns[currentsuns]->x, suns[currentsuns]->y);


                    currentsuns++;

                }


            }

            generationClock.restart();
        }




    }







};




#endif //SFMLTEST_SUNFLOWER_H
