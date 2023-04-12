#ifndef TIPKR_INPUT_H
#define TIPKR_INPUT_H

#include "SFML/Graphics.hpp"

class Input {
public:
    Input();
    void init();
    void HandleInput(sf::RenderWindow &window, sf::Event &event);




private:

};


#endif //TIPKR_INPUT_H
