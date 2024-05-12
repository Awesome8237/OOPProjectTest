//
// Created by admin on 4/30/2024.
//

#ifndef SFMLTEST_BULLET_H
#define SFMLTEST_BULLET_H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Bullet{

    Image spritesheet;
    Image snowbullet;
    Texture bullettexture;
    Sprite bulletsprite;

    bool snow;
public:
    bool isSnow() const;

    void setSnow(bool snow);

    float getVelocity() const;

    void setVelocity(float velocity);

    bool isExists() const;

    void setExists(bool exists);

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);


private:
    float velocity;


private:
    bool exists;


private:

    float x, y;


public:

    Bullet();


    void moveBullet(RenderWindow& window,Time &bulletTime);

    bool isOutside();


    ~Bullet(){}


};


#endif //SFMLTEST_BULLET_H
