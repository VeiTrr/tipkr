#include "Score.h"

Score::Score() {
    init();
}

void Score::init() {
    font.loadFromFile("data/arial.ttf");
    score.setFont(font);
    score.setCharacterSize(24);
    score.setFillColor(sf::Color::White);
    score.setPosition(position);
    setScore(0);
}

void Score::setposition(sf::Vector2f pos) {
    position = pos;
    score.setPosition(position);
}

void Score::setScore(int score) {
    scoreValue = score;
    std::string temp = std::to_string(score);
    this->score.setString("Score: " + temp);
}

sf::Text Score::getScore() {
    return score;
}

int Score::getScoreValue() {
    return scoreValue;
}

