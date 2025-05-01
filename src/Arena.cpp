#include "Arena.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Arena::Arena() {
    for (int r = 0; r < SIZE; ++r) {
        for (int c = 0; c < SIZE; ++c) {
            occupied[r][c] = false;
        }
    }
    generateTerrain();
}

void Arena::generateTerrain() {
    // Fill terrainMap with valid terrain
    char terrainTypes[] = { 'F', 'M', 'P', 'W', 'S' }; // 'F' = Forest, 'M' = Mountain, 'P' = Plain, 'W' = Water, 'S' = Swamp
    // Initialize terrain grid
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Randomly pick a terrain type for this cell
            char newType;
            do {
                newType = terrainTypes[rand() % 5]; // Random terrain type
            } while (hasSameTypeNeighbor(i, j, newType)); // Ensure no neighbor has the same type

            terrainMap[i][j] = newType;
        }
    }
}

bool Arena::isOccupied(int row, int col) const{
    return occupied[row][col];
}

void Arena::markOccupied(int row, int col){
    occupied[row][col] = true;
}

char Arena::getTerrainTile(int row, int col) const{
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
};

void Arena::printTerrainForDebug() const {
	// Print the terrain map for debugging
	cout << "Terrain Map:\n";
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
		    cout << terrainMap[i][j] << " ";
		}
		cout << "\n";
	}
}