#pragma once
#define SDL_DISABLE_OLD_NAMES
#include <SDL3/SDL.h>

class Tile {
public:
    int value;
    float x, y;
    float targetX, targetY;
    bool merged = false;

    Tile(int val, int px, int py);
    void update(float delta);
    void render(SDL_Renderer* renderer, int size);
    void moveTo(int nx, int ny);
};
