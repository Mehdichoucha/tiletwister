#include "Tile.h"

Tile::Tile(int val, int px, int py)
    : value(val), x(px), y(py), targetX(px), targetY(py), merged(false) {}

void Tile::moveTo(int nx, int ny) {
    targetX = (float)nx;
    targetY = (float)ny;
}

void Tile::update(float delta) {
    x += (targetX - x) * delta * 10.0f;
    y += (targetY - y) * delta * 10.0f;
}

void Tile::render(SDL_Renderer* renderer, int size) {
    SDL_FRect rect{
        x * size + 10 * x + 10,
        y * size + 10 * y + 10,
        (float)size,
        (float)size
    };

    switch (value) {
        case 2:  SDL_SetRenderDrawColor(renderer, 238, 228, 218, 255); break;
        case 4:  SDL_SetRenderDrawColor(renderer, 237, 224, 200, 255); break;
        case 8:  SDL_SetRenderDrawColor(renderer, 242, 177, 121, 255); break;
        case 16: SDL_SetRenderDrawColor(renderer, 245, 149, 99, 255); break;
        case 32: SDL_SetRenderDrawColor(renderer, 246, 124, 95, 255); break;
        case 64: SDL_SetRenderDrawColor(renderer, 246, 94, 59, 255); break;
        default: SDL_SetRenderDrawColor(renderer, 237, 207, 114, 255); break;
    }

    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderRect(renderer, &rect);
}
