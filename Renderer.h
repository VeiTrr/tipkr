#ifndef TIPKR_RENDERER_H
#define TIPKR_RENDERER_H

#include "Snake.h"
#include "Food.h"
#include "Score.h"
#include "libs/SDL2-2.26.4/x86_64-w64-mingw32/include/SDL2/SDL.h"
#include "libs/SDL2_ttf-2.20.2//x86_64-w64-mingw32/include/SDL2/SDL_ttf.h"

class Renderer {
public:
    Renderer(int screenWidth, int screenHeight); // конструктор класса
    static void RenderRect(SDL_Renderer* renderer, SDL_Rect rect); // отрисовать прямоугольник
    void RenderSnake(Snake& snake); // отрисовать змейку
    void RenderFood(Food& food); // отрисовать еду
    void RenderScore(Score& score); // отрисовать текущий счет игрока
    void RenderGameBoard(); // отрисовать игровое поле
    void Render(); // отрисовать все элементы игры

private:
    int screenWidth; // ширина окна игры
    int screenHeight; // высота окна игры
    SDL_Window* window; // указатель на окно игры
    SDL_Renderer* renderer; // указатель на рендер игры
    SDL_Rect gameBoardRect; // прямоугольник игрового поля
};


#endif //TIPKR_RENDERER_H
