//
// Created by VeiTr on 27.03.2023.
//

#include "Score.h"

Score::Score() {
    score = 0;
}

void Score::Init(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, 0, 0, 0, 0);
}

void Score::IncreaseScore(int points) {
    score += points;
}

int Score::GetScore() {
    return score;
}

SDL_Texture* Score::GetText() {
    return text;
}
