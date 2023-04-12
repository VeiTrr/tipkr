#ifndef TIPKR_FOOD_H
#define TIPKR_FOOD_H


#include <SFML/Graphics/RectangleShape.hpp>

class Food {
public:
    Food();
    void init();
    void setposition(sf::Vector2f pos);
    sf::RectangleShape getfood();

private:
    sf::RectangleShape food;
    sf::Vector2f size = sf::Vector2f(20, 20);

};


#endif //TIPKR_FOOD_H
