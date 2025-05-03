#include "mechanic.h"
#include "Arena.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/* W, A, S, D for cardinal directions, Q, E, Z, C for diagonals
-----------------------------
W - Up      | Q - Up left
A - Left    | E - Up Right
S - Down    | Z - Down left
D - Right   | C - Down Right
-----------------------------
- Implement Random Movement for Computer
- This will take the current position of codemon 
- And update it with the new movement*/
void movement(const char move, int &row, const int &col, Arena& arena){
    int n_row = row;
    int n_col = col;

    switch (move):
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



