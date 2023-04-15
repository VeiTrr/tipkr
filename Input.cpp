#include "Input.h"

Input::Input() {
}

void Input::init() {
}

void Input::HandleInput(sf::RenderWindow &window, sf::Event &event) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
    if (event.type == sf::Event::Resized) {
        window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
    }
}
