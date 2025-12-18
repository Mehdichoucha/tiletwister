#include "../include/Grid.hpp"
#include <array> 

void Grid::moveLeft() {
    for (int i = 0; i < 4; i++) {
        std::array<int, 4> tempRow = {0, 0, 0, 0};
        int index = 0;

        // Tasser
        for (int j = 0; j < 4; j++) {
            if (data[i][j] != 0) { tempRow[index] = data[i][j]; index++; }
        }
        data[i] = tempRow;

        // Fusionner
        for (int j = 0; j < 3; j++) {
            if (data[i][j] != 0 && data[i][j] == data[i][j + 1]) {
                data[i][j] *= 2;
                data[i][j + 1] = 0;
            }
        }

        // Retasser
        tempRow = {0, 0, 0, 0};
        index = 0;
        for (int j = 0; j < 4; j++) {
            if (data[i][j] != 0) { tempRow[index] = data[i][j]; index++; }
        }
        data[i] = tempRow;
    }
}

void Grid::moveRight() {
    for (int i = 0; i < 4; i++) {
        std::array<int, 4> tempRow = {0, 0, 0, 0};
        int index = 3;

        for (int j = 3; j >= 0; j--) {
            if (data[i][j] != 0) { tempRow[index] = data[i][j]; index--; }
        }
        data[i] = tempRow;

        for (int j = 3; j > 0; j--) {
            if (data[i][j] != 0 && data[i][j] == data[i][j - 1]) {
                data[i][j] *= 2;
                data[i][j - 1] = 0;
            }
        }

        tempRow = {0, 0, 0, 0};
        index = 3;
        for (int j = 3; j >= 0; j--) {
            if (data[i][j] != 0) { tempRow[index] = data[i][j]; index--; }
        }
        data[i] = tempRow;
    }
}

void Grid::moveUp() {
    for (int j = 0; j < 4; j++) {
        std::array<int, 4> tempCol = {0, 0, 0, 0};
        int index = 0;

        for (int i = 0; i < 4; i++) {
            if (data[i][j] != 0) { tempCol[index] = data[i][j]; index++; }
        }
        for(int i=0; i<4; i++) data[i][j] = tempCol[i];

        for (int i = 0; i < 3; i++) {
            if (data[i][j] != 0 && data[i][j] == data[i + 1][j]) {
                data[i][j] *= 2;
                data[i + 1][j] = 0;
            }
        }

        tempCol = {0, 0, 0, 0};
        index = 0;
        for (int i = 0; i < 4; i++) {
            if (data[i][j] != 0) { tempCol[index] = data[i][j]; index++; }
        }
        for(int i=0; i<4; i++) data[i][j] = tempCol[i];
    }
}

void Grid::moveDown() {
    for (int j = 0; j < 4; j++) {
        std::array<int, 4> tempCol = {0, 0, 0, 0};
        int index = 3;

        for (int i = 3; i >= 0; i--) {
            if (data[i][j] != 0) { tempCol[index] = data[i][j]; index--; }
        }
        for(int i=0; i<4; i++) data[i][j] = tempCol[i];

        for (int i = 3; i > 0; i--) {
            if (data[i][j] != 0 && data[i][j] == data[i - 1][j]) {
                data[i][j] *= 2;
                data[i - 1][j] = 0;
            }
        }

        tempCol = {0, 0, 0, 0};
        index = 3;
        for (int i = 3; i >= 0; i--) {
            if (data[i][j] != 0) { tempCol[index] = data[i][j]; index--; }
        }
        for(int i=0; i<4; i++) data[i][j] = tempCol[i];
    }
}