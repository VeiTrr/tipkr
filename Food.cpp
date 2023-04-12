#include "Food.h"

Food::Food() {
    init();
}

void Food::init() {
    food.setSize(size);
    food.setFillColor(sf::Color::Red);
    food.setOutlineColor(sf::Color::White);
    food.setOutlineThickness(-2);
}

void Food::setposition(sf::Vector2f pos) {
    food.setPosition(pos);
}

sf::RectangleShape Food::getfood() {
    return food;
}


