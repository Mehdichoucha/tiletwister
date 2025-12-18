#include "../include/Game.hpp"
#include <iostream>
#include <cstdlib> // pour system()

Game::Game() {
    isRunning = true;
    hasWon = false;
    // La grille s'initialise toute seule grâce à son propre constructeur
}

void Game::runConsole() {
    std::cout << "=== TILE TWISTER (Console Version) ===" << std::endl;
    grid.display();

    char input;
    while (isRunning) {
        // 1. Vérifications
        checkGameStatus();
        if (!isRunning) break; // Si on a perdu ou quitté

        // 2. Input
        std::cout << "Action (z=haut, q=gauche, s=bas, d=droite, x=quitter) : ";
        std::cin >> input;

        // 3. Traitement
        processInput(input);
    }
    std::cout << "Fin du programme." << std::endl;
}

void Game::checkGameStatus() {
    // Victoire
    if (!hasWon && grid.checkWin()) {
        std::cout << "FÉLICITATIONS ! VOUS AVEZ ATTEINT 2048 !" << std::endl;
        hasWon = true; 
        std::cout << "Continuez pour le score ou quittez (x)." << std::endl;
    }

    // Défaite
    if (grid.checkGameOver()) {
        std::cout << "GAME OVER ! Plus aucun mouvement possible." << std::endl;
        isRunning = false;
    }
}

void Game::processInput(char input) {
    if (input == 'x') {
        isRunning = false;
        return;
    }

    bool moved = false;
    if (input == 'q') { grid.moveLeft(); moved = true; }
    else if (input == 'd') { grid.moveRight(); moved = true; }
    else if (input == 'z') { grid.moveUp(); moved = true; }
    else if (input == 's') { grid.moveDown(); moved = true; }
    else {
        std::cout << "Commande inconnue." << std::endl;
    }

    if (moved) {
        grid.spawnRandomTile();
        
        #ifdef _WIN32
            std::system("cls");
        #else
            std::system("clear");
        #endif
        
        grid.display();
    }
}