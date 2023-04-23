#ifndef TIPKR_SNAKE_H
#define TIPKR_SNAKE_H

#include <SFML/Graphics.hpp>


class Snake {
public:
    Snake();
    void init();
    void initmultiplayer();
    void grow();
    void move(sf::RenderWindow &window);
    void setdirection(int dir);
    int getdirection();
    void setspeed(float spd);
    void setposition(sf::Vector2f pos);
    void setsize (sf::Vector2f size);
    void setColor(sf::Color color,sf::Color color2);
    int getlength();
    sf::Vector2f getsize();
    sf::RectangleShape getsnakehead();
    sf::RectangleShape getsnakebody();
    sf::RectangleShape getsnakebody(int i);


private:
    int direction;
    int length = 3;
    float speed = 0.1;
    sf::Vector2f size = sf::Vector2f(20, 20);
    sf::RectangleShape snakehead;
    sf::RectangleShape *snakebody = new sf::RectangleShape[length];
    sf::Clock clock;

};


#endif //TIPKR_SNAKE_H
