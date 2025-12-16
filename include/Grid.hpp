#pragma once
#include <array>

class Grid {
public:   // Ici on mettra les actions possibles (bouger, afficher...)
    Grid();

private: // Ici on met les données cachées (les nombres)
    std::array<std::array<int, 4>, 4> data;
};