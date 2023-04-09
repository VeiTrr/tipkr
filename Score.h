#ifndef TIPKR_SCORE_H
#define TIPKR_SCORE_H

#include <iostream>



class Score {
public:
    Score(); // конструктор класса
    void Init(); // инициализация счета
    void Render(); // отрисовать счет
    void IncreaseScore(int points); // увеличить счет на заданное количество очков
    int GetScore(); // получить текущий счет игрока
    char GetText();
    std::type_info font;
    std::string text;
private:
    int score; // текущий счет игрока

};



#endif //TIPKR_SCORE_H
