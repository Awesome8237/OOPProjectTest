//
// Created by admin on 5/13/2024.
//

#include "WallNut.h"

WallNut::WallNut(Zombie** zombies, int lane, Time &deltaTime, int colnum){

spritesheet.loadFromFile("Images/wallNut_sheet.png");

planttexture.loadFromImage(spritesheet);

plantsprite.setTexture(planttexture);

plantsprite.setTextureRect(IntRect(0, 94, 28, 30));
plantsprite.setPosition(100, 100);
plantsprite.scale(1, 1);

/*plantsprite.setOrigin(28/2,30/2);*/

    this->colnum = colnum;

this->zombie = zombies;

this->deltaTime = deltaTime;

    health = 100;

    bomb = false;

lanenum = lane;

}

void WallNut::update(){


    for(int i = 0; i < 45; i++){

        if(zombie[i] == nullptr)
            continue;

        if(x <= zombie[i]->getX() + 42 && x + 28 >= zombie[i]->getX() && y <= zombie[i]->getY() + 40 && y+34 >= zombie[i]->getY())
            zombie[i]->setHealth(0);

    }



}

void WallNut::idleAnimation(RenderWindow& window) {



    plantsprite.setPosition((x += velocity),y);

    if(animationClock.getElapsedTime().asSeconds() > 0.5f){

        if(plantsprite.getTextureRect().left == 29*7)
            plantsprite.setTextureRect(IntRect(0, 94, 29, 33));
        else
            plantsprite.setTextureRect(IntRect(plantsprite.getTextureRect().left + 29,94,29,33));


        animationClock.restart();

    }

    if(x >= 500)
        health = 0;


    window.draw(plantsprite);
}

