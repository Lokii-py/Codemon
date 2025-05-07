#include "Arena.h"
#include "Codemon.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Arena::Arena() {
    for (int r = 0; r < SIZE; ++r) {
        for (int c = 0; c < SIZE; ++c) {
            occupied[r][c] = false;
            visibleMap[r][c] = '#';
        }
    }
    generateTerrain();
    curRow = -1; // not placed yet
    curCol = -1;
    eneRow = -1;
    eneCol = -1;
}

void Arena::generateTerrain() {
    // Fill terrainMap with valid terrain
    char terrainTypes[] = { 'F', 'M', 'P', 'W', 'S' }; // 'F' = Forest, 'M' = Mountain, 'P' = Plain, 'W' = Water, 'S' = Swamp
    // Initialize terrain grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Randomly pick a terrain type for this cell
            char newType;
            do {
                newType = terrainTypes[rand() % 5]; // Random terrain type
            } while (hasSameTypeNeighbor(i, j, newType)); // Ensure no neighbor has the same type

            terrainMap[i][j] = newType;
        }
    }
}

bool Arena::isOccupied(int row, int col) const {
    return occupied[row][col];
}

void Arena::markOccupied(int row, int col) {
    occupied[row][col] = true;
}

char Arena::getTerrainTile(int row, int col) const {
    char type;
    type = terrainMap[row][col];
    return type;
}

bool Arena::hasSameTypeNeighbor(int x, int y, char type) const {
    // Check for neighbors (top, bottom, left, right) to ensure they are not the same type
    // Top
    if (x > 0 && terrainMap[x - 1][y] == type) {
        return true;
    }
    // Bottom
    if (x < 4 && terrainMap[x + 1][y] == type) {
        return true;
    }
    // Left
    if (y > 0 && terrainMap[x][y - 1] == type) {
        return true;
    }
    // Right
    if (y < 4 && terrainMap[x][y + 1] == type) {
        return true;
    }

    return false;
}

void Arena::printTerrainForDebug() const {
    // Print the terrain map for debugging
    cout << "Terrain Map:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << terrainMap[i][j] << " ";
        }
        cout << "\n";
    }
}


void Arena::updateVisibility(int x, int y) {
    for (int r = 0; r < SIZE; ++r) {
        for (int c = 0; c < SIZE; ++c) {
            visibleMap[r][c] = '#';
        }
    }
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE)
                visibleMap[nx][ny] = terrainMap[nx][ny];
        }
    }
}

void Arena::setTerrainTile(const int n_row, const int n_col, const char c) {
    visibleMap[n_row][n_col] = c;
}

void Arena::clearPreviousTile() {
    if (curRow != -1 && curCol != -1) {
        visibleMap[curRow][curCol] = terrainMap[curRow][curCol];
        occupied[curRow][curCol] = false;
    }
}

void Arena::updateCurrentPosition(const int n_row, const int n_col) {
    curRow = n_row;
    curCol = n_col;
}

void Arena::printVisibleMap() const {  // I know it is not "void Contestant::printVisibleMap() const"
    // Print the visible map
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << visibleMap[i][j] << " ";
        }
        cout << "\n";
    }
    std::cout << "==========\n";
}

bool Arena::isEnemyInRange(int& row, int& col, Arena& arena) {
    for (int i = row - 1; i <= row + 1; ++i) {
        for (int j = col - 1; j <= col + 1; ++j) {
            if (i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
                if (i == eneRow && j == eneCol) {
                    return true;
                }
            }
        }
    }
    return false;
}
