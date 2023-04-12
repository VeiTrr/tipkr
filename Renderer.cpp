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

void Renderer::renderdisplay(sf::RenderWindow &window) {
    window.display();
}



