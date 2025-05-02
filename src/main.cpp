// Programmer: Henry Campbell
// Date: 4/25/25
// File: main.cpp
// Assignment: HW7
// Purpose: This is the Codémon simulation. The simulation creates three contestants who assemble
// their codemon teams, assign skills, and find items. It then prints out the data nicely and lastly 
// does a skill search. This new addition to HW 6 is 

#include <iostream>
#include "contestant.h"
#include "utility.h"
#include "Arena.h"

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
    int row, colm;
    do {
        row = rand() % 5;
        colm = rand() % 5;
    } while (arena.isOccupied(row, colm));

    player.print();
    computer.print();


    /*
    // Main Game Loop
    while (!player.isEliminated() && !computer.isEliminated()) {
        arena.placeCodemon(computer);
        arena.placeCodemon(player);  // place one Codemon randomly
        arena.printVisibleMap(player);

        arena.executeTurn(player, computer);     // Player turn
        if (computer.isEliminated()) break;

        arena.executeTurn(computer, player);     // CPU turn
    }

    if (player.isEliminated())
        std::cout << "\nCPU wins the battle!\n";
    else
        std::cout << "\nYou win the battle!\n";
        */
    return 0;
}
