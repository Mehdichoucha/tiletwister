#pragma once
#define SDL_DISABLE_OLD_NAMES
#include <SDL3/SDL.h>
#include "Grid.h"

class Game {
public:
    Game();
    ~Game();

    bool init(const char* title, int width, int height);
    void run();
    void clean();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;

    Grid grid;

    void handleEvents();
    void update(float delta);
    void render();
};
