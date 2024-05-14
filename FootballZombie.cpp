//
// Created by admin on 5/13/2024.
//

#include "FootballZombie.h"

FootballZombie::FootballZombie() {


    zombspritesheet.loadFromFile("Images/fbzombie_sheet.png");

    zombtexture.loadFromImage(zombspritesheet);

    zombsprite.setTexture(zombtexture);
    zombsprite.setTextureRect(IntRect(0,80,64,60));


    zombsprite.setPosition(326,100);

    x = 326;

    y = 100;

    velocity = 10;

    health = 240;

    clockEnabled = false;

    slowed = false;

    summonTimeup = false;

    dancing = false;

    zombsprite.scale(0.8,0.8);




}

void FootballZombie::eatingAnimation(RenderWindow& window){

    window.draw(zombsprite);

}

void FootballZombie::moveZombie(RenderWindow& window,Time &ZombTime){

    if(slowed){
        slowClock.restart();
        //halve velocity

    }

    if(slowClock.getElapsedTime().asSeconds() > 5.0f){
        slowed = false;
        //set velocity back to normal
    }

    if(upDownClock.getElapsedTime().asSeconds() > 5.0f){

        bool upDown = rand()%2;

        if(upDown && laneNum > 0){
            laneNum--;
            y -= (169 / 5);
        }
        else if(!upDown && laneNum < 4){
            laneNum++;
            y += (169 / 5);
        }

        upDownClock.restart();

    }

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

    if(animationClock.getElapsedTime().asSeconds() > 0.3f){

        if(zombsprite.getTextureRect().left == 448)
            zombsprite.setTextureRect(IntRect(0,80,64,60));
        else
            zombsprite.setTextureRect(IntRect(zombsprite.getTextureRect().left + 64,80,64,60));


        animationClock.restart();

    }

    window.draw(zombsprite);


}

void FootballZombie::spawn(int y){

    x = float(5+246);

    this->y = y-20;

    zombsprite.setPosition(x,this->y);


    velocity = 10;


};
