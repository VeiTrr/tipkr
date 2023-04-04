//
// Created by VeiTr on 27.03.2023.
//

#include "Renderer.h"

Renderer::Renderer(int screenWidth, int screenHeight) {
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    gameBoardRect = {0, 0, screenWidth, screenHeight};
}

void Renderer::RenderRect(SDL_Renderer* renderer, SDL_Rect rect) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Renderer::RenderSnake(Snake& snake) {
    for (int i = 0; i < snake.body.size(); i++) {
        RenderRect(renderer, snake.body[i]);
    }
}

void Renderer::RenderFood(Food& food) {
    RenderRect(renderer, food.rect);
}

void Renderer::RenderScore(Score& score) {
    SDL_Color color = {255, 255, 255}; // Define the color of the text as white
    SDL_Surface* surface = TTF_RenderText_Solid(score.font, score.GetText()->c_str(), color);// Render the text as a surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface); // Convert the surface to a texture
    SDL_Rect rect = {0, 0, surface->w, surface->h}; // Define the position and size of the texture
    SDL_RenderCopy(renderer, texture, nullptr, &rect); // Copy the texture to the renderer
    SDL_FreeSurface(surface); // Free the surface memory
    SDL_DestroyTexture(texture); // Destroy the texture memory
}



void Renderer::RenderGameBoard() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &gameBoardRect);
}

void Renderer::Render() {
    SDL_RenderPresent(renderer);
}
