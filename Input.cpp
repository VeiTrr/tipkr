//
// Created by VeiTr on 27.03.2023.
//

#include "Input.h"

Input::Input() {}

bool Input::IsKeyDown(SDL_Keycode key) {
    return keys[key];
}
