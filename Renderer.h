#ifndef TIPKR_RENDERER_H
#define TIPKR_RENDERER_H

#include "Snake.h"
#include "Food.h"
#include "Score.h"

class Renderer {
public:
    Renderer(int screenWidth, int screenHeight); // конструктор класса
    void RenderSnake(Snake& snake); // отрисовать змейку
    void RenderFood(Food& food); // отрисовать еду
    void RenderScore(Score& score); // отрисовать текущий счет игрока
    void RenderGameBoard(); // отрисовать игровое поле
    void Render(); // отрисовать все элементы игры

private:
    int screenWidth; // ширина окна игры
    int screenHeight; // высота окна игры
};


#endif //TIPKR_RENDERER_H
