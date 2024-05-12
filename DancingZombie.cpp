//
// Created by admin on 5/13/2024.
//
#include "DancingZombie.h"

DancingZombie::DancingZombie(){


    zombspritesheet.loadFromFile("Images/dancingzombie_sheet.png");

    zombtexture.loadFromImage(zombspritesheet);

    zombsprite.setTexture(zombtexture);
    zombsprite.setTextureRect(IntRect(0,80,55,85));


    zombsprite.setPosition(326,100);

    x = 326;

    y = 100;

    velocity = 5;

    y_velocity = 5;

    dancing = true;

    summonTimeup = false;


    health = 240;




    zombsprite.scale(0.8,0.8);


}
void DancingZombie::moveZombie(RenderWindow& window,Time &ZombTime) {

    if (slowed) {
        slowClock.restart();
        //halve velocity

    }

    if (slowClock.getElapsedTime().asSeconds() > 5.0f) {
        slowed = false;
        //set velocity back to normal
    }

    if(y+85 >= gridSizeY+gridLocationY || y <= 0)
        y_velocity = -y_velocity;

    if(summonClock.getElapsedTime().asSeconds() > 30.f) {
        summonTimeup = true;
        summonClock.restart();
    }

    zombsprite.setPosition((x -= velocity * ZombTime.asSeconds()), y += y_velocity * ZombTime.asSeconds());

    if (animationClock.getElapsedTime().asSeconds() > 0.3f) {

        if (zombsprite.getTextureRect().left == 150)
            zombsprite.setTextureRect(IntRect(0, 0, 50, 80));
        else
            zombsprite.setTextureRect(IntRect(zombsprite.getTextureRect().left + 50, 0, 50,80));


        animationClock.restart();

    }

    window.draw(zombsprite);


}

void DancingZombie::eatingAnimation(RenderWindow& window){

    if (animationClock.getElapsedTime().asSeconds() > 0.3f) {

        if (zombsprite.getTextureRect().left == 55*9 || zombsprite.getTextureRect().left == 0)
            zombsprite.setTextureRect(IntRect(0, 675, 50, 80));
        else
            zombsprite.setTextureRect(IntRect(zombsprite.getTextureRect().left + 55, 0, 55,80));


        animationClock.restart();

    }

    window.draw(zombsprite);



}

void DancingZombie::spawn(int y){

    x = float(gridLocationX+gridSizeX);

    this->y = y-20;

    zombsprite.setPosition(x,this->y);


    velocity = 5;


};