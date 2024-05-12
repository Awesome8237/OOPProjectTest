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

    Icon(int iconNum);

    bool isClicked(int MousePosX, int MousePosY);

    void drawIcon(RenderWindow& window);






};


#endif //SFMLTEST_ICON_H
