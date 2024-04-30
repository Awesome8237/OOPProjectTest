//
// Created by admin on 4/30/2024.
//

#ifndef SFMLTEST_ZOMBIE_H
#define SFMLTEST_ZOMBIE_H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Zombie{

public:

    Image zombspritesheet;
    Texture zombtexture;
    Sprite zombsprite;
    float velocity;

    int health;


    Clock animationClock;

    float x, y;



    Zombie(){


        zombspritesheet.loadFromFile("Images/zombie_sheet_test.png");

        zombtexture.loadFromImage(zombspritesheet);

        zombsprite.setTexture(zombtexture);
        zombsprite.setTextureRect(IntRect(0,59,42,54));


        zombsprite.setPosition(200,100);

        x = 200;

        y = 100;

        velocity = 5;

        health = 120;


        zombsprite.scale(1,1);




    }


    void moveZombie(RenderWindow& window,Time &ZombTime){


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

    bool isOutside(){

        if(x > 600){
            return true;
        }
        else{
            return false;
        }


    }




};

#endif //SFMLTEST_ZOMBIE_H
