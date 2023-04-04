#ifndef TIPKR_INPUT_H
#define TIPKR_INPUT_H


#include "libs/SDL2-2.26.4/x86_64-w64-mingw32/include/SDL2/SDL.h"

class Input {
public:
    Input(); // конструктор класса
    bool IsKeyDown(SDL_Keycode key); // проверить, нажата ли клавиша

private:
    bool keys[SDL_NUM_SCANCODES]{}; // массив, хранящий состояние клавиш
};


#endif //TIPKR_INPUT_H
