#ifndef TIPKR_GAME_H
#define TIPKR_GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Snake.h"
#include "Food.h"
#include "Score.h"
#include "Input.h"
#include "Renderer.h"


class Game {
public:
    Game();
    void run();
    sf::Vector2i getWindowsize();

private:
    void drawWelcomeScreen();
    void drawPauseScreen();
    void drawGame();
    void processEvents();
    void render();
    void reset();
    void checkCollision();
    sf::RenderWindow window;
    sf::RectangleShape startButton;
    sf::RectangleShape resumeButton;
    sf::RectangleShape endButton;
    bool isStarted = false;
    bool isPaused = false;
    Snake snake;
    Food food;
    Score score;
    Input input;
    Renderer renderer;
    sf::Clock clock;
    sf::Image icon;
};


#endif //TIPKR_GAME_H
