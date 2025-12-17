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


void Grid::moveLeft() {
    for (int i = 0; i < 4; i++) {
        // --- ÉTAPE 1 : Tasser à gauche (supprimer les 0 intermédiaires) ---
        // On crée un tableau temporaire pour stocker les nombres non-nuls
        std::array<int, 4> tempRow = {0, 0, 0, 0};
        int index = 0;

        // On garde seulement ce qui n'est pas 0
        for (int j = 0; j < 4; j++) {
            if (data[i][j] != 0) {
                tempRow[index] = data[i][j];
                index++;
            }
        }
        // On remet la ligne tassée dans la grille
        data[i] = tempRow;

        // --- ÉTAPE 2 : Fusionner les doublons ---
        for (int j = 0; j < 3; j++) {
            // Si une case est égale à sa voisine de droite (et n'est pas 0)
            if (data[i][j] != 0 && data[i][j] == data[i][j + 1]) {
                data[i][j] *= 2;      // On double la valeur (2+2 = 4)
                data[i][j + 1] = 0;   // L'autre case devient vide
            }
        }

        // --- ÉTAPE 3 : Tasser à nouveau (après la fusion, des trous ont pu apparaître) ---
        // Exemple : [2, 2, 4, 0] -> fusion -> [4, 0, 4, 0] -> il faut retasser -> [4, 4, 0, 0]
        tempRow = {0, 0, 0, 0};
        index = 0;
        for (int j = 0; j < 4; j++) {
            if (data[i][j] != 0) {
                tempRow[index] = data[i][j];
                index++;
            }
        }
        data[i] = tempRow;
    }
}


void Grid::moveRight() {
    for (int i = 0; i < 4; i++) {
        std::array<int, 4> tempRow = {0, 0, 0, 0};
        int index = 3; // On commence à remplir par la droite

        // 1. Tasser à droite
        for (int j = 3; j >= 0; j--) {
            if (data[i][j] != 0) {
                tempRow[index] = data[i][j];
                index--;
            }
        }
        data[i] = tempRow;

        // 2. Fusionner (de la droite vers la gauche)
        for (int j = 3; j > 0; j--) {
            if (data[i][j] != 0 && data[i][j] == data[i][j - 1]) {
                data[i][j] *= 2;
                data[i][j - 1] = 0;
            }
        }

        // 3. Re-tasser après fusion
        tempRow = {0, 0, 0, 0};
        index = 3;
        for (int j = 3; j >= 0; j--) {
            if (data[i][j] != 0) {
                tempRow[index] = data[i][j];
                index--;
            }
        }
        data[i] = tempRow;
    }
}
