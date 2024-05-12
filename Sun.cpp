//
// Created by admin on 5/13/2024.
//
#include "Sun.h"
Sun::Sun(){

    spritesheet.loadFromFile("Images/sun_sheet.png");

    suntexture.loadFromImage(spritesheet);

    sunsprite.setTexture(suntexture);
    sunsprite.setTextureRect(IntRect(0, 0, 26, 26));

    x = 150, y = 0;

    clicked = false;

    sunsprite.setPosition(x,y);

    sunsprite.scale(1, 1);


};

bool Sun::isClicked(int MousePosX, int MousePosY){

    if(MousePosX >= x*3 && MousePosX <= (x+26)*3 && MousePosY >= y*3 && MousePosY <= (y+26)*3){

        //make sun fly up

        totalSuns += 25;

        return true;
    }
    else{
        return false;
    }

}

void Sun::drawSun(RenderWindow& window){

    sunsprite.setPosition(x,y);

    window.draw(sunsprite);


}

void Sun::moveSun(RenderWindow& window,Time &deltaTime){

    sunsprite.setPosition(x,(y += 10 * deltaTime.asSeconds()));

    window.draw(sunsprite);
}

void Sun::spawnSun(){

    x = 150;
    y = 0;

    sunsprite.setPosition(x,y);
}
int Sun::totalSuns = 0;
