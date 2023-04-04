//
// Created by VeiTr on 27.03.2023.
//

#include "Snake.h"
#include "Renderer.h"

Snake::Snake() {
    body.push_back({0, 0, 10, 10});
    direction = 0;
}

void Snake::Init(SDL_Renderer* renderer) {
    for (int i = 0; i < body.size(); i++) {
        Renderer::RenderRect(renderer, body[i]);
    }
}

void Snake::Render(SDL_Renderer* renderer) {
    for (int i = 0; i < body.size(); i++) {
        Renderer::RenderRect(renderer, body[i]);
    }
}

void Snake::Update() {
    Move();
}

int Snake::GetHeadX() {
    return body[0].x;
}

int Snake::GetHeadY() {
    return body[0].y;
}

void Snake::Grow() {
    SDL_Rect newBodyPart = {body[body.size() - 1].x, body[body.size() - 1].y, 10, 10};
    body.push_back(newBodyPart);
}


void Snake::Move() {
    for (int i = body.size() - 1; i > 0; i--) {
        body[i].x = body[i - 1].x;
        body[i].y = body[i - 1].y;
    }
    switch (direction) {
        case 0:
            body[0].x += 10;
            break;
        case 1:
            body[0].y += 10;
            break;
        case 2:
            body[0].x -= 10;
            break;
        case 3:
            body[0].y -= 10;
            break;
    }
}

void Snake::HandleInput(Input input) {
    if (input.IsKeyDown(SDLK_UP) && direction != 1) direction = 3;
    if (input.IsKeyDown(SDLK_DOWN) && direction != 3) direction = 1;
    if (input.IsKeyDown(SDLK_LEFT) && direction != 0) direction = 2;
    if (input.IsKeyDown(SDLK_RIGHT) && direction != 2) direction = 0;
}

bool Snake::CheckCollision() {
    if (body[0].x < 0 || body[0].x > 590 || body[0].y < 0 || body[0].y > 590) return true;
    for (int i = 1; i < body.size(); i++) {
        if (body[0].x == body[i].x && body[0].y == body[i].y) return true;
    }
    return false;
}

std::vector<SDL_Rect> Snake::GetBody() {
    return body;
}
