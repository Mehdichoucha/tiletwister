#include <iostream>
#include <cstdlib> // <--- Ajout
#include <ctime>   // <--- Ajout
#include "../include/Grid.hpp"  // On importe notre plan de Grille


int main() {

    // Initialisation de la graine aléatoire basée sur l'heure actuelle
    std::srand(std::time(nullptr));

    std::cout << "Tile Twister : Initialisation..." << std::endl;

    // On crée une instance de la grille.
    // Cela appelle automatiquement le constructeur Grid() que j'ai écrit
    // et remplit le tableau de zéros.
    Grid gameGrid; 

    std::cout << "Grille créée et initialisée :" << std::endl;
    gameGrid.display(); // <--- On affiche !

    return 0;
}

