// Programmer: Henry Campbell (id: 12619823;hmcngb) and Lokesh Das (id: 12631232;ldd3g)
// Date: 4/25/25
// File: main.cpp
// Assignment: HW7
// Purpose: This is the Codemon simulation game player.

#include "Arena.h"
#include "contestant.h"
#include "mechanic.h"
#include "Snuggle.h"
#include <iostream>
#include <cstdlib>
#include <cstring> // for strchr
using namespace std;

int main() {
    srand(1025); // Set random seed once

    Arena arena; // Initialize the battle arena
    Contestant player("Player"), computer("CPU"); // Initialize contestants

    arena.generateTerrain(); // Fill terrainMap with valid terrain
    arena.printTerrainForDebug(); // Debug view of full terrain

    // Codémon selection
    char choice;
    cout << "PLAYER: Do you want custom selection of Codemons? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        player.selectCodemons(); // Choose 3 Codemons
    }
    else {
        player.generateCodemons(); // Random Codemons
    }
    computer.generateCodemons(); // CPU always uses random

    // Place Player Codémon
    int playerRow, playerCol;
    do {
        playerRow = rand() % 5;
        playerCol = rand() % 5;
    } while (arena.isOccupied(playerRow, playerCol));
    arena.updateVisibility(playerRow, playerCol);
    arena.setTerrainTile(playerRow, playerCol, '@');
    arena.markOccupied(playerRow, playerCol);

    // Place CPU Codémon
    int cpuRow, cpuCol;
    do {
        cpuRow = rand() % 5;
        cpuCol = rand() % 5;
    } while (arena.isOccupied(cpuRow, cpuCol));
    arena.markOccupied(cpuRow, cpuCol);

    // Main game loop
    while (player.isAlive() && computer.isAlive()) {
        // Print visible map
        arena.printVisibleMap();

        // Player move
        char move;
        do {
            cout << "Move your Codemon (W/A/S/D/Q/E/Z/C): ";
            cin >> move;
            move = toupper(move);  // Make sure it's uppercase
        } while (move != 'W' && move != 'A' && move != 'S' && move != 'D' &&
            move != 'Q' && move != 'E' && move != 'Z' && move != 'C');

        movement(move, playerRow, playerCol, arena);

        // Check if enemy is in range and handle battle
        if (arena.isEnemyInRange(playerRow, playerCol, arena)) {
            cout << "Enemy in range! Initiating battle..." << endl;
            string response;
            cout << "Do you want to attack? (yes/no): ";
            cin >> response;
            if (response == "yes") {
                battle(player, computer, arena, playerRow, playerCol); // ← updated call
            }
            else {
                cout << "You chose not to attack.\n";
            }
            continue; // Skip CPU move if battle occurs
        }

        // CPU move (random)
        char moves[] = { 'W', 'A', 'S', 'D', 'Q', 'E', 'Z', 'C' };
        char cpuMove = moves[rand() % 8];
        movement(cpuMove, cpuRow, cpuCol, arena);
    }

    // Game over
    cout << "Game over. ";
    if (!player.isAlive()) {
        cout << "Computer wins.\n";
    }
    else {
        cout << "Player wins.\n";
    }

    return 0;
}
