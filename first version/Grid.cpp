#include "Grid.h"
#include <cstdlib>
#include <ctime>

Grid::Grid()
    : grid(4, std::vector<std::shared_ptr<Tile>>(4, nullptr)) {
    srand((unsigned int)time(nullptr));
}

void Grid::init() {
    addRandomTile();
    addRandomTile();
}

void Grid::addRandomTile() {
    std::vector<std::pair<int, int>> empty;

    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            if (!grid[y][x])
                empty.push_back({x, y});

    if (empty.empty()) return;

    auto [x, y] = empty[rand() % empty.size()];
    grid[y][x] = std::make_shared<Tile>((rand() % 2 + 1) * 2, x, y);
}

void Grid::move(Direction dir) {
    movedThisTurn = false;
    slideAndMerge(dir);
    if (movedThisTurn) addRandomTile();
}

void Grid::slideAndMerge(Direction dir) {
    for (int i = 0; i < 4; i++) {
        std::vector<std::shared_ptr<Tile>> line;

        for (int j = 0; j < 4; j++) {
            int x = (dir == LEFT || dir == RIGHT) ? j : i;
            int y = (dir == LEFT || dir == RIGHT) ? i : j;
            if (dir == RIGHT || dir == DOWN) x = 3 - x;
            if (dir == DOWN) y = 3 - y;

            if (grid[y][x]) line.push_back(grid[y][x]);
        }

        std::vector<std::shared_ptr<Tile>> merged;
        for (size_t k = 0; k < line.size(); k++) {
            if (k + 1 < line.size() &&
                line[k]->value == line[k + 1]->value &&
                !line[k]->merged) {

                auto t = std::make_shared<Tile>(line[k]->value * 2, 0, 0);
                t->merged = true;
                merged.push_back(t);
                k++;
                movedThisTurn = true;
            } else {
                merged.push_back(line[k]);
            }
        }

        while (merged.size() < 4) merged.push_back(nullptr);

        for (int j = 0; j < 4; j++) {
            int x = (dir == LEFT || dir == RIGHT) ? j : i;
            int y = (dir == LEFT || dir == RIGHT) ? i : j;
            if (dir == RIGHT || dir == DOWN) x = 3 - x;
            if (dir == DOWN) y = 3 - y;

            grid[y][x] = merged[j];
            if (merged[j]) merged[j]->moveTo(x, y);
        }
    }

    for (auto& row : grid)
        for (auto& t : row)
            if (t) t->merged = false;
}

void Grid::update(float delta) {
    for (auto& row : grid)
        for (auto& t : row)
            if (t) t->update(delta);
}

void Grid::render(SDL_Renderer* renderer) {
    SDL_FRect bg{0, 0, 600, 600};
    SDL_SetRenderDrawColor(renderer, 187, 173, 160, 255);
    SDL_RenderFillRect(renderer, &bg);

    for (auto& row : grid)
        for (auto& t : row)
            if (t) t->render(renderer, 120);
}

bool Grid::canMove() {
    for (auto& row : grid)
        for (auto& t : row)
            if (!t) return true;

    return false;
}

bool Grid::isGameOver() {
    return !canMove();
}
