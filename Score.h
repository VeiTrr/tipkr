#ifndef TIPKR_SCORE_H
#define TIPKR_SCORE_H


#include <SFML/Graphics.hpp>

class Score {
public:
    Score();
    void init();
    void setposition(sf::Vector2f pos);
    void setScore(int score);
    sf::Text getScore();
    int getScoreValue();

private:
    sf::Text score;
    sf::Font font;
    sf::Vector2f position = sf::Vector2f(0, 0);
    int scoreValue = 0;

};


#endif //TIPKR_SCORE_H
