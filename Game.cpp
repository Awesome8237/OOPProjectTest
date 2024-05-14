//
// Created by admin on 5/13/2024.
//
#include "Game.h"




//#include"../SFML/Images/"
using namespace sf;
using namespace std;

/*const int 256 = 256;
const int 192 = 192;
const int 246 = 246;
const int 169 = 169;
const int 71 = 71;
const int 2 = 2;
const int 5 = 5;
const int 17 = 17;*/



//Drawing the background
void createBack(RenderWindow& window) {
    //Drawing the background
    Image map_image;
    map_image.loadFromFile("Images/lawn_sheet_edited.png");
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setTextureRect(IntRect(71,2,256,192));
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
    s_map.setTextureRect(IntRect(248,242,246,169));
    s_map.setPosition(5,17);

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

    //Create a window, n*n

Game::Game() {
    srand(time(0));


    RenderWindow window(VideoMode(256, 192), "Plants Vs Zombies");
    //Game icon
    Image icon;
    if (!icon.loadFromFile("Images/icon.png")) {

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

    Time deltaTime;


    Zombie **zombie;

    zombie = new Zombie *[45];

    Bullet **bullet[45];

    Sun **sun[45];

    Sun FlyingSun;

    Clock FlyingSunClock;

    Plant *plants[45];

    Icon *icons[7];

    PlantFactory plantFactory(plants, bullet, sun, zombie, deltaTime);

    ZombieFactory zombieFactory(zombie);


    cout << "Total suns: " << Sun::totalSuns << endl;


    for (int i = 0; i < 7; ++i) {

        icons[i] = nullptr;
    }

    for (int i = 0; i < 45; ++i) {
        plants[i] = nullptr;
        bullet[i] = nullptr;
        sun[i] = nullptr;
        zombie[i] = nullptr;
    }

    icons[0] = new Icon(0);
    icons[1] = new Icon(1);
    icons[2] = new Icon(2);
    icons[3] = new Icon(3);
    icons[4] = new Icon(4);
    icons[5] = new Icon(5);






    //-------------------------GAME LOOP-------------------------------------//


    bool mouseclicked = false;

    bool paused = false;

    bool gameOver = false;

    int lives = 3;

    Font sunFont;
    sunFont.loadFromFile("Images/dogica.ttf");
    Text TotalSuns;
    TotalSuns.setFont(sunFont);
    TotalSuns.setCharacterSize(10);
    TotalSuns.setFillColor(Color::Black);

    Text Lives;
    TotalSuns.setFont(sunFont);
    TotalSuns.setCharacterSize(10);
    TotalSuns.setFillColor(Color::Black);



    while (window.isOpen() && !gameOver) {


        float time = clock.getElapsedTime().asMicroseconds();
        float moneyTime = timeMoney.getElapsedTime().asSeconds();

        clock.restart();
        time = time / 800;

        //----------------------------EVENT POLLING------------------------------------------//

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) //Mouse button Pressed
            {
                if (event.mouseButton.button == sf::Mouse::Left && !mouseclicked) //specifies
                {
                    mouseclicked = true;
                }
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == Keyboard::Escape) {
                paused = !paused;

            }


        }

        //Create a background
        createBack(window);
        createMap(window);

        TotalSuns.setString( to_string(Sun::totalSuns) );
        TotalSuns.setPosition(200,4);

        Lives.setString( to_string(lives) );
        Lives.setPosition(220,4);

        //-----------------------------------MOUSE CLICK DETECTION--------------------------------//

        int MousePosX = Mouse::getPosition(window).x;
        int MousePosY = Mouse::getPosition(window).y;

        if (mouseclicked) {
            mouseclicked = false;

            /*int MousePosX = Mouse::getPosition(window).x;
            int MousePosY = Mouse::getPosition(window).y;*/


            //---------FLYING SUN CLICKS-----------//

            if (FlyingSun.isClicked(MousePosX, MousePosY)) {

                FlyingSun.setClicked(true);

            }

            for (int i = 0; i < 45; i++) {

                if (sun[i] == nullptr)
                    continue;

                for (int j = 0; j < 5; j++) {

                    if (sun[i][j] == nullptr)
                        continue;

                    if (sun[i][j]->isClicked(MousePosX, MousePosY)) {

                        sun[i][j]->setClicked(true);


                    }

                }

            }

            //---------SUN CLICKS-----------//

            for (int i = 0; i < 7; i++) {

                if (icons[i] == nullptr)
                    continue;

                if (Sun::totalSuns >= icons[i]->getCost() && icons[i]->getPassedTime() >= icons[i]->getRegenTime())
                    icons[i]->setAvailable(true);
                else
                    icons[i]->setAvailable(false);


                if (icons[i]->isClicked(MousePosX, MousePosY) && icons[i]->isAvailable()) {

                    for (int j = 0; j < 7; j++) {
                        if (icons[j] == nullptr || i == j)
                            continue;

                        icons[j]->setSelected(false);

                    }

                    icons[i]->setSelected(!(icons[i]->isSelected()));


                }


                cout << "Selected: " << icons[i]->isSelected() << endl;

            }

            //---------ICON CLICKS-----------//

            if (MousePosX >= 5 * scale && MousePosY >= 17 * scale) {
                int j = (((MousePosX - 5 * scale) / (246 * scale / 9)));
                int i = (((MousePosY - 17 * scale) / (169 * scale / 5)));

                cout << MousePosX << "," << MousePosY << endl;
                cout << i << "," << j << endl;

                int iconNum = -1;

                for (int k = 0; k < 7; k++) {

                    if (icons[k] == nullptr)
                        continue;

                    if (icons[k]->isSelected()) {

                        iconNum = k;
                        cout << "IconNum: " << iconNum << endl;

                        break;

                    }

                }


                if (!FIELD_GAME_STATUS[i][j] && i >= 0 && i < 5 && j >= 0 && j < 9 && iconNum != -1) {

                    FIELD_GAME_STATUS[i][j] = true;


                    plantFactory.createPlant(i, j, iconNum);


                    icons[iconNum]->setSelected(false);
                    icons[iconNum]->resetTimer();
                    icons[iconNum]->setAvailable(false);
                    Sun::totalSuns -= icons[iconNum]->getCost();
                }
            }


        }

        if(lives == 0)
            gameOver = true;

        if(gameOver)
            window.close();

        //--------------------------------- ENTITY UPDATION ----------------------------------//

        deltaTime = bulletClock.restart();



        //---------FLYING SUN------------//


        if (FlyingSunClock.getElapsedTime().asSeconds() >= 5.0f && FlyingSun.getClicked() || FlyingSun.getY() >= 200) {

            FlyingSun.spawnSun();
            FlyingSun.setClicked(false);
            FlyingSunClock.restart();

        }

        if (!FlyingSun.getClicked())
            FlyingSun.moveSun(window, deltaTime);





        //----------------PLANT UPDATION------------------------//

        for (int j = 0; j < 45; j++) {

            if (plants[j] == nullptr)
                continue;

            plants[j]->update();


        }



        //---------ZOMBIE SPAWNING---------------------//


        zombieFactory.createZombie();

        //---------PLANTS---------------------//

        for (int i = 0; i < 45; i++) {

            if (plants[i] == nullptr)
                continue;

            plants[i]->idleAnimation(window);

            if (plants[i]->getHealth() <= 0) {
                delete plants[i];
                plants[i] = nullptr;
            }
        }


        //-------------------BULLETS---------------------//

        for (int i = 0; i < 45; i++) {

            if (bullet[i] == nullptr)
                continue;

            for (int j = 0; j < 10; j++) {

                if (bullet[i][j] == nullptr)
                    continue;

                for (int k = 0; k < 45; k++) {

                    if (zombie[k] == nullptr)
                        continue;

                    if (bullet[i][j]->getX() <= zombie[k]->getX() + 42 &&
                        bullet[i][j]->getX() + 10 >= zombie[k]->getX() &&
                        bullet[i][j]->getY() <= zombie[k]->getY() + 54 &&
                        bullet[i][j]->getY() + 10 >= zombie[k]->getY()) {

                        if (bullet[i][j]->isSnow())
                            zombie[k]->setSlowed(true);

                        zombie[k]->setHealth(zombie[k]->getHealth() - 30);

                        bullet[i][j]->setX(zombie[k]->getX());
                        bullet[i][j]->setY(zombie[k]->getY());
                        bullet[i][j]->setExists(false);
                    }

                }


                if (!bullet[i][j]->isOutside()) {

                    bullet[i][j]->moveBullet(window, deltaTime);

                } else {
                    delete bullet[i][j];
                    bullet[i][j] = nullptr;

                }
            }
        }

        //-------------------ZOMBIES---------------------//
        for (int i = 0; i < 45; i++) {

            if (zombie[i] == nullptr)
                continue;

            if (zombie[i]->isDancing() && zombie[i]->isSummonTimeup()) {
                zombieFactory.summonZombie(i);
                zombie[i]->setSummonTimeup(false);
            }

            if(zombie[i]->getX() <= 0){

                lives--;
                delete zombie[i];
                zombie[i] = nullptr;


            }


            if (zombie[i] != nullptr && zombie[i]->getHealth() <= 0) {

                delete zombie[i];
                zombie[i] = nullptr;


            } else {

                 bool eating = false;

                 for(int j = 0; j < 45; j++){

                     if(plants[j] == nullptr)
                         continue;

                     if(zombie[i] == nullptr)
                         continue;

                     if(plants[j]->getX() <= zombie[i]->getX() + 48 && plants[j]->getX() + (246/9) >= zombie[i]->getX() && plants[j]->getY() <= zombie[i]->getY() + (169/5) && plants[j]->getY()+(169/5) >= zombie[i]->getY()){

                         plants[j]->setHealth(plants[j]->getHealth() - 1);

                         zombie[i]->eatingAnimation(window);

                         eating = true;

                     }

                 }

                 if(!eating)
                if(zombie[i] != nullptr)
                    zombie[i]->moveZombie(window, deltaTime);
            }


        }

        //--------SUNS-----------//

        for (int i = 0; i < 45; i++) {

            if (sun[i] == nullptr)
                continue;

            for (int j = 0; j < 5; j++) {

                if (sun[i][j] == nullptr)
                    continue;

                if (sun[i][j]->getClicked()) {

                    delete sun[i][j];
                    sun[i][j] = nullptr;

                    cout << "Total Suns: " << Sun::totalSuns << endl;
                } else
                    sun[i][j]->drawSun(window);


            }


        }




        //---------ICONS---------------------//

        for (int i = 0; i < 7; i++) {
            if (icons[i] == nullptr)
                continue;

            icons[i]->drawIcon(window);

        }

        window.draw(TotalSuns);

        window.draw(Lives);


        window.setSize(sf::Vector2u(256 * scale, 192 * scale));
        window.display();
    }

}