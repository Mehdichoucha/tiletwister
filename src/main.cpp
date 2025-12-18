#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/Game.hpp" // On inclut Game, plus besoin de Grid ici

int main() {
    // Initialisation du hasard (une seule fois pour tout le programme)
    std::srand(std::time(nullptr)); 

    // On crée le jeu et on le lance
    Game myGame;
    myGame.runConsole();

    return 0;
}