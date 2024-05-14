//
// Created by admin on 5/13/2024.
//
#include "FrozenPeaShooter.h"

FrozenPeashooter::FrozenPeashooter(Bullet**& bullets, Zombie**& zombies, int lane, int colnum){

spritesheet.loadFromFile("Images/fps_sheet.png");

planttexture.loadFromImage(spritesheet);

plantsprite.setTexture(planttexture);

plantsprite.setTextureRect(IntRect(0, 0, 30, 32));
plantsprite.setPosition(100, 100);
plantsprite.scale(1, 1);

this->bullets = bullets;

this->zombies = zombies;

currentbullets = 0;

    health = 100;

    bomb = false;

    this->colnum = colnum;

lanenum = lane;

x = 0, y = 0;
}

void FrozenPeashooter::idleAnimation(RenderWindow& window){

    if(animationClock.getElapsedTime().asSeconds() > 0.1f){

        if(plantsprite.getTextureRect().left == 30*7)
            plantsprite.setTextureRect(IntRect(0, 0, 30, 32));
        else
            plantsprite.setTextureRect(IntRect(plantsprite.getTextureRect().left + 30, 0, 30, 32));


        animationClock.restart();

    }

    window.draw(plantsprite);

}


void FrozenPeashooter::update(){

    for(int i = 0; i < 45; i++) {

        if(zombies[i] == nullptr || zombies[i]->getLaneNum() != lanenum)
            continue;

        if (zombies[i]->getX() < 246) {


            if (fireClock.getElapsedTime().asSeconds() > 1.0f) {

                if (currentbullets < 10) {
                    if (bullets[currentbullets] == nullptr) {
                        bullets[currentbullets] = new Bullet();


                        bullets[currentbullets]->setX(this->x + 21);

                        bullets[currentbullets]->setY(this->y + 2);



                        bullets[currentbullets]->setVelocity(70);

                        bullets[currentbullets]->setSnow(true);

                        bullets[currentbullets]->setExists(true);


                        currentbullets++;


                    }
                } else {
                    currentbullets = 0;
                    if (bullets[currentbullets] == nullptr) {
                        bullets[currentbullets] = new Bullet();

                        bullets[currentbullets]->setX(this->x + 21);

                        bullets[currentbullets]->setY(this->y + 2);



                        bullets[currentbullets]->setVelocity(70);

                        bullets[currentbullets]->setSnow(true);

                        bullets[currentbullets]->setExists(true);

                        currentbullets++;

                    }


                }

                fireClock.restart();
            }
        }
    }



}
