// Programmer: Henry Campbell (id: 12619823;hmcngb)  and Lokesh Das (id: 12631232 ldd3g)
// Date: 4/25/25
// File: main.cpp
// Assignment: HW7
// Purpose: This is the Codemon simulation game player.
#include "Arena.h"
#include "contestant.h"
#include "mechanic.h"
#include <iostream>
using namespace std;

int main() {

    Arena arena; //Initalize the battle arena
    Contestant player("Player"), computer("CPU"); //initalize the contestant

    // Set random seed ONCE
    srand(1025);

    arena.generateTerrain(); // Fill terrainMap with valid terrain
    arena.printTerrainForDebug();

    char choice;
    std::cout << "PLAYER: Do you want custom selection of Codemons? (y/n)\n";
    std::cin >> choice;   // user selects or random
    if (choice == 'y') {
        player.selectCodemons();      // choose three codemons
    }
    else {
        player.generateCodemons();  // generate three codemons
    }

    computer.generateCodemons();

    //Deploy codemon to the unoccupied and valid grid in arena randomly
    int row, col;
    do {
        row = rand() % 5;
        col = rand() % 5;
    } while (arena.isOccupied(row, col));
    //place codemon
    arena.updateVisibility(row, col);
    arena.setTerrainTile(row, col, '@');
    arena.markOccupied(row, col);

    // place enemy
    do {
        row = rand() % 5;
        col = rand() % 5;
    } while (arena.isOccupied(row, col));
    //place enemy
    arena.setTerrainTile(row, col, 'E');
    arena.markOccupied(row, col);
   

    do {
        //print visible map
        arena.printVisibleMap();

        char move;
        cout << "Please choose the direction to move your Codemon (W A S D Q E Z C): ";
        cin >> move;

        movement(move, row, col, arena);
        //row and col afterward this place is the position you can use it to specify the codemon position

        //Movement for computer:
        bool Random = true;
        if (Random) {
            int num = rand() % 8;
            char moves[] = { 'W', 'A', 'S', 'D', 'Q', 'E', 'Z', 'C' };
            movement(moves[num], row, col, arena);
        }

        if (true) {//arena.isEnemyInRange(row, col, arena)
            if (true) {//isEnemyInRange(row, col, arena)
                cout << "Enemy in range! Initiating battle..." << endl;
                string response, skill;
                cout << "Do you want to attack? (yes/no)";
                cin >> response;
                if (response == "yes") {
                    battle(player, computer, arena);
                }
                else {
                    cout << "Not attacking." << endl;
                }
            }
        }
    } while (player.isAlive() && computer.isAlive());

    std::cout << "Game over";
    if (!player.isAlive()) {
        std::cout << "Computer wins.\n";
    }
    if (!computer.isAlive()) {
        std::cout << "Player wins.\n";
    }
    return 0;
} 
