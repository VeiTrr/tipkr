#include "Input.h"

Input::Input() {
}

void Input::init() {
}

void Input::HandleInput(sf::RenderWindow &window, sf::Event &event) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
}
