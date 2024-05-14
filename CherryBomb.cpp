//
// Created by admin on 5/13/2024.
//
#include "CherryBomb.h"

CherryBomb::CherryBomb(Zombie **zombies, int lane, int colnum) {

    spritesheet.loadFromFile("Images/cb_sheet.png");

planttexture.loadFromImage(spritesheet);

plantsprite.setTexture(planttexture);

plantsprite.setTextureRect(IntRect(0, 0, 34, 47));
plantsprite.setPosition(100, 100);
plantsprite.scale(0.75, 0.75);

this->zombie = zombies;

lanenum = lane;

    this->colnum = colnum;

    health = 10000;

    bomb = true;

exploded = false;

dead = false;

frameNumber = 0;

}

void CherryBomb::update(){

    if(timer.getElapsedTime().asSeconds() > 1.2f && !exploded){
        exploded = true;
        for(int i = 0; i < 45; i++){

            if(zombie[i] == nullptr)
                continue;

            if(x-(246 / 9) <= zombie[i]->getX() + 42 && x + (246 / 9) >= zombie[i]->getX() && y-(169 / 5) <= zombie[i]->getY() + 54 && y+(169 / 5) >= zombie[i]->getY())
                zombie[i]->setHealth(0);

        }

    }
    if(exploded){

        if(frameNumber == 0){
            plantsprite.setTextureRect(IntRect(0, 37, 68, 67));
            frameNumber++;
        }
        else if(frameNumber == 1){
            plantsprite.setTextureRect(IntRect(68, 37, 83, 67));
            frameNumber++;
        }
        else if(frameNumber == 2){
            plantsprite.setTextureRect(IntRect(68+83, 37, 95, 67));
            frameNumber++;
        }
        else if(frameNumber == 3){
            plantsprite.setTextureRect(IntRect(68+83+95, 37, 95, 67));
            frameNumber++;
        }
        else if(frameNumber == 4){
            plantsprite.setTextureRect(IntRect(68+83+95+95, 37, 95, 67));
            frameNumber++;
        }
        else if(frameNumber == 5){
            plantsprite.setTextureRect(IntRect(68+83+95+95+95, 37, 95, 67));
            frameNumber++;
        }
        else if(frameNumber == 6){
            plantsprite.setTextureRect(IntRect(68+83+95+95+95+95, 37, 95, 67));
            frameNumber++;
        }
        else if(frameNumber == 7){
            plantsprite.setTextureRect(IntRect(68+83+95+95+95+95+82, 37, 87, 67));
            frameNumber++;
        }
        else{
            health = 0;

        }

    }



}
void CherryBomb::idleAnimation(RenderWindow& window) {

    window.draw(plantsprite);
}