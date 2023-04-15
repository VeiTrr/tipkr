#include <cmath>
#include "Game.h"

Game::Game() {

    window.create(sf::VideoMode(800, 600), "Snake",sf::Style::Titlebar  | sf::Style::Resize  | sf::Style::Close, sf::ContextSettings(0, 0, 8));
    window.setFramerateLimit(60);
    startButton.setSize(sf::Vector2f(200.f, 100.f));
    startButton.setPosition(window.getSize().x/2 - startButton.getSize().x/2,  window.getSize().y/2 - 100);
    startButton.setFillColor(sf::Color::Green);
    startButton.setOutlineColor(sf::Color::White);
    startButton.setOutlineThickness(-2);
    resumeButton.setSize(sf::Vector2f(200.f, 100.f));
    resumeButton.setPosition(window.getSize().x/2 - resumeButton.getSize().x/2,  window.getSize().y/2 - 103);
    resumeButton.setFillColor(sf::Color::Green);
    resumeButton.setOutlineColor(sf::Color::White);
    resumeButton.setOutlineThickness(-2);
    endButton.setSize(sf::Vector2f(200, 100));
    endButton.setPosition(window.getSize().x/2 - endButton.getSize().x/2,  window.getSize().y/2 );
    endButton.setFillColor(sf::Color::Red);
    endButton.setOutlineColor(sf::Color::White);
    endButton.setOutlineThickness(-2);
    icon.loadFromFile("data/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Game::run() {

    snake.init();
    food.init();
    score.init();
    sf::Vector2<float> temp = sf::Vector2f(rand() % (getWindowsize().x - 40), rand() % (getWindowsize().y - 40));
    if (std::fmod(temp.x, 20.0f) != 0.0f) {
        temp.x = temp.x - std::fmod(temp.x, 20.0f);
    }
    if (std::fmod(temp.y, 20.0f) != 0.0f) {
        temp.y = temp.y - std::fmod(temp.y, 20.0f);
    }
    food.setposition(temp);
    while (window.isOpen()) {
        processEvents();
        render();
    }
}

sf::Vector2i Game::getWindowsize() {
    return sf::Vector2i(window.getSize().x, window.getSize().y);
}

void Game::processEvents() {
    sf::Event event{};
    while (window.pollEvent(event)) {
        input.HandleInput(window, event);
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (event.mouseButton.x >= (startButton.getPosition().x ) && event.mouseButton.x <= (startButton.getPosition().x + startButton.getSize().x) && !isStarted && !isPaused) {
                    if (event.mouseButton.y >= (startButton.getPosition().y ) && event.mouseButton.y <= (startButton.getPosition().y + startButton.getSize().y)) {
                        std::cout << "Start button clicked" << std::endl;
                        isStarted = true;
                        break;
                    }
                }
                if (event.mouseButton.x >= (resumeButton.getPosition().x ) && event.mouseButton.x <= (resumeButton.getPosition().x + resumeButton.getSize().x) && isPaused) {
                    if (event.mouseButton.y >= (resumeButton.getPosition().y ) && event.mouseButton.y <= (resumeButton.getPosition().y + resumeButton.getSize().y)) {
                        std::cout << "Resume button clicked" << std::endl;
                        isPaused = false;
                        break;
                    }
                }
                if (event.mouseButton.x >= (endButton.getPosition().x) && event.mouseButton.x <= (endButton.getPosition().x + endButton.getSize().x) && isPaused) {
                    if (event.mouseButton.y >= (endButton.getPosition().y ) && event.mouseButton.y <= (endButton.getPosition().y + endButton.getSize().y)) {
                        std::cout << "End button clicked" << std::endl;
                        reset();
                        isStarted = false;
                        isPaused = false;
                        break;
                    }
                }
            }
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                if (snake.getdirection() != 2) {
                    snake.setdirection(0);
                }
            }
            if (event.key.code == sf::Keyboard::Right) {
                if (snake.getdirection() != 3) {
                    snake.setdirection(1);
                }
            }
            if (event.key.code == sf::Keyboard::Down) {
                if (snake.getdirection() != 0) {
                    snake.setdirection(2);
                }
            }
            if (event.key.code == sf::Keyboard::Left) {
                if (snake.getdirection() != 1) {
                    snake.setdirection(3);
                }
            }
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                if (isPaused) {
                    isPaused = false;
                } else {
                    isPaused = true;
                    drawPauseScreen();
                }
            }
        }
    }
}

void Game::render() {
    renderer.renderclear(window);
    if (!isStarted) {
        drawWelcomeScreen();
    }
    if (isStarted) {
        if (isPaused) {
            drawPauseScreen();
        } else {
            drawGame();
        }
    }

    renderer.renderdisplay(window);
}

void Game::reset() {
    snake.init();
    food.init();
    sf::Vector2f temp = sf::Vector2f(rand() % (getWindowsize().x - 40), rand() % (getWindowsize().y - 40));
    if (std::fmod(temp.x, 20.0f) != 0.0f) {
        temp.x = temp.x - std::fmod(temp.x, 20.0f);
    }
    if (std::fmod(temp.y, 20.0f) != 0.0f) {
        temp.y = temp.y - std::fmod(temp.y, 20.0f);
    }
    food.setposition(temp);
    score.init();
}

void Game::checkCollision() {
    if (snake.getsnakehead().getPosition().x < 0) {
        snake.setposition(sf::Vector2f(getWindowsize().x, snake.getsnakehead().getPosition().y));
    }
    if (snake.getsnakehead().getPosition().x > getWindowsize().x) {
        snake.setposition(sf::Vector2f(0, snake.getsnakehead().getPosition().y));
    }
    if (snake.getsnakehead().getPosition().y < 0) {
        snake.setposition(sf::Vector2f(snake.getsnakehead().getPosition().x, getWindowsize().y));
    }
    if (snake.getsnakehead().getPosition().y > getWindowsize().y) {
        snake.setposition(sf::Vector2f(snake.getsnakehead().getPosition().x, 0));
    }
    for (int i = 0; i < snake.getlength(); i++) {
        if (snake.getsnakehead().getPosition() == snake.getsnakebody(i).getPosition()) {
            reset();
        }
    }
    if (snake.getsnakehead().getGlobalBounds().intersects(food.getfood().getGlobalBounds())) {
        snake.grow();
        sf::Vector2f temp = sf::Vector2f(rand() % (getWindowsize().x - 40), rand() % (getWindowsize().y - 40));
        if (std::fmod(temp.x, 20.0f) != 0.0f) {
            temp.x = temp.x - std::fmod(temp.x, 20.0f);
        }
        if (std::fmod(temp.y, 20.0f) != 0.0f) {
            temp.y = temp.y - std::fmod(temp.y, 20.0f);
        }
        food.setposition(temp);
        score.setScore(score.getScoreValue() + 1);
    }



}


void Game::drawWelcomeScreen() {
    sf::Font font;
    if (!font.loadFromFile("data/arial.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    sf::Text text;
    sf::Text text1;
    sf::Text startButtontext;
    text.setFont(font);
    text.setString("Welcome to Snake");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(300, 100);
    text1.setFont(font);
    text1.setString("@Created as a course work for MIREA by Ivan Maltsev");
    text1.setCharacterSize(24);
    text1.setFillColor(sf::Color::White);
    text1.setPosition(100, window.getSize().y - 100);
    startButtontext.setFont(font);
    startButtontext.setString("Start");
    startButtontext.setCharacterSize(24);
    startButtontext.setFillColor(sf::Color::White);
    startButtontext.setOutlineColor(sf::Color::Black);
    startButtontext.setOutlineThickness(1);
    startButtontext.setPosition(startButton.getPosition().x + 68, startButton.getPosition().y + 35);


    window.draw(startButton);
    window.draw(text);
    window.draw(text1);
    window.draw(startButtontext);
}

void Game::drawPauseScreen() {
    sf::Font font;
    if (!font.loadFromFile("data/arial.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    sf::Text text;
    sf::Text resumeButtontext;
    sf::Text endButtontext;
    text.setFont(font);
    text.setString("Paused");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2 - 200);
    resumeButtontext.setFont(font);
    resumeButtontext.setString("Resume");
    resumeButtontext.setCharacterSize(24);
    resumeButtontext.setFillColor(sf::Color::White);
    resumeButtontext.setOutlineColor(sf::Color::Black);
    resumeButtontext.setOutlineThickness(1);
    resumeButtontext.setPosition(resumeButton.getPosition().x + 56, resumeButton.getPosition().y + 35);
    endButtontext.setFont(font);
    endButtontext.setString("End");
    endButtontext.setCharacterSize(24);
    endButtontext.setFillColor(sf::Color::White);
    endButtontext.setOutlineColor(sf::Color::Black);
    endButtontext.setOutlineThickness(1);
    endButtontext.setPosition(endButton.getPosition().x + 74, endButton.getPosition().y + 35);

    window.draw(resumeButton);
    window.draw(endButton);
    window.draw(text);
    window.draw(resumeButtontext);
    window.draw(endButtontext);
}

void Game::drawGame() {
    renderer.renderscore(window, score.getScore());
    checkCollision();
    if (clock.getElapsedTime().asSeconds() > 0.1) {
        snake.move(window);
        clock.restart();
    }
    renderer.renderfood(window, food.getfood());
    window.draw(snake.getsnakehead());
    for (int i = 0; i < snake.getlength(); i++) {
        window.draw(snake.getsnakebody(i));
    }
}
