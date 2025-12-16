#include "../include/Grid.hpp" // On inclut notre plan

// Grid::Grid veut dire "Le constructeur Grid qui appartient à la classe Grid"
Grid::Grid() {
    for (int i = 0; i < 4; i++) {       // Pour chaque ligne i
        for (int j = 0; j < 4; j++) {   // Pour chaque colonne j
            data[i][j] = 0;             // On met la case à 0
        }
    }
}