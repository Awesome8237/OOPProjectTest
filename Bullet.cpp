//
// Created by admin on 5/13/2024.
//
#include "Bullet.h"

Bullet::Bullet(){


    spritesheet.loadFromFile("Images/shooter_sheet_ds.png");
    snowbullet.loadFromFile("Images/fps_sheet.png");

    bullettexture.loadFromImage(spritesheet);

    bulletsprite.setTexture(bullettexture);
    IntRect rectbulletSprite(77,43,11,10);
    bulletsprite.setTextureRect(rectbulletSprite);

    bulletsprite.scale(1,1);

    exists = false;

    snow = false;


}


void Bullet::moveBullet(RenderWindow& window,Time &bulletTime){

    if(snow){
        bullettexture.loadFromImage(snowbullet);

        bulletsprite.setTexture(bullettexture);
        IntRect rectbulletSprite(88,50,25,14);
        bulletsprite.setTextureRect(rectbulletSprite);
    }

    bulletsprite.setPosition((x += velocity * bulletTime.asSeconds()),y);
    window.draw(bulletsprite);


}

bool Bullet::isOutside(){

    if(x > 500 || !exists){
        return true;
    }
    else{
        return false;
    }


}

bool Bullet::isSnow() const {
    return snow;
}

void Bullet::setSnow(bool snow) {
    Bullet::snow = snow;
}

float Bullet::getVelocity() const {
    return velocity;
}

void Bullet::setVelocity(float velocity) {
    Bullet::velocity = velocity;
}

bool Bullet::isExists() const {
    return exists;
}

void Bullet::setExists(bool exists) {
    Bullet::exists = exists;
}

float Bullet::getX() const {
    return x;
}

void Bullet::setX(float x) {
    Bullet::x = x;
}

float Bullet::getY() const {
    return y;
}

void Bullet::setY(float y) {
    Bullet::y = y;
}
