#ifndef TIPKR_GAME_H
#define TIPKR_GAME_H


#include "Snake.h"
#include "Food.h"
#include "Score.h"
#include "Renderer.h"

class Game {
public:
    Game(); // конструктор класса
    void Run(); // запустить игру
    void Init(); // инициализировать игру
    void Clean(); // очистить игру
    void Pause(); // приостановить игру
    void Resume(); // возобновить игру
    void HandleInput(); // обработать ввод пользователя
    void Update(); // обновить состояние игры на каждом шаге
    void Render(); // отрисовать игровое поле и его элементы

private:
    bool isRunning; // флаг, указывающий, работает ли игра в данный момент
    bool isPaused; // флаг, указывающий, находится ли игра в режиме паузы
    int screenWidth; // ширина окна игры
    int screenHeight; // высота окна игры
    Snake snake; // змейка
    Food food; // еда на игровом поле
    Score score; // текущий счет игрока

};


#endif //TIPKR_GAME_H
