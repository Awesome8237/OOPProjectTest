//
// Created by admin on 5/13/2024.
//
#include "Peashooter.h"

Peashooter::Peashooter(Bullet**& bullets, Zombie**& zombies, int lane){

spritesheet.loadFromFile("Images/shooter_sheet_ds.png");

planttexture.loadFromImage(spritesheet);

plantsprite.setTexture(planttexture);

plantsprite.setTextureRect(IntRect(0, 0, 27, 33));
plantsprite.setPosition(100, 100);
plantsprite.scale(1, 1);

this->bullets = bullets;

this->zombies = zombies;

currentbullets = 0;

lanenum = lane;

x = 0, y = 0;
}

void Peashooter::idleAnimation(RenderWindow& window){

    if(animationClock.getElapsedTime().asSeconds() > 0.1f){

        if(plantsprite.getTextureRect().left == 189)
            plantsprite.setTextureRect(IntRect(0, 0, 27, 33));
        else
            plantsprite.setTextureRect(IntRect(plantsprite.getTextureRect().left + 27, 0, 27, 33));


        animationClock.restart();

    }

    window.draw(plantsprite);

}


void Peashooter::update(){

    for(int i = 0; i < 45; i++) {

        if(zombies[i] == nullptr || zombies[i]->getLaneNum() != lanenum)
            continue;

        if (zombies[i]->getX() < gridSizeX) {


            if (fireClock.getElapsedTime().asSeconds() > 1.0f) {

                if (currentbullets < 10) {
                    if (bullets[currentbullets] == nullptr) {
                        bullets[currentbullets] = new Bullet();


                        bullets[currentbullets]->setX(this->x + 21);

                        bullets[currentbullets]->setY(this->y + 2);

                        //bullets[currentbullets]->bulletsprite.setPosition(this->x, this->y);

                        bullets[currentbullets]->setVelocity(70);

                        bullets[currentbullets]->setExists(true);


                        currentbullets++;


                    }
                } else {
                    currentbullets = 0;
                    if (bullets[currentbullets] == nullptr) {
                        bullets[currentbullets] = new Bullet();

                        bullets[currentbullets]->setX(this->x + 21);

                        bullets[currentbullets]->setY(this->y + 2);

                        //bullets[currentbullets]->bulletsprite.setPosition(this->x, this->y);

                        bullets[currentbullets]->setVelocity(70);

                        bullets[currentbullets]->setExists(true);

                        currentbullets++;

                    }


                }

                fireClock.restart();
            }
        }
    }



}