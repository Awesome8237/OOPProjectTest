//
// Created by admin on 4/30/2024.
//

#ifndef SFMLTEST_BULLET_H
#define SFMLTEST_BULLET_H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Bullet{

public:

    Image spritesheet;
    Texture bullettexture;
    Sprite bulletsprite;
    float velocity;

    bool exists;

    float x, y;



    Bullet(){


        spritesheet.loadFromFile("Images/shooter_sheet_ds.png");

        bullettexture.loadFromImage(spritesheet);

        bulletsprite.setTexture(bullettexture);
        IntRect rectbulletSprite(77,43,11,10);
        bulletsprite.setTextureRect(rectbulletSprite);

        bulletsprite.scale(1,1);

        exists = false;


    }

    void fire(){


        bulletsprite.setPosition(121, 106);

        x = 121;

        y = 103;

        velocity = 70;

        exists = true;


    }

    void moveBullet(RenderWindow& window,Time &bulletTime){

        bulletsprite.setPosition((x += velocity * bulletTime.asSeconds()),y);
        window.draw(bulletsprite);


    }

    bool isOutside(){

        if(x > 600 || !exists){
            return true;
        }
        else{
            return false;
        }


    }

    Bullet& operator=(Bullet& copy){

        spritesheet.loadFromFile("Images/peashooter_sheet_test.png");

        bullettexture.loadFromImage(spritesheet);

        bulletsprite.setTexture(bullettexture);
        IntRect rectbulletSprite(256,63,10,10);
        bulletsprite.setTextureRect(rectbulletSprite);


        bulletsprite.scale(1,1);

        velocity = copy.velocity;
        x = copy.x;
        y = copy.y;

        return *this;



    }

    ~Bullet(){



    }



};


#endif //SFMLTEST_BULLET_H
