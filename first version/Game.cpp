#include "Game.h"
#include <iostream>

Game::Game()
    : window(nullptr), renderer(nullptr), isRunning(true) {}

Game::~Game() {}

bool Game::init(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
    if (!window) return false;

    renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) return false;

    grid.init();
    return true;
}

void Game::run() {
    Uint64 last = SDL_GetTicks();

    while (isRunning) {
        Uint64 now = SDL_GetTicks();
        float delta = (now - last) / 1000.0f;
        last = now;

        handleEvents();
        update(delta);
        render();

        SDL_Delay(16);
    }
}

void Game::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            isRunning = false;
        }

        if (event.type == SDL_EVENT_KEY_DOWN) {
            SDL_Keycode key = event.key.key;

            if (key == SDLK_UP)    grid.move(UP);
            if (key == SDLK_DOWN)  grid.move(DOWN);
            if (key == SDLK_LEFT)  grid.move(LEFT);
            if (key == SDLK_RIGHT) grid.move(RIGHT);
        }
    }
}

void Game::update(float delta) {
    grid.update(delta);
    if (grid.isGameOver()) {
        std::cout << "Game Over\n";
        isRunning = false;
    }
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 250, 248, 239, 255);
    SDL_RenderClear(renderer);

    grid.render(renderer);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
