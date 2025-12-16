#include "../include/Grid.hpp"
#include <iostream> // <--- Ne pas oublier pour std::cout
#include <vector>  // Pour lister les cases vides
#include <cstdlib> // Pour rand() (le hasard)

Grid::Grid() {
    // Initialisation à 0
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            data[i][j] = 0;
        }
    }
    
    // Génération des deux premières tuiles
    spawnRandomTile();
    spawnRandomTile();
}

// Nouvelle fonction d'affichage
void Grid::display() {
    std::cout << "-----------------" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "| "; // Début de ligne
        for (int j = 0; j < 4; j++) {
            // On affiche le nombre suivi d'un espace
            // Si c'est 0, on affiche un point '.' pour que ce soit plus lisible
            if (data[i][j] == 0) {
                std::cout << ". ";
            } else {
                std::cout << data[i][j] << " ";
            }
            std::cout << "| "; // Séparateur
        }
        std::cout << std::endl; // Fin de ligne (retour chariot)
        std::cout << "-----------------" << std::endl;
    }
}

void Grid::spawnRandomTile() {
    // 1. Trouver toutes les cases vides
    std::vector<std::pair<int, int>> emptyCells;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (data[i][j] == 0) {
                // On stocke les coordonnées (i, j) de la case vide
                emptyCells.push_back({i, j});
            }
        }
    }

    // 2. S'il n'y a pas de place, on ne fait rien
    if (emptyCells.empty()) {
        return;
    }

    // 3. Choisir une case au hasard parmi celles vides
    int randomIndex = rand() % emptyCells.size();
    std::pair<int, int> target = emptyCells[randomIndex];

    // 4. Mettre un 2 (90% de chance) ou un 4 (10% de chance)
    // rand() % 10 donne un nombre entre 0 et 9. Si c'est 0 (1 chance sur 10), on met 4.
    int value = (rand() % 10 == 0) ? 4 : 2;

    data[target.first][target.second] = value;
}