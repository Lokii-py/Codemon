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
        n_row = row + 1;
        break;
    case 'A':
        n_col = col - 1;
        break;
    case 'S':
        n_row = row - 1;
        break;
    case 'D':
        n_col = col + 1;
        break;
    case 'Q':
        n_row = row + 1;
        n_col = col - 1;
        break;
    case 'E':
        n_row = row + 1;
        n_col = col + 1;
        break;
    case 'Z':
        n_row = row - 1;
        n_col = col - 1;
        break;
    case 'C':
        n_row = row - 1;
        n_col = col + 1;
        break;
    default:
        cout << "Invalid Input!" << endl;
        break;
    }

    if (n_row < 0 || n_row >= 5 || n_col < 0 || n_col >= 5) {
        cout << "Out of bounds." << endl;
        return;
    }

    // Example check � tile is not blocked (optional)
    if (arena.isOccupied(n_row, n_col)) {
        cout << "Tile occupied." << endl;
        return;
    }
    arena.setTerrainTile(row, col, '#');
    arena.updateVisibility(n_row, n_col);
    arena.setTerrainTile(n_row, n_col, '@');
    row = n_row;
    col = n_col;
    arena.markOccupied(row, col);
}




void battle(Contestant& player, Contestant& comp, Arena& arena) {
    int playerCount = player.getCodemonCount() - 1;
    int compCount = comp.getCodemonCount() - 1;
    int playerDamage = player.pocket[playerCount].skills[0].getBaseDamage();
    int compDamage = comp.pocket[compCount].skills[0].getBaseDamage();

    bool playerAlive = true;
    bool compAlive = true;

    do {
        // codemon battles with 
        // subtract skill damage from each codemon hp
        player.pocket[playerCount] -= compDamage;
        comp.pocket[compCount] -= playerDamage;

        if (player.pocket[playerCount].getCurrentHP() == 0) {
            playerAlive = false;
            std::cout << "Player codemon has died.\n";
            player.death();
        }

        if (comp.pocket[compCount].getCurrentHP() == 0) {
            compAlive = false;
            std::cout << "Computer codemon has died.\n";
            comp.death();

        }

        
    } while (playerAlive == true && compAlive == true);//while codemon hp is > 0


    std::cout << player.pocket[playerCount];
    std::cout << comp.pocket[compCount];

    if (player.getCodemonCount() == 0) {
        std::cout << "Player has died.\n";

    }
    if (comp.getCodemonCount() == 0) {
        std::cout << "Computer has died.\n";
    }
    return;
}
