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
    void drawSPGame();
    void drawMPGame();
    void drawEndScreen();
    void processEvents();
    void render();
    void reset();
    void checkCollisionSP();
    void checkCollisionMP();
    sf::RenderWindow window;
    sf::RectangleShape SPstart; //single player start
    sf::RectangleShape MPstart; //multi player start
    sf::RectangleShape resumeButton;
    sf::RectangleShape endButton;
    bool isStarted = false;
    bool isPaused = false;
    bool isSinglePlayer = false;
    bool winnerisPlayer2 = false;
    bool isEnd = false;
    Snake snake;
    Snake snake2;
    Food food;
    Score score;
    Score score2;
    Score endscore;
    Score endscore2;
    Input input;
    Renderer renderer;
    sf::Clock clock;
    sf::Image icon;
};


#endif //TIPKR_GAME_H
