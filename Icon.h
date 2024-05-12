//
// Created by admin on 5/11/2024.
//

#ifndef SFMLTEST_ICON_H
#define SFMLTEST_ICON_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Icon{


    Image spritesheet;
    Texture icontexture;
    Sprite iconsprite;

    bool selected;
    bool available;

    float regenTime;
public:
    float getRegenTime() const {
        return regenTime;
    }

    void setRegenTime(float regenTime) {
        Icon::regenTime = regenTime;
    }

private:

    Clock timer;
public:

    void resetTimer(){

        timer.restart();

    }

    float getPassedTime(){

        return timer.getElapsedTime().asSeconds();

    }



    bool isAvailable() const {
        return available;
    }

    void setAvailable(bool available) {
        Icon::available = available;
    }

private:

    int iconWidth, iconHeight;

    int cost;
public:
    int getCost() const {
        return cost;
    }

    void setCost(int cost) {
        Icon::cost = cost;
    }

public:
    bool isSelected() const {
        return selected;
    }

    void setSelected(bool selected) {
        Icon::selected = selected;
    }

    int getIconWidth() const {
        return iconWidth;
    }

    void setIconWidth(int iconWidth) {
        Icon::iconWidth = iconWidth;
    }

    int getIconHeight() const {
        return iconHeight;
    }

    void setIconHeight(int iconHeight) {
        Icon::iconHeight = iconHeight;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        Icon::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Icon::y = y;
    }

private:

    int x,y;

public:

    Icon(int iconNum){

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


    bool isClicked(int MousePosX, int MousePosY){

        if(MousePosX >= x*scale && MousePosX <= (x+iconWidth)*scale && MousePosY >= y*scale && MousePosY <= (y+iconHeight)*scale){

            return true;

        }
        else{
            return false;
        }


    }

    void drawIcon(RenderWindow& window){

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






};


#endif //SFMLTEST_ICON_H
