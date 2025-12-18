#pragma once
#include "Grid.hpp"

class Game {
public:
    Game();
    void runConsole(); // Lance la boucle de jeu en mode console

private:
    Grid grid;         // L'objet Grille est géré par le Jeu
    bool isRunning;
    bool hasWon;
    
    void processInput(char input);
    void checkGameStatus(); // Vérifie victoire/défaite
};