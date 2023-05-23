#include <cmath>
#include "Game.h"

Game::Game() {

    window.create(sf::VideoMode(800, 600), "Snake",sf::Style::Titlebar  | sf::Style::Resize  | sf::Style::Close, sf::ContextSettings(0, 0, 8));
    window.setFramerateLimit(60);

    SPstart.setSize(sf::Vector2f(200.f, 100.f));
    SPstart.setPosition(window.getSize().x / 2 - SPstart.getSize().x / 2, window.getSize().y / 2 - 100);
    SPstart.setFillColor(sf::Color::Green);
    SPstart.setOutlineColor(sf::Color::White);
    SPstart.setOutlineThickness(-2);

    MPstart.setSize(sf::Vector2f(200, 100));
    MPstart.setPosition(window.getSize().x / 2 - MPstart.getSize().x / 2, window.getSize().y / 2);
    MPstart.setFillColor(sf::Color::Red);
    MPstart.setOutlineColor(sf::Color::White);
    MPstart.setOutlineThickness(-2);

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
    snake2.initmultiplayer();
    food.init();
    score.init();
    score2.init();
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
                if (event.mouseButton.x >= (SPstart.getPosition().x ) && event.mouseButton.x <= (SPstart.getPosition().x + SPstart.getSize().x) && !isStarted && !isPaused && !isEnd) {
                    if (event.mouseButton.y >= (SPstart.getPosition().y ) && event.mouseButton.y <= (SPstart.getPosition().y + SPstart.getSize().y)) {
                        std::cout << "Single Player button clicked" << std::endl;
                        isStarted = true;
                        isSinglePlayer = true;
                        break;
                    }
                }
                if (event.mouseButton.x >= (MPstart.getPosition().x ) && event.mouseButton.x <= (MPstart.getPosition().x + MPstart.getSize().x) && !isStarted && !isPaused && !isEnd) {
                    if (event.mouseButton.y >= (MPstart.getPosition().y ) && event.mouseButton.y <= (MPstart.getPosition().y + MPstart.getSize().y)) {
                        std::cout << "Multi Player button clicked" << std::endl;
                        isStarted = true;
                        isSinglePlayer = false;
                        break;
                    }
                }
                if (event.mouseButton.x >= (resumeButton.getPosition().x ) && event.mouseButton.x <= (resumeButton.getPosition().x + resumeButton.getSize().x) && isPaused && !isEnd) {
                    if (event.mouseButton.y >= (resumeButton.getPosition().y ) && event.mouseButton.y <= (resumeButton.getPosition().y + resumeButton.getSize().y)) {
                        std::cout << "Resume button clicked" << std::endl;
                        isPaused = false;
                        break;
                    }
                }
                if ((event.mouseButton.x >= (endButton.getPosition().x) && event.mouseButton.x <= (endButton.getPosition().x + endButton.getSize().x) && isPaused) || (event.mouseButton.x >= (endButton.getPosition().x) && event.mouseButton.x <= (endButton.getPosition().x + endButton.getSize().x) && isEnd)) {
                    if (event.mouseButton.y >= (endButton.getPosition().y ) && event.mouseButton.y <= (endButton.getPosition().y + endButton.getSize().y)) {
                        std::cout << "End button clicked" << std::endl;
                        reset();
                        isStarted = false;
                        isPaused = false;
                        isEnd = false;
                        break;
                    }
                }
                if (event.mouseButton.x >= (HardCheckBox.getPosition().x ) && event.mouseButton.x <= (HardCheckBox.getPosition().x + HardCheckBox.getSize().x) && !isStarted && !isPaused && !isEnd) {
                    if (event.mouseButton.y >= (HardCheckBox.getPosition().y ) && event.mouseButton.y <= (HardCheckBox.getPosition().y + HardCheckBox.getSize().y)) {
                        std::cout << "Hard mode button clicked" << std::endl;
                        isHard = !isHard;
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
            if (event.key.code == sf::Keyboard::W) {
                if (snake2.getdirection() != 2) {
                    snake2.setdirection(0);
                }
            }
            if (event.key.code == sf::Keyboard::D) {
                if (snake2.getdirection() != 3) {
                    snake2.setdirection(1);
                }
            }
            if (event.key.code == sf::Keyboard::S) {
                if (snake2.getdirection() != 0) {
                    snake2.setdirection(2);
                }
            }
            if (event.key.code == sf::Keyboard::A) {
                if (snake2.getdirection() != 1) {
                    snake2.setdirection(3);
                }
            }
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                if (isStarted && !isEnd) {
                    if (isPaused) {
                        isPaused = false;
                    } else {
                        isPaused = true;
                        drawPauseScreen();
                    }
                }
            }
        }
        //test func
//        if (event.type == sf::Event::KeyPressed) {
//            if (event.key.code == sf::Keyboard::Space) {
//                snake.grow();
//                score.setScore(score.getScoreValue() + 10);
//                if (score.getScoreValue() % 10 == 0) {
//                    speed = speed - 1;
//                }
//            }
//        }
    }
}

void Game::render() {
    renderer.renderclear(window);
    if (!isStarted) {
        drawWelcomeScreen();
    }
    if (isStarted) {
        if (isEnd) {
            drawEndScreen();
        } else {
            if (isPaused) {
                drawPauseScreen();
            } else {
                if (isSinglePlayer) {
                    drawSPGame();
                } else {
                    drawMPGame();
                }

            }
        }
    }

    renderer.renderdisplay(window);
}

void Game::reset() {
    speed = 100;
    if (isSinglePlayer) {
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
    } else {
        snake.init();
        snake2.initmultiplayer();
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
        score2.init();
    }
}

void Game::checkCollisionSP() {
    //check collision with borders
    if (snake.getsnakehead().getPosition().x < 0) {
        snake.setposition(sf::Vector2f(getWindowsize().x - 20, snake.getsnakehead().getPosition().y));
    }
    if (snake.getsnakehead().getPosition().x > getWindowsize().x - 20) {
        snake.setposition(sf::Vector2f(0, snake.getsnakehead().getPosition().y));
    }
    if (snake.getsnakehead().getPosition().y < 0) {
        snake.setposition(sf::Vector2f(snake.getsnakehead().getPosition().x, getWindowsize().y - 20));
    }
    if (snake.getsnakehead().getPosition().y > getWindowsize().y - 20) {
        snake.setposition(sf::Vector2f(snake.getsnakehead().getPosition().x, 0));
    }
    //check collision with body
    for (int i = 0; i < snake.getlength(); i++) {
        if (snake.getsnakehead().getPosition() == snake.getsnakebody(i).getPosition()) {
            reset();
        }
    }
    //check collision with food
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
        if (score.getScoreValue() % 10 == 0) {   //increase speed every 10 points
            speed = speed - 1;
        }
    }
    //check food position
    if (food.getfood().getPosition().y > getWindowsize().y - 20) {
        sf::Vector2f temp = sf::Vector2f(rand() % (getWindowsize().x - 40), rand() % (getWindowsize().y - 40));
        if (std::fmod(temp.x, 20.0f) != 0.0f) {
            temp.x = temp.x - std::fmod(temp.x, 20.0f);
        }
        if (std::fmod(temp.y, 20.0f) != 0.0f) {
            temp.y = temp.y - std::fmod(temp.y, 20.0f);
        }
        food.setposition(temp);
    }
    if ((food.getfood().getPosition().x > getWindowsize().x - 20) || (food.getfood().getPosition().y < 0) || (food.getfood().getPosition().y > getWindowsize().y - 20) || (food.getfood().getPosition().x < 0)) {
        sf::Vector2f temp = sf::Vector2f(rand() % (getWindowsize().x - 40), rand() % (getWindowsize().y - 40));
        if (std::fmod(temp.x, 20.0f) != 0.0f) {
            temp.x = temp.x - std::fmod(temp.x, 20.0f);
        }
        if (std::fmod(temp.y, 20.0f) != 0.0f) {
            temp.y = temp.y - std::fmod(temp.y, 20.0f);
        }
        food.setposition(temp);
    }
}


void Game::checkCollisionMP() {

    if (snake.getsnakehead().getPosition().x < 0) {
        snake.setposition(sf::Vector2f(getWindowsize().x - 20, snake.getsnakehead().getPosition().y));
    }
    if (snake.getsnakehead().getPosition().x > getWindowsize().x - 20) {
        snake.setposition(sf::Vector2f(0, snake.getsnakehead().getPosition().y));
    }
    if (snake.getsnakehead().getPosition().y < 0) {
        snake.setposition(sf::Vector2f(snake.getsnakehead().getPosition().x, getWindowsize().y - 20));
    }
    if (snake.getsnakehead().getPosition().y > getWindowsize().y - 20) {
        snake.setposition(sf::Vector2f(snake.getsnakehead().getPosition().x, 0));
    }

    for (int i = 0; i < snake.getlength(); i++) {
        if (snake.getsnakehead().getPosition() == snake.getsnakebody(i).getPosition()) {
            reset();
            isEnd = true;
            winnerisPlayer2 = false;
        }
    }

    if (snake2.getsnakehead().getPosition().x < 0) {
        snake2.setposition(sf::Vector2f(getWindowsize().x - 20, snake2.getsnakehead().getPosition().y));
    }
    if (snake2.getsnakehead().getPosition().x > getWindowsize().x - 20) {
        snake2.setposition(sf::Vector2f(0, snake2.getsnakehead().getPosition().y));
    }
    if (snake2.getsnakehead().getPosition().y < 0) {
        snake2.setposition(sf::Vector2f(snake2.getsnakehead().getPosition().x, getWindowsize().y - 20));
    }
    if (snake2.getsnakehead().getPosition().y > getWindowsize().y - 20) {
        snake2.setposition(sf::Vector2f(snake2.getsnakehead().getPosition().x, 0));
    }

    for (int i = 0; i < snake2.getlength(); i++) {
        if (snake2.getsnakehead().getPosition() == snake2.getsnakebody(i).getPosition()) {
            reset();
            isEnd = true;
            winnerisPlayer2 = true;
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
        if (score.getScoreValue() % 10 == 0) {
            speed = speed - 1;
        }
    }

    if (snake2.getsnakehead().getGlobalBounds().intersects(food.getfood().getGlobalBounds())) {
        snake2.grow();
        sf::Vector2f temp = sf::Vector2f(rand() % (getWindowsize().x - 40), rand() % (getWindowsize().y - 40));
        if (std::fmod(temp.x, 20.0f) != 0.0f) {
            temp.x = temp.x - std::fmod(temp.x, 20.0f);
        }
        if (std::fmod(temp.y, 20.0f) != 0.0f) {
            temp.y = temp.y - std::fmod(temp.y, 20.0f);
        }
        food.setposition(temp);
        score2.setScore(score2.getScoreValue() + 1);
        if (score2.getScoreValue() % 10 == 0) {
            speed = speed - 1;
        }
    }

    if (food.getfood().getPosition().y > getWindowsize().y - 20) {
        sf::Vector2f temp = sf::Vector2f(rand() % (getWindowsize().x - 40), rand() % (getWindowsize().y - 40));
        if (std::fmod(temp.x, 20.0f) != 0.0f) {
            temp.x = temp.x - std::fmod(temp.x, 20.0f);
        }
        if (std::fmod(temp.y, 20.0f) != 0.0f) {
            temp.y = temp.y - std::fmod(temp.y, 20.0f);
        }
        food.setposition(temp);
    }

    for (int i = 0; i < snake2.getlength(); i++) {
        if (snake.getsnakehead().getPosition() == snake2.getsnakebody(i).getPosition()) {
            reset();
            isEnd = true;
            winnerisPlayer2 = false;
        }
    }

    for (int i = 0; i < snake.getlength(); i++) {
        if (snake2.getsnakehead().getPosition() == snake.getsnakebody(i).getPosition()) {
            reset();
            isEnd = true;
            winnerisPlayer2 = true;
        }
    }

}


void Game::drawWelcomeScreen() {
    SPstart.setSize(sf::Vector2f(200.f, 100.f));
    SPstart.setPosition(window.getSize().x / 2 - SPstart.getSize().x / 2, window.getSize().y / 2 - 100);
    SPstart.setFillColor(sf::Color::Green);
    SPstart.setOutlineColor(sf::Color::White);
    SPstart.setOutlineThickness(-2);

    MPstart.setSize(sf::Vector2f(200.f, 100.f));
    MPstart.setPosition(window.getSize().x / 2 - MPstart.getSize().x / 2, window.getSize().y / 2 + 50);
    MPstart.setFillColor(sf::Color::Green);
    MPstart.setOutlineColor(sf::Color::White);
    MPstart.setOutlineThickness(-2);

    if (isHard) {
        HardCheckBox.setFillColor(sf::Color::Green);
    }
    else {
        HardCheckBox.setFillColor(sf::Color::Red);
    }
    HardCheckBox.setSize(sf::Vector2f(20.f, 20.f));
    HardCheckBox.setPosition(window.getSize().x / 2 - SPstart.getSize().x / 2 + 50, window.getSize().y / 2 - 150);
    HardCheckBox.setOutlineColor(sf::Color::White);
    HardCheckBox.setOutlineThickness(-2);

    sf::Font font;
    if (!font.loadFromFile("data/arial.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    sf::Text text;
    sf::Text text1;
    sf::Text SPstartButtontext;
    sf::Text MPstartButtontext;
    sf::Text HardCheckBoxText;

    text.setFont(font);
    text.setString("Welcome to Snake");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(window.getSize().x/2 - 100, window.getSize().y/2 - 200);

    text1.setFont(font);
    text1.setString("@Created as a course work for MIREA by Ivan Maltsev");
    text1.setCharacterSize(24);
    text1.setFillColor(sf::Color::White);
    text1.setPosition(window.getSize().x/2 - 300, window.getSize().y - 100);

    SPstartButtontext.setFont(font);
    SPstartButtontext.setString("Single Player");
    SPstartButtontext.setCharacterSize(24);
    SPstartButtontext.setFillColor(sf::Color::White);
    SPstartButtontext.setOutlineColor(sf::Color::Black);
    SPstartButtontext.setOutlineThickness(1);
    SPstartButtontext.setPosition(SPstart.getPosition().x + 25, SPstart.getPosition().y + 35);

    MPstartButtontext.setFont(font);
    MPstartButtontext.setString("Multi Player");
    MPstartButtontext.setCharacterSize(24);
    MPstartButtontext.setFillColor(sf::Color::White);
    MPstartButtontext.setOutlineColor(sf::Color::Black);
    MPstartButtontext.setOutlineThickness(1);
    MPstartButtontext.setPosition(MPstart.getPosition().x + 35, MPstart.getPosition().y + 35);

    HardCheckBoxText.setFont(font);
    HardCheckBoxText.setString("Hard Mode");
    HardCheckBoxText.setCharacterSize(24);
    HardCheckBoxText.setFillColor(sf::Color::White);
    HardCheckBoxText.setOutlineColor(sf::Color::Black);
    HardCheckBoxText.setOutlineThickness(1);
    HardCheckBoxText.setPosition(HardCheckBox.getPosition().x + 35, HardCheckBox.getPosition().y - 5);

    window.draw(text);
    window.draw(text1);
    window.draw(SPstart);
    window.draw(MPstart);
    window.draw(SPstartButtontext);
    window.draw(MPstartButtontext);
    window.draw(HardCheckBox);
    window.draw(HardCheckBoxText);
}

void Game::drawPauseScreen() {
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

    window.draw(text);
    window.draw(resumeButton);
    window.draw(endButton);
    window.draw(resumeButtontext);
    window.draw(endButtontext);
}

void Game::drawSPGame() {
    renderer.renderscore(window, score.getScore());
    checkCollisionSP();
    if (clock.getElapsedTime().asMilliseconds() > 100 && !isHard) {
        snake.move(window);
        clock.restart();
    }
    else if (isHard) {
        if (clock.getElapsedTime().asMilliseconds() > speed) {
            if (speed < 25) {
                speed = 25;
            }
            snake.move(window);
            clock.restart();
        }
    }
    renderer.renderfood(window, food.getfood());
    window.draw(snake.getsnakehead());
    for (int i = 0; i < snake.getlength(); i++) {
        window.draw(snake.getsnakebody(i));
    }
}

void Game::drawMPGame() {
    renderer.renderscore(window, score.getScore(), score2.getScore());
    checkCollisionMP();
    if (clock.getElapsedTime().asMilliseconds() > 100 && !isHard) {
        snake.move(window);
        snake2.setColor(sf::Color::Blue, sf::Color::Cyan);
        snake2.move(window);
        clock.restart();
    }
    else if (isHard) {
        if (clock.getElapsedTime().asMilliseconds() > speed) {
            if (speed < 25) {
                speed = 25;
            }
            snake.move(window);
            snake2.setColor(sf::Color::Blue, sf::Color::Cyan);
            snake2.move(window);
            clock.restart();
        }
    }
        renderer.renderfood(window, food.getfood());
        window.draw(snake.getsnakehead());
        for (int i = 0; i < snake.getlength(); i++) {
            window.draw(snake.getsnakebody(i));
        }
        window.draw(snake2.getsnakehead());
        for (int i = 0; i < snake2.getlength(); i++) {
            window.draw(snake2.getsnakebody(i));
        }

}

void Game::drawEndScreen() {
    sf::Font font;
    if (!font.loadFromFile("data/arial.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    sf::Text text;
    sf::Text text1;
    sf::Text EndButtontext;
    text.setFont(font);
    if (winnerisPlayer2) {
        text.setString("Player 1 wins");
    } else {
        text.setString("Player 2 wins");
    }
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(window.getSize().x/2 - 50, window.getSize().y/2 - 200);

    text1.setFont(font);
    text1.setString("Player 1 score: " + std::to_string(score.getScoreValue()) + "\n" + "Player 2 score: " + std::to_string(score2.getScoreValue()));
    text1.setCharacterSize(24);
    text1.setFillColor(sf::Color::White);
    text1.setPosition(window.getSize().x/2 - 200, window.getSize().y/2 - 100);

    EndButtontext.setFont(font);
    EndButtontext.setString("End");
    EndButtontext.setCharacterSize(24);
    EndButtontext.setFillColor(sf::Color::White);
    EndButtontext.setOutlineColor(sf::Color::Black);
    EndButtontext.setOutlineThickness(1);
    EndButtontext.setPosition(endButton.getPosition().x + 74, endButton.getPosition().y + 35);

    endButton.setSize(sf::Vector2f(200, 100));
    endButton.setPosition(window.getSize().x/2 - endButton.getSize().x/2,  window.getSize().y/2 );
    endButton.setFillColor(sf::Color::Red);
    endButton.setOutlineColor(sf::Color::White);
    endButton.setOutlineThickness(-2);

    window.draw(text);
    window.draw(text1);
    window.draw(endButton);
    window.draw(EndButtontext);
}