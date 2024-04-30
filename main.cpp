#include <SFML/Graphics.hpp>
#include <ctime>
#include "Bullet.h"
#include "Zombie.h"
//#include"../SFML/Images/"
using namespace sf;
using namespace std;

struct coordinats {
    int x;
    int y;
};



//Drawing the background
void createBack(RenderWindow& window) {
    //Drawing the background
    Image map_image;
    map_image.loadFromFile("Images/lawn_sheet.png");
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setTextureRect(IntRect(2,2,326,192));
    s_map.setPosition(0, 0);
    window.draw(s_map);
}

//Drawing the map
void createMap(RenderWindow& window) {
    //Drawing a map
    Image map_image;//объект изображения для карты
    map_image.loadFromFile("Images/lawn_sheet.png");//load the file for the map
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setTextureRect(IntRect(245,412-170,248,173));
    s_map.setPosition(320-250, 182-166);

    window.draw(s_map);
}

void createSprite(RenderWindow& window){

    Image spritesheet;
    spritesheet.loadFromFile("Images/peashooter_sheet_test.png");
    Texture peashootertexture;
    peashootertexture.loadFromImage(spritesheet);
    Sprite peashootersprite;
    peashootersprite.setTexture(peashootertexture);


};

int main()
{
    //Create a window, n*n
    RenderWindow window(VideoMode(326, 192), "Plants Vs Zombies");
    //Game icon
    Image icon;
    if (!icon.loadFromFile("Images/icon.png"))
    {
        return 1;
    }
    window.setIcon(32, 32, icon.getPixelsPtr());

    ///////////////////////////////////////

    //Game field (5*9)
    //Point 137*79 - leftmost point
    //length 41; width 53
    const int ROWS = 5;
    const int COLS = 9;

    bool FIELD_GAME_STATUS[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            FIELD_GAME_STATUS[i][j] = true;
        }
    }

    Clock timeMoney;

    Clock clock;

    Clock animationClock;

    Clock bulletClock;

    Clock fireClock;

    Time bulletTime;

    Zombie zombie;

    Bullet* bullet[10];

    for(int i = 0; i < 10; i++)
        bullet[i] = nullptr;

    int currentbullets = 0;

    Image spritesheet;
    spritesheet.loadFromFile("Images/peashooter_sheet_test.png");
    Texture peashootertexture;
    peashootertexture.loadFromImage(spritesheet);
    Sprite peashootersprite;
    peashootersprite.setTexture(peashootertexture);
    IntRect rectPeaShooterSprite(2,10,34,33);
    peashootersprite.setTextureRect(rectPeaShooterSprite);
    peashootersprite.setPosition(100,100);
    peashootersprite.scale(1,1);

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        float moneyTime = timeMoney.getElapsedTime().asSeconds();

        clock.restart();
        time = time / 800;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //Create a background
        createBack(window);
        createMap(window);



        bulletTime = bulletClock.restart();

        if(fireClock.getElapsedTime().asSeconds() > 1.0f){

            if(currentbullets < 10) {
                if(bullet[currentbullets] == nullptr) {
                    bullet[currentbullets] = new Bullet();

                    bullet[currentbullets]->fire();
                    currentbullets++;

                    fireClock.restart();
                }
            }
            else{
                currentbullets = 0;
                if(bullet[currentbullets] == nullptr) {
                    bullet[currentbullets] = new Bullet();

                    bullet[currentbullets]->fire();
                    currentbullets++;

                    fireClock.restart();
                }


            }

        }

        for(int i = 0; i < 10; i++) {

            if(bullet[i] == nullptr)
                continue;

            if(bullet[i]->x <= zombie.x + 42 && bullet[i]->x + 10 >= zombie.x){

                bullet[i]->x = 1300;
                zombie.health -= 30;

            }

            if (!bullet[i]->isOutside()) {

//                Bullet temp[10];
//
//                for(int i = 0; i < currentbullets; i++){
//
//                    if(bullet[i].isOutside()){
//                        continue;
//                    }
//
//                    temp[i] = bullet[i];
//
//
//                }
//                currentbullets--;
//                for(int i = 0; i < currentbullets; i++){
//
//                    bullet[i] = temp[i];
//
//
//                }
//
//
//            }

               bullet[i]->moveBullet(window, bulletTime);

            }
            else{
                delete bullet[i];
                bullet[i] = nullptr;

            }
        }

        if(animationClock.getElapsedTime().asSeconds() > 0.1f){

            if(rectPeaShooterSprite.left == 233)
                rectPeaShooterSprite.left = 2;
            else
                rectPeaShooterSprite.left += 33;

            peashootersprite.setTextureRect(rectPeaShooterSprite);
            animationClock.restart();

        }

        if(zombie.health <= 0) {
            zombie.x = 1300;
            zombie.y = 12;
            zombie.zombsprite.setPosition(1300,12);
        }
        else{
            zombie.moveZombie(window, bulletTime);
        }

        window.draw(peashootersprite);







        window.setSize(sf::Vector2u(550, 340));
        window.display();
    }
    return 0;
}