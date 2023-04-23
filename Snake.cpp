#include "Snake.h"

Snake::Snake() {
    init();
}

void Snake::init() {
    snakehead.setSize(getsize());
    snakehead.setPosition(400, 300);
    snakehead.setFillColor(sf::Color(1, 50, 32));
    snakehead.setOutlineColor(sf::Color::White);
    snakehead.setOutlineThickness(-2);
    snakebody[0].setSize(getsize());
    snakebody[0].setPosition(snakehead.getPosition().x,snakehead.getPosition().y + getsize().y);
    snakebody[0].setFillColor(sf::Color::Green);
    snakebody[0].setOutlineColor(sf::Color::Black);
    snakebody[0].setOutlineThickness(1);

    for (int i = 1; i < 3; i++) {
        snakebody[i].setSize(getsize());
        snakebody[i].setPosition(snakebody[i-1].getPosition().x, snakebody[i-1].getPosition().y + getsize().x);
        snakebody[i].setFillColor(sf::Color::Green);
        snakebody[i].setOutlineColor(sf::Color::Black);
        snakebody[i].setOutlineThickness(1);
    }
    length = 3;
    direction = -1;
}

void Snake::initmultiplayer() {
    snakehead.setSize(getsize());
    snakehead.setPosition(200, 300);
    snakehead.setFillColor(sf::Color(1, 50, 32));
    snakehead.setOutlineColor(sf::Color::White);
    snakehead.setOutlineThickness(-2);
    snakebody[0].setSize(getsize());
    snakebody[0].setPosition(snakehead.getPosition().x,snakehead.getPosition().y + getsize().y);
    snakebody[0].setFillColor(sf::Color::Green);
    snakebody[0].setOutlineColor(sf::Color::Black);
    snakebody[0].setOutlineThickness(1);

    for (int i = 1; i < 3; i++) {
        snakebody[i].setSize(getsize());
        snakebody[i].setPosition(snakebody[i-1].getPosition().x, snakebody[i-1].getPosition().y + getsize().x);
        snakebody[i].setFillColor(sf::Color::Green);
        snakebody[i].setOutlineColor(sf::Color::Black);
        snakebody[i].setOutlineThickness(1);
    }
    length = 3;
    direction = -1;
}

void Snake::grow() {
    sf::RectangleShape *temp = new sf::RectangleShape[length + 1];
    for (int i = 0; i < length; i++) {
        temp[i] = snakebody[i];
    }
    temp[length].setSize(getsize());
    temp[length].setPosition(snakebody[length - 1].getPosition().x, snakebody[length - 1].getPosition().y);
    temp[length].setFillColor(sf::Color::Green);
    temp[length].setOutlineColor(sf::Color::Black);
    temp[length].setOutlineThickness(1);
    snakebody = temp;
    length++;
}

void Snake::move(sf::RenderWindow &window) {
    if (direction == 0) {
        sf::Vector2f tempp = snakehead.getPosition() ;
        sf::Vector2f tempp2 = snakebody[0].getPosition();
        snakehead.setPosition(snakehead.getPosition() - sf::Vector2f(0 , getsize().y));
        snakebody[0].setPosition(tempp);
        for (int i = 1; i < length; i++) {
            if (i % 2 == 0) {
                tempp2 = snakebody[i].getPosition();
                snakebody[i].setPosition(tempp);
            }
            else {
                tempp = snakebody[i].getPosition();
                snakebody[i].setPosition(tempp2);
            }
        }
    }
    else if (direction == 1) {
        sf::Vector2f tempp = snakehead.getPosition();
        sf::Vector2f tempp2 = snakebody[0].getPosition();
        snakehead.setPosition(snakehead.getPosition() + sf::Vector2f(getsize().x, 0));
        snakebody[0].setPosition(tempp);
        for (int i = 1; i < length; i++) {
            if (i % 2 == 0) {
                tempp2 = snakebody[i].getPosition();
                snakebody[i].setPosition(tempp);
            }
            else {
                tempp = snakebody[i].getPosition();
                snakebody[i].setPosition(tempp2);
            }
        }
    }
    else if (direction == 2) {
        sf::Vector2f tempp = snakehead.getPosition();
        sf::Vector2f tempp2 = snakebody[0].getPosition();
        snakehead.setPosition(snakehead.getPosition() + sf::Vector2f(0, getsize().y));
        snakebody[0].setPosition(tempp);
        for (int i = 1; i < length; i++) {
            if (i % 2 == 0) {
                tempp2 = snakebody[i].getPosition();
                snakebody[i].setPosition(tempp);
            }
            else {
                tempp = snakebody[i].getPosition();
                snakebody[i].setPosition(tempp2);
            }
        }
    }
    else if (direction == 3) {
        sf::Vector2f tempp = snakehead.getPosition();
        sf::Vector2f tempp2 = snakebody[0].getPosition();
        snakehead.setPosition(snakehead.getPosition() - sf::Vector2f(getsize().x, 0));
        snakebody[0].setPosition(tempp);
        for (int i = 1; i < length; i++) {
            if (i % 2 == 0) {
                tempp2 = snakebody[i].getPosition();
                snakebody[i].setPosition(tempp);
            }
            else {
                tempp = snakebody[i].getPosition();
                snakebody[i].setPosition(tempp2);
            }
        }
    }
}

void Snake::setdirection(int dir) {
    direction = dir;
}

int Snake::getdirection() {
    return direction;
}

void Snake::setspeed(float spd) {
    speed = spd;
}

int Snake::getlength() {
    return length;
}

sf::RectangleShape Snake::getsnakehead() {
    return snakehead;
}


sf::RectangleShape Snake::getsnakebody(int i) {
    return snakebody[i];
}

sf::Vector2f Snake::getsize() {
    return size;
}

void Snake::setposition(sf::Vector2f pos) {
    snakehead.setPosition(pos);
}

void Snake::setsize(sf::Vector2f size) {
    this->size = size;
}

void Snake::setColor(sf::Color color, sf::Color color2) {
    snakehead.setFillColor(color);
    for (int i = 0; i < length; i++) {
        snakebody[i].setFillColor(color2);
    }
}
