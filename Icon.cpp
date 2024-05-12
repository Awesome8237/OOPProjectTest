//
// Created by admin on 5/13/2024.
//
#include "Icon.h"

Icon::Icon(int iconNum){

    available = false;

    switch(iconNum) {

        case 0:

            spritesheet.loadFromFile("Images/shooter_sheet_ds.png");

            icontexture.loadFromImage(spritesheet);

            iconsprite.setTexture(icontexture);

            iconWidth = 26, iconHeight = 24;

            iconsprite.setTextureRect(IntRect(113, 36, iconWidth, iconHeight));

            x = 20, y = 1;

            iconsprite.setPosition(x, y);

            iconsprite.scale(1, 1);

            selected = false;



            cost = 100;

            regenTime = 3.f;

            break;

        case 1:

            spritesheet.loadFromFile("Images/sunflower_sheet.png");

            icontexture.loadFromImage(spritesheet);

            iconsprite.setTexture(icontexture);

            iconWidth = 26, iconHeight = 26;

            iconsprite.setTextureRect(IntRect(161, 0, iconWidth, iconHeight));

            x = 50, y = -1;

            iconsprite.setPosition(x, y);

            iconsprite.scale(1, 1);

            selected = false;

            cost = 50;

            regenTime = 1.f;

            break;

        case 2:

            spritesheet.loadFromFile("Images/cb_sheet.png");

            icontexture.loadFromImage(spritesheet);

            iconsprite.setTexture(icontexture);

            iconWidth = 25, iconHeight = 27;

            iconsprite.setTextureRect(IntRect(265, 11, iconWidth, iconHeight));

            x = 80, y = -1;

            iconsprite.setPosition(x, y);

            iconsprite.scale(1, 1);

            selected = false;

            cost = 150;

            regenTime = 6.f;

            break;

        case 3:

            spritesheet.loadFromFile("Images/wallNut_sheet.png");

            icontexture.loadFromImage(spritesheet);

            iconsprite.setTexture(icontexture);

            iconWidth = 26, iconHeight = 32;

            iconsprite.setTextureRect(IntRect(135, 0, iconWidth, iconHeight));

            x = 110, y = -6;

            iconsprite.setPosition(x, y);

            iconsprite.scale(1, 1);

            selected = false;

            cost = 50;

            regenTime = 3.f;

            break;

        case 4:

            spritesheet.loadFromFile("Images/fps_sheet.png");

            icontexture.loadFromImage(spritesheet);

            iconsprite.setTexture(icontexture);

            iconWidth = 27, iconHeight = 24;

            iconsprite.setTextureRect(IntRect(169, 38, iconWidth, iconHeight));

            x = 140, y = 0;

            iconsprite.setPosition(x, y);

            iconsprite.scale(1, 1);

            selected = false;



            cost = 175;

            regenTime = 3.f;

            break;

        case 5:

            spritesheet.loadFromFile("Images/repeater_sheet.png");

            icontexture.loadFromImage(spritesheet);

            iconsprite.setTexture(icontexture);

            iconWidth = 26, iconHeight = 24;

            iconsprite.setTextureRect(IntRect(117, 33, iconWidth, iconHeight));

            x = 170, y = 0;

            iconsprite.setPosition(x, y);

            iconsprite.scale(1, 1);

            selected = false;



            cost = 175;

            regenTime = 3.f;

            break;


    }

}


bool Icon::isClicked(int MousePosX, int MousePosY){

    if(MousePosX >= x*3 && MousePosX <= (x+iconWidth)*3 && MousePosY >= y*3 && MousePosY <= (y+iconHeight)*3){

        return true;

    }
    else{
        return false;
    }


}

void Icon::drawIcon(RenderWindow& window){

    if(selected && available) {
        iconsprite.setColor(Color::White);
    }
    else if(!selected && available){
        iconsprite.setColor(Color::Cyan);

    }
    else{
        iconsprite.setColor(Color::Red);
    }

    window.draw(iconsprite);
}