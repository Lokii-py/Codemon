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

int main() {
    ///////////////////////////////////////////////////////////////

    srand(1025); // Set random seed ONCE

    Arena arena;
    arena.generateTerrain(); // Fill terrainMap with valid terrain
	arena.printTerrainForDebug(); 

    // Create contestants
    Contestant player("Player");
    Contestant computer("CPU");
    
    char choice;
    std::cout << "Would player like custom selection of Codemons? (y/n)\n";
    std::cin >> choice;   // user selects or random
    if (choice == 'y') {
        player.selectCodemons();     
    }
    else {
        player.generateCodemons();
    }
    computer.generateCodemons(); // random from pool

    /*
    arena.placeCodemon(computer);
    arena.placeCodemon(player);  // place one Codemon randomly

    arena.printVisibleMap(player);
    /*
    // Main Game Loop
    while (!player.isEliminated() && !computer.isEliminated()) {
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
