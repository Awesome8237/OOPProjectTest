//
// Created by admin on 5/13/2024.
//
#include "NormalZombie.h"

NormalZombie::NormalZombie(){


    zombspritesheet.loadFromFile("Images/zombie_sheet_test.png");

    zombtexture.loadFromImage(zombspritesheet);

    zombsprite.setTexture(zombtexture);
    zombsprite.setTextureRect(IntRect(0,59,42,54));


    zombsprite.setPosition(326,100);

    x = 326;

    y = 100;

    velocity = 5;

    health = 120;

    slowed = false;

    clockEnabled = false;

    summonTimeup = false;

    dancing = false;

    zombsprite.scale(1,1);




}


void NormalZombie::moveZombie(RenderWindow& window,Time &ZombTime){

    if(slowed && !clockEnabled){
        slowClock.restart();
        velocity /= 2;
        slowed = false;
        clockEnabled = true;
        zombsprite.setColor(Color::Cyan);
    }

    if(slowClock.getElapsedTime().asSeconds() > 5.0f && clockEnabled){
        velocity *= 2;
        clockEnabled = false;
        zombsprite.setColor(Color::White);
    }



    zombsprite.setPosition((x -= velocity * ZombTime.asSeconds()),y);

    if(animationClock.getElapsedTime().asSeconds() > 0.5f){

        if(zombsprite.getTextureRect().left == 300)
            zombsprite.setTextureRect(IntRect(0,59,42,54));
        else
            zombsprite.setTextureRect(IntRect(zombsprite.getTextureRect().left + 50,59,42,54));



        animationClock.restart();

    }

    window.draw(zombsprite);


}

void NormalZombie::eatingAnimation(RenderWindow& window) {};

/*bool isOutside(){

    if(x > windowSizeX){
        return true;
    }
    else{
        return false;
    }


}*/

void NormalZombie::spawn(int y){

    x = float(gridLocationX+gridSizeX);

    this->y = y-20;

    zombsprite.setPosition(x,this->y);


    velocity = 5;


};