//
// Created by admin on 5/13/2024.
//
#include "CherryBomb.h"

CherryBomb::CherryBomb(Zombie **zombies, int lane) {

    spritesheet.loadFromFile("Images/cb_sheet.png");

planttexture.loadFromImage(spritesheet);

plantsprite.setTexture(planttexture);

plantsprite.setTextureRect(IntRect(0, 0, 34, 47));
plantsprite.setPosition(100, 100);
plantsprite.scale(0.75, 0.75);

this->zombie = zombies;

lanenum = lane;

exploded = false;

}

void CherryBomb::update(){

    if(timer.getElapsedTime().asSeconds() > 1.2f && !exploded){
        exploded = true;
        for(int i = 0; i < 45; i++){

            if(zombie[i] == nullptr)
                continue;

            if(x-(gridSizeX / 9) <= zombie[i]->getX() + 42 && x + (gridSizeX / 9) >= zombie[i]->getX() && y-(gridSizeY / 5) <= zombie[i]->getY() + 54 && y+(gridSizeY / 5) >= zombie[i]->getY())
                zombie[i]->setHealth(0);

        }

    }



}
void CherryBomb::idleAnimation(RenderWindow& window) {

    window.draw(plantsprite);
}