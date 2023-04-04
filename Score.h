//
// Created by VeiTr on 27.03.2023.
//

#ifndef TIPKR_SCORE_H
#define TIPKR_SCORE_H

#include "libs/SDL2-2.26.4/x86_64-w64-mingw32/include/SDL2/SDL.h"



class Score {
public:
    Score(); // конструктор класса
    void Init(SDL_Renderer* renderer); // инициализация счета
    void Render(SDL_Renderer* renderer); // отрисовать счет
    void IncreaseScore(int points); // увеличить счет на заданное количество очков
    int GetScore(); // получить текущий счет игрока
    SDL_Texture* GetText();
    SDL_Texture* font;
    SDL_Texture* text;
private:
    int score; // текущий счет игрока

};



#endif //TIPKR_SCORE_H
