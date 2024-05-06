#include <SFML/Graphics.hpp>
#include <ctime>
#include "Bullet.h"
#include "Zombie.h"
#include "Peashooter.h"
#include "ZombieAbstract.h"
#include <ctime>

//#include"../SFML/Images/"
using namespace sf;
using namespace std;

struct coordinats {
    int x;
    int y;
};

/*const int windowSizeX = 256;
const int windowSizeY = 192;
const int gridSizeX = 246;
const int gridSizeY = 169;
const int windowLocationX = 71;
const int windowLocationY = 2;
const int gridLocationX = 5;
const int gridLocationY = 17;*/



//Drawing the background
void createBack(RenderWindow& window) {
    //Drawing the background
    Image map_image;
    map_image.loadFromFile("Images/lawn_sheet_edited.png");
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setTextureRect(IntRect(windowLocationX,windowLocationY,windowSizeX,windowSizeY));
    s_map.setPosition(0, 0);
    window.draw(s_map);
}

//Drawing the map
void createMap(RenderWindow& window) {
    //Drawing a map
    Image map_image;//объект изображения для карты
    map_image.loadFromFile("Images/lawn_sheet_edited.png");//load the file for the map
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setTextureRect(IntRect(248,242,gridSizeX,gridSizeY));
    s_map.setPosition(gridLocationX,gridLocationY);

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


    srand(time(0));


    RenderWindow window(VideoMode(windowSizeX, windowSizeY), "Plants Vs Zombies");
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
            FIELD_GAME_STATUS[i][j] = false;
        }
    }

    Clock timeMoney;

    Clock clock;

    Clock animationClock;

    Clock bulletClock;

    Clock fireClock;

    Clock zomClock;

    Time bulletTime;

    ZombieAbstract* zombie[5];

    Bullet** bullet[45];

    //Bullet* bullet[10];

    Peashooter* peashooter[45];

    for(int i = 0; i < 10; i++)
        bullet[i] = nullptr;

    for (int i = 0; i < 5; ++i) {
        zombie[i] = nullptr;
    }

    for (int i = 0; i < 45; ++i) {
        peashooter[i] = nullptr;
        bullet[i] = nullptr;
    }

    int currentbullets = 0;
    int currentzombie = 0;

    int currentshooter = 0;

    /*Image spritesheet;
    spritesheet.loadFromFile("Images/peashooter_sheet_test.png");
    Texture peashootertexture;
    peashootertexture.loadFromImage(spritesheet);
    Sprite peashootersprite;
    peashootersprite.setTexture(peashootertexture);
    IntRect rectPeaShooterSprite(2,10,34,33);
    peashootersprite.setTextureRect(rectPeaShooterSprite);
    peashootersprite.setPosition(100,100);
    peashootersprite.scale(1,1);*/

    bool mouseclicked = false;

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



        if(Mouse::isButtonPressed(Mouse::Left)){
            mouseclicked = true;
            cout << "Button's pressed" << endl;
            cout << Mouse::getPosition(window).x << "," << Mouse::getPosition(window).y << endl;

        }

        if(mouseclicked){
            mouseclicked = false;
            /*for(int i = 0; i < ROWS; i++){

                for(int j = 0; j < COLS; j++){*/


                        int MousePosX = Mouse::getPosition(window).x;
                        int MousePosY = Mouse::getPosition(window).y;

                        

                        int j = (((MousePosX-gridLocationX*scale)/(gridSizeX*scale/9)));
                        int i = (((MousePosY-gridLocationY*scale)/(gridSizeY*scale/5)));

                        cout << MousePosX <<","<< MousePosY << endl;
                        cout << i << "," << j << endl;


                        if(!FIELD_GAME_STATUS[i][j] && i >= 0 && i < 5 && j >= 0 && j < 9) {
                            FIELD_GAME_STATUS[i][j] = true;
                            bullet[currentshooter] = new Bullet*[10];

                            for(int k = 0; k < 10; k++)
                                bullet[currentshooter][k] = nullptr;

                            peashooter[currentshooter] = new Peashooter(bullet[currentshooter], i);

                            peashooter[currentshooter]->spawn((gridSizeX/9)*j+gridLocationX, (gridSizeY/5)*i+gridLocationY);
                            currentshooter++;

                        }

                    //}

            /*    }


            }*/


        }

        bulletTime = bulletClock.restart();

        //if(fireClock.getElapsedTime().asSeconds() > 1.0f){

            for(int i = 0; i < 5; i++) {

                if(zombie[i] == nullptr)
                    continue;

                if (zombie[i]->x < gridSizeX) {

                    for(int j = 0; j < 45; j++){

                        if(peashooter[j] == nullptr)
                            continue;

                        peashooter[j]->fire();


                    }



                        //fireClock.restart();

                }
            }

        //}

        if(zomClock.getElapsedTime().asSeconds() > 5.0f){

            int lane = rand()%5;

            if(currentzombie < 5) {
                if(zombie[currentzombie] == nullptr) {



                    zombie[currentzombie] = new Zombie();

                    zombie[currentzombie]->spawn((gridSizeY/5)*lane+gridLocationY);
                    currentzombie++;

                    zomClock.restart();
                }
            }
            else{
                currentzombie = 0;
                if(zombie[currentzombie] == nullptr) {

                    zombie[currentzombie] = new Zombie();

                    zombie[currentzombie]->spawn((gridSizeY/5)*lane+gridLocationY);

                    zomClock.restart();
                }



            }

        }

        for(int i = 0; i < currentshooter; i++) {

            if(peashooter[i] == nullptr)
                continue;

            peashooter[i]->idleAnimation(window);
        }

        for(int i = 0; i < 45; i++) {

            if(bullet[i] == nullptr)
                continue;

            for(int j = 0; j < 10; j++) {

                if (bullet[i][j] == nullptr)
                    continue;

                for (int k = 0; k < 5; k++) {

                    if (zombie[k] == nullptr)
                        continue;

                    if (bullet[i][j]->x <= zombie[k]->x + 42 && bullet[i][j]->x + 10 >= zombie[k]->x && bullet[i][j]->y <= zombie[k]->y + 54 && bullet[i][j]->y+10 >= zombie[k]->y) {


                        zombie[k]->health -= 30;

                        bullet[i][j]->x = zombie[k]->x;
                        bullet[i][j]->y = zombie[k]->y;
                        bullet[i][j]->exists = false;
                    }

                }


                if (!bullet[i][j]->isOutside()) {

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

                    bullet[i][j]->moveBullet(window, bulletTime);

                } else {
                    delete bullet[i][j];
                    bullet[i][j] = nullptr;

                }
            }
        }

        /*if(animationClock.getElapsedTime().asSeconds() > 0.1f){

            if(rectPeaShooterSprite.left == 233)
                rectPeaShooterSprite.left = 2;
            else
                rectPeaShooterSprite.left += 33;

            peashootersprite.setTextureRect(rectPeaShooterSprite);
            animationClock.restart();

        }*/




        for(int i = 0; i < 5; i++) {

            if(zombie[i] == nullptr)
                continue;

            if (zombie[i]->health <= 0) {

                delete zombie[i];
                zombie[i] = nullptr;


            }
            else {
                zombie[i]->moveZombie(window, bulletTime);
            }
        }









        window.setSize(sf::Vector2u(256*scale,192*scale));
        window.display();
    }
    return 0;
}