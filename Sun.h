//
// Created by admin on 5/10/2024.
//

#ifndef SFMLTEST_SUN_H
#define SFMLTEST_SUN_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Sun{



    bool clicked;
public:
    bool getClicked() const {
        return clicked;
    }

    void setClicked(bool clicked) {
        Sun::clicked = clicked;
    }

private:

    Image spritesheet;
    Texture suntexture;
    Sprite sunsprite;


public:

    static int totalSuns;

    static int getTotalSuns() {
        return totalSuns;
    }

    static void setTotalSuns(int totalSuns) {
        Sun::totalSuns = totalSuns;
    }

private:

    float x,y;
public:
    int getX() const {
        return x;
    }

    void setX(int x) {
        Sun::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Sun::y = y;
    }

public:


    Sun();

    bool isClicked(int MousePosX, int MousePosY);

    void drawSun(RenderWindow& window);

    void moveSun(RenderWindow& window,Time &deltaTime);

    void spawnSun();





};






#endif //SFMLTEST_SUN_H
