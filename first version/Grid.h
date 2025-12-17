#pragma once
#define SDL_DISABLE_OLD_NAMES
#include <SDL3/SDL.h>
#include <vector>
#include <memory>
#include "Tile.h"
#include "Direction.h"

class Grid {
public:
    Grid();
    void init();
    void move(Direction dir);
    void update(float delta);
    void render(SDL_Renderer* renderer);
    bool isGameOver();

private:
    std::vector<std::vector<std::shared_ptr<Tile>>> grid;
    bool movedThisTurn = false;

    void addRandomTile();
    bool canMove();
    void slideAndMerge(Direction dir);
};
