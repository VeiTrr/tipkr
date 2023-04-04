#include "Game.h"

Game::Game() {
    isRunning = false;
    isPaused = false;
    screenWidth = 640;
    screenHeight = 480;
    window = nullptr;
    renderer = nullptr;
}

void Game::Run() {
    if (isRunning) return;
    isRunning = true;
    Init();
    while (isRunning) {
        HandleInput();
        Update();
        Render();
    }
    Clean();
}

void Game::Init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    snake.Init(renderer);
    food.Init(renderer);
    score.Init(renderer);
}

void Game::Clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::Pause() {
    if (isPaused) return;
    isPaused = true;
}

void Game::Resume() {
    if (!isPaused) return;
    isPaused = false;
}

void Game::HandleInput() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
                case SDLK_SPACE:
                    if (isPaused) {
                        Resume();
                    } else {
                        Pause();
                    }
                    break;
            }
            break;
    }
}

void Game::Update() {
    if (isPaused) return;
    snake.Update();
    if (snake.GetHeadX() == food.GetX() && snake.GetHeadY() == food.GetY()) {
        food.Randomize();
        snake.Grow();
        score.IncreaseScore(1);
    }
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    snake.Render(renderer);
    food.Render(renderer);
    score.Render(renderer);
    SDL_RenderPresent(renderer);
}


