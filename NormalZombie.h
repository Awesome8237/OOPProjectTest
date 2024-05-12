//
// Created by admin on 4/30/2024.
//

#ifndef SFMLTEST_NORMALZOMBIE_H
#define SFMLTEST_NORMALZOMBIE_H

#include <SFML/Graphics.hpp>
#include "Zombie.h"

using namespace sf;
using namespace std;

/*const int scale = 3;

const int windowSizeX = 256;
const int windowSizeY = 192;
const int gridSizeX = 246;
const int gridSizeY = 169;
const int windowLocationX = 71;
const int windowLocationY = 2;
const int gridLocationX = 5;
const int gridLocationY = 17;*/

class NormalZombie: public Zombie{


    Clock animationClock;
    bool clockEnabled;


public:
    NormalZombie(){


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


    virtual void moveZombie(RenderWindow& window,Time &ZombTime){

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

    virtual void eatingAnimation(RenderWindow& window) {};

    /*bool isOutside(){

        if(x > windowSizeX){
            return true;
        }
        else{
            return false;
        }


    }*/

    virtual void spawn(int y){

        x = float(gridLocationX+gridSizeX);

        this->y = y-20;

        zombsprite.setPosition(x,this->y);


        velocity = 5;


    };

    ~NormalZombie(){}

};

#endif //SFMLTEST_NORMALZOMBIE_H
