#include "Renderer.h"

Renderer::Renderer() {
}

void Renderer::init() {
}

void Renderer::renderclear(sf::RenderWindow &window) {
    window.clear();
}

void Renderer::renderfood(sf::RenderWindow &window, sf::RectangleShape food) {
    window.draw(food);
}

void Renderer::renderscore(sf::RenderWindow &window, sf::Text Score) {
    window.draw(Score);
}

void Renderer::renderscore(sf::RenderWindow &window, sf::Text Score, sf::Text Score2) {
    Score.setPosition(window.getSize().x/2 - 150, 0);
    window.draw(Score);
    Score2.setPosition(window.getSize().x/2 + 50, 0);
    window.draw(Score2);
}

void Renderer::renderdisplay(sf::RenderWindow &window) {
    window.display();
}



