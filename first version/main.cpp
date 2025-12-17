#include "Game.h"

int main(int, char**) {
    Game game;
    if (!game.init("Tile Twister 2048", 600, 600))
        return -1;

    game.run();
    game.clean();
    return 0;
}
