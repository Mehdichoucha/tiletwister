#include "../include/Grid.hpp"
#include <iostream> // <--- Ne pas oublier pour std::cout
#include <vector>  // Pour lister les cases vides
#include <cstdlib> // Pour rand() (le hasard)

Grid::Grid() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            data[i][j] = 0;
        }
    }
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