//
// Created by VeiTr on 27.03.2023.
//

#include "Food.h"

Food::Food() {
    position = {0, 0, 10, 10};
}

void Food::Init(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &position);
}

void Food::Render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &position);
}

int Food::GetX() {
    return position.x;
}

int Food::GetY() {
    return position.y;
}

void Food::Randomize() {
    position.x = rand() % 50;
    position.y = rand() % 50;
}

void Food::Spawn(SDL_Renderer* renderer, int tileSize, int screenWidth, int screenHeight) {
    position.w = tileSize;
    position.h = tileSize;
    position.x = (rand() % (screenWidth / tileSize)) * tileSize;
    position.y = (rand() % (screenHeight / tileSize)) * tileSize;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &position);
}

SDL_Rect Food::GetPosition() {
    return position;
}
