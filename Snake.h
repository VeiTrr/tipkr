//
// Created by VeiTr on 27.03.2023.
//

#ifndef TIPKR_SNAKE_H
#define TIPKR_SNAKE_H


#include <vector>
#include "Input.h"
#include "libs/SDL2-2.26.4/x86_64-w64-mingw32/include/SDL2/SDL.h"

class Snake {
public:
    Snake(); // конструктор класса
    void Init(SDL_Renderer* renderer); // инициализация змейки
    void Render(SDL_Renderer* renderer); // отрисовка змейки на игровом поле
    void Update(); // обновление состояния змейки
    int GetHeadX(); // получить текущую координату X головы змейки
    int GetHeadY(); // получить текущую координату Y головы змейки
    void Grow(); // увеличить длину змейки
    void Move(); // перемещение змейки на игровом поле
    void HandleInput(Input input); // обработка ввода пользователя
    bool CheckCollision(); // проверка на столкновение змейки со стенами или своим телом
    std::vector<SDL_Rect> GetBody(); // получить текущую позицию змейки
    std::vector<SDL_Rect> body;
protected:
    // текущая позиция змейки на игровом поле
    int direction; // текущее направление движения змейки
};



#endif //TIPKR_SNAKE_H
