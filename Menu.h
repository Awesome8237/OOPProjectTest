//
// Created by admin on 5/13/2024.
//

#ifndef SFMLTEST_MENU_H
#define SFMLTEST_MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class GameMenu {
public:
    GameMenu(sf::RenderWindow& window) : window(window), Start(false) {}

    void showInstructionsScreen() {
        // Load instruction screen image
        sf::Texture instructionScreenTexture;
        if (!instructionScreenTexture.loadFromFile("Images/in.jpg")) {
            cout << "Failed to load instruction screen image!" <<endl;
            return;
        }
        sf::Sprite instructionScreen(instructionScreenTexture);

        // Display instruction screen
        sf::RenderWindow instructionsWindow(sf::VideoMode(instructionScreenTexture.getSize().x, instructionScreenTexture.getSize().y), "Instructions");
        while (instructionsWindow.isOpen()) {
            sf::Event event;
            while (instructionsWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    instructionsWindow.close();
            }

            instructionsWindow.clear();
            instructionsWindow.draw(instructionScreen);
            instructionsWindow.display();
        }
    }


    void show() {

        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("Images/menu.jpg")) {
            cout << "Failed to load background image!" << endl;
            return;
        }
        sf::Sprite backgroundSprite(backgroundTexture);
        float scaleX = static_cast<float>(window.getSize().x) / backgroundTexture.getSize().x;
        float scaleY = static_cast<float>(window.getSize().y) / backgroundTexture.getSize().y;
        backgroundSprite.setScale(scaleX, scaleY);
        // Load start button image
        sf::Texture startButtonTexture;
        if (!startButtonTexture.loadFromFile("Images/file.png")) {
            cout << "Failed to load start button image!" << endl;
            return;
        }
        sf::Sprite startButton(startButtonTexture);
        //startButton.setScale(200, 400);
        startButton.setPosition(500, 450);


        sf::Texture instructionButtonTexture;
        if (!instructionButtonTexture.loadFromFile("Images/insbutton.png")) {
            cout << "Failed to load instruction button image!" << endl;
            return;
        }
        sf::Sprite instructionButton(instructionButtonTexture);
        //instructionButton.setScale(240, 93);
        instructionButton.setPosition(975, 650);
        //






        while (window.isOpen() && !Start) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::MouseButtonPressed) {
                    // Check if the start button is clicked
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (startButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {



                    }
                    else if (instructionButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {

                        showInstructionsScreen();

                    }
                }
            }

            window.clear();
            // Draw background
            window.draw(backgroundSprite);
            // Draw start button
            window.draw(startButton);
            window.draw(instructionButton);
            window.display();
        }
    }

private:
    sf::RenderWindow& window;
    bool Start;
};

#endif //SFMLTEST_MENU_H
