//
// Created by admin on 5/10/2024.
//

#ifndef SFMLTEST_SUN_H
#define SFMLTEST_SUN_H
#include <SFML/Graphics.hpp>

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


    Sun(){

        spritesheet.loadFromFile("Images/sun_sheet.png");

        suntexture.loadFromImage(spritesheet);

        sunsprite.setTexture(suntexture);
        sunsprite.setTextureRect(IntRect(0, 0, 26, 26));

        x = 150, y = 0;

        clicked = false;

        sunsprite.setPosition(x,y);

        sunsprite.scale(1, 1);


    };

    bool isClicked(int MousePosX, int MousePosY){

        if(MousePosX >= x*scale && MousePosX <= (x+26)*scale && MousePosY >= y*scale && MousePosY <= (y+26)*scale){

            //make sun fly up

            totalSuns += 25;

            return true;
        }
        else{
            return false;
        }

    }

    void drawSun(RenderWindow& window){

        sunsprite.setPosition(x,y);

        window.draw(sunsprite);


    }

    void moveSun(RenderWindow& window,Time &deltaTime){

        sunsprite.setPosition(x,(y += 10 * deltaTime.asSeconds()));

        window.draw(sunsprite);
    }

    void spawnSun(){

        x = 150;
        y = 0;

        sunsprite.setPosition(x,y);
    }





};

int Sun::totalSuns = 0;




#endif //SFMLTEST_SUN_H
