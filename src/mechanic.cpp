#include "mechanic.h"
#include "Arena.h"
#include "Codemon.h"

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

    // Example check — tile is not blocked (optional)
    if (arena.isOccupied(n_row, n_col)) {
        cout << "Tile occupied." << endl;
        return;
    }

    arena.clearPreviousTile();

    // Update new position
    arena.setTerrainTile(n_row, n_col, '@');
    arena.markOccupied(n_row, n_col);
    arena.updateCurrentPosition(n_row, n_col);
    arena.updateVisibility(n_row, n_col);

    // Update caller's position variables
    row = n_row;
    col = n_col;
}


void battle(Contestant& player, Contestant& comp, Arena& arena, int row, int col) {
    Codemon& pCodemon = player.getActiveCodemon();
    Codemon& cCodemon = comp.getActiveCodemon();

    // Get terrain type at current battle location
    char terrain = arena.getTerrainTile(row, col);

    int basePlayerDamage = pCodemon.skills[0].getBaseDamage();
    int baseCompDamage = cCodemon.skills[0].getBaseDamage();

    // Apply terrain advantage: +10 if Codémon matches terrain type
    int playerDamage = basePlayerDamage;
    int compDamage = baseCompDamage;

    if (pCodemon.getType()[0] == terrain) {
        playerDamage += 10;
        cout << "Player Codemon gains terrain advantage! +" << 10 << " damage.\n";
    }
    if (cCodemon.getType()[0] == terrain) {
        compDamage += 10;
        cout << "Computer Codemon gains terrain advantage! +" << 10 << " damage.\n";
    }

    cout << "Battle Start: \n";
    cout << "Player Codemon: " << pCodemon.getName() << " vs Computer Codemon: " << cCodemon.getName() << "\n";

    while (pCodemon.getCurrentHP() > 0 && cCodemon.getCurrentHP() > 0) {
        // Each Codémon attacks the other
        pCodemon -= compDamage;
        cCodemon -= playerDamage;

        // Display current HP
        cout << "After this round:\n";
        cout << "Player Codemon HP: " << pCodemon.getCurrentHP() << "\n";
        cout << "Computer Codemon HP: " << cCodemon.getCurrentHP() << "\n";
    }

    // Handle fainting
    if (pCodemon.getCurrentHP() <= 0) {
        cout << "Player's Codemon " << pCodemon.getName() << " has fainted.\n";
        player.death();
    }
    if (cCodemon.getCurrentHP() <= 0) {
        cout << "Computer's Codemon " << cCodemon.getName() << " has fainted.\n";
        comp.death();
    }

    // Print new active Codémons (if any left)
    if (player.isAlive()) {
        cout << "New Player Codemon:\n" << player.getActiveCodemon();
    }
    if (comp.isAlive()) {
        cout << "New Computer Codemon:\n" << comp.getActiveCodemon();
    }

    // Endgame check
    if (!player.isAlive()) {
        cout << "All Player Codémons have been defeated.\n";
    }
    if (!comp.isAlive()) {
        cout << "All Computer Codémons have been defeated.\n";
    }
}
