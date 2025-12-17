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
        std::cout << "Action (z=haut, q=gauche, s=bas, d=droite, x=quitter) : ";
        std::cin >> input;

        if (input == 'x') {
            running = false;
        } 
        else {
            bool moved = false; // On ne fait apparaitre une tuile que si on a bougé
            
            if (input == 'q') { gameGrid.moveLeft(); moved = true; }
            else if (input == 'd') { gameGrid.moveRight(); moved = true; }
            else if (input == 'z') { gameGrid.moveUp(); moved = true; }
            else if (input == 's') { gameGrid.moveDown(); moved = true; }
            else {
                std::cout << "Commande inconnue." << std::endl;
            }

            if (moved) {
                gameGrid.spawnRandomTile();
                gameGrid.display();
            }
        }
    }