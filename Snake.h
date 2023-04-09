#ifndef TIPKR_SNAKE_H
#define TIPKR_SNAKE_H


#include <vector>
#include "Input.h"

class Snake {
public:
    Snake(); // конструктор класса
    void Init(); // инициализация змейки
    void Render(); // отрисовка змейки на игровом поле
    void Update(); // обновление состояния змейки
    int GetHeadX(); // получить текущую координату X головы змейки
    int GetHeadY(); // получить текущую координату Y головы змейки
    void Grow(); // увеличить длину змейки
    void Move(); // перемещение змейки на игровом поле
    void HandleInput(Input input); // обработка ввода пользователя
    bool CheckCollision(); // проверка на столкновение змейки со стенами или своим телом
protected:
    int direction; // текущее направление движения змейки
};



#endif //TIPKR_SNAKE_H
