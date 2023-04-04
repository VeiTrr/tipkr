//
// Created by VeiTr on 27.03.2023.
//

#ifndef TIPKR_FOOD_H
#define TIPKR_FOOD_H

#include "libs/SDL2-2.26.4/x86_64-w64-mingw32/include/SDL2/SDL.h"


class Food {
public:
    Food(); // конструктор класса
    void Init(SDL_Renderer* renderer); // инициализация еды
    void Render(SDL_Renderer* renderer); // отрисовка еды
    int GetX(); // получить координату X еды
    int GetY(); // получить координату Y еды
    void Randomize(); // рандомизировать координаты еды
    void Spawn(SDL_Renderer* renderer, int tileSize, int screenWidth, int screenHeight); // отображение еды на игровом поле
    SDL_Rect GetPosition(); // получить координаты еды
    SDL_Rect rect;
private:
    SDL_Rect position; // координаты еды на игровом поле
};



#endif //TIPKR_FOOD_H
