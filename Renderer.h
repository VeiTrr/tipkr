#ifndef TIPKR_RENDERER_H
#define TIPKR_RENDERER_H


#include <SFML/Graphics.hpp>

class Renderer {
public:
    Renderer();
    void init();
    void renderclear(sf::RenderWindow &window);
    void renderscore(sf::RenderWindow &window, sf::Text Score);
    void renderscore(sf::RenderWindow &window, sf::Text Score, sf::Text Score2);
    void renderfood(sf::RenderWindow &window, sf::RectangleShape food);
    void renderdisplay(sf::RenderWindow &window);

};


#endif //TIPKR_RENDERER_H
