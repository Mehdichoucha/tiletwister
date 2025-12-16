#include <iostream>
#include "../include/Grid.hpp"  // On importe notre plan de Grille


int main() {
    std::cout << "Tile Twister : Initialisation..." << std::endl;

    // On crée une instance de la grille.
    // Cela appelle automatiquement le constructeur Grid() que j'ai écrit
    // et remplit le tableau de zéros.
    Grid gameGrid; 

    std::cout << "Grille créée en mémoire !" << std::endl;
    gameGrid.display(); // <--- On affiche !

    return 0;
}