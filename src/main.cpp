#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/Grid.hpp"

int main() {
    // Initialisation du hasard
    std::srand(std::time(nullptr)); 

    std::cout << "=== TILE TWISTER (Console Version) ===" << std::endl;
    
    Grid gameGrid;
    gameGrid.display();

    char input;
    bool running = true;

    while (running) {
        std::cout << "Action (g = gauche, q = quitter) : ";
        std::cin >> input;

        if (input == 'q') {
            running = false;
        } 
        else if (input == 'g') {
            gameGrid.moveLeft();       // 1. On bouge
            gameGrid.spawnRandomTile(); // 2. Une nouvelle tuile apparaît
            gameGrid.display();         // 3. On montre le résultat
        } 
        else {
            std::cout << "Commande inconnue. Essayez 'g'." << std::endl;
        }
    }

    std::cout << "Fin de la partie !" << std::endl;
    return 0;
}
