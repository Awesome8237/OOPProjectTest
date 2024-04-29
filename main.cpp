#include <SFML/Graphics.hpp>
#include <ctime>
//#include"../SFML/Images/"
using namespace sf;
using namespace std;


struct coordinats {
    int x;
    int y;
};

class Bullet{

public:

    Image spritesheet;
    Texture bullettexture;
    Sprite bulletsprite;
    float velocity;

    float x, y;



    Bullet(){


        spritesheet.loadFromFile("Images/peashooter_sheet_test.png");

        bullettexture.loadFromImage(spritesheet);

        bulletsprite.setTexture(bullettexture);
        IntRect rectbulletSprite(256,63,10,10);
        bulletsprite.setTextureRect(rectbulletSprite);


        bulletsprite.scale(1,1);




    }

    void fire(){

        bulletsprite.setPosition(100,100);

        x = 100;

        y = 100;

        velocity = 70;

    }

    void moveBullet(RenderWindow& window,Time &bulletTime){

        bulletsprite.setPosition((x += velocity * bulletTime.asSeconds()),y);
        window.draw(bulletsprite);


    }

    bool isOutside(){

        if(x > 600){
            return true;
        }
        else{
            return false;
        }


    }

    Bullet& operator=(Bullet& copy){

        spritesheet.loadFromFile("Images/peashooter_sheet_test.png");

        bullettexture.loadFromImage(spritesheet);

        bulletsprite.setTexture(bullettexture);
        IntRect rectbulletSprite(256,63,10,10);
        bulletsprite.setTextureRect(rectbulletSprite);


        bulletsprite.scale(1,1);

        velocity = copy.velocity;
        x = copy.x;
        y = copy.y;

        return *this;



    }




};

class Zombie{

public:

    Image zombspritesheet;
    Texture zombtexture;
    Sprite zombsprite;
    float velocity;

    int health;


    Clock animationClock;

    float x, y;



    Zombie(){


        zombspritesheet.loadFromFile("Images/zombie_sheet_test.png");

        zombtexture.loadFromImage(zombspritesheet);

        zombsprite.setTexture(zombtexture);
        zombsprite.setTextureRect(IntRect(0,59,42,54));


        zombsprite.setPosition(200,100);

        x = 200;

        y = 100;

        velocity = 5;

        health = 120;


        zombsprite.scale(1,1);




    }


    void moveZombie(RenderWindow& window,Time &ZombTime){


        zombsprite.setPosition((x -= velocity * ZombTime.asSeconds()),y);

        if(animationClock.getElapsedTime().asSeconds() > 0.5f){

            if(zombsprite.getTextureRect().left == 300)
                zombsprite.setTextureRect(IntRect(0,59,42,54));
            else
                zombsprite.setTextureRect(IntRect(zombsprite.getTextureRect().left + 50,59,42,54));


            animationClock.restart();

        }

        window.draw(zombsprite);


    }

    bool isOutside(){

        if(x > 600){
            return true;
        }
        else{
            return false;
        }


    }




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

    Bullet bullet[10];

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
                bullet[currentbullets].fire();
                currentbullets++;
                fireClock.restart();
            }

        }

        for(int i = 0; i < currentbullets; i++) {

            if(bullet[i].x <= zombie.x + 42 && bullet[i].x + 10 >= zombie.x){

                bullet[i].x = 1300;
                zombie.health -= 30;

            }

            if (bullet[i].isOutside()) {

                Bullet temp[10];

                for(int i = 0; i < currentbullets; i++){

                    if(bullet[i].isOutside()){
                        continue;
                    }

                    temp[i] = bullet[i];


                }
                currentbullets--;
                for(int i = 0; i < currentbullets; i++){

                    bullet[i] = temp[i];


                }


            }
            else{

                bullet[i].moveBullet(window, bulletTime);

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