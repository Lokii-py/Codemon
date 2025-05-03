#include "mechanic.h"
#include "Arena.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void movement(const char move, int& row, int& col, Arena& arena) {
    int n_row = row;
    int n_col = col;
     
    switch (move) {
    case 'W':
        n_row = row - 1;
        break;
    case 'A':
        n_col = col - 1;
        break;
    case 'S':
        n_row = row + 1;
        break;
    case 'D':
        n_col = col + 1;
        break;
    case 'Q':
        n_row = row - 1;
        n_col = col - 1;
        break;
    case 'E':
        n_row = row - 1;
        n_col = col + 1;
        break;
    case 'Z':
        n_row = row + 1;
        n_col = col - 1;
        break;
    case 'C':
        n_row = row + 1;
        n_col = col - 1;
        break;
    default:
        cout << "Invalid Input!" << endl;
        break;
    }

    if (n_row < 0 || n_row >= 5 || n_col < 0 || n_col >= 5) {
        cout << "Out of bounds. << endl;";
        return;
    }

    // Example check — tile is not blocked (optional)
    if (arena.isOccupied(n_row, n_col)) {
        cout << "Tile occupied." << endl;
        return;
    }

    arena.setTerrainTile(n_row, n_col, '@');
    row = n_row;
    col = n_col;
    arena.markOccupied(row, col);
}


bool isEnemyInRange(int& row, int& col, Arena& arena) {
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < 5 && j >= 0 && j < 5) {
                if (arena.getTerrainTile(i, j) == 'E') {
                    return true;
                }
            }
        }
    }
}
