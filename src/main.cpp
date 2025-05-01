// Programmer: Henry Campbell
// Date: 4/25/25
// File: main.cpp
// Assignment: HW7
<<<<<<< HEAD:main.cpp
// Purpose: This is the Codémon simulation. The simulation creates three contestants who assemble
=======
// Purpose: This is the Cod�mon simulation. The simulation creates three contestants who assemble
>>>>>>> origin/Lokii:src/main.cpp
// their codemon teams, assign skills, and find items. It then prints out the data nicely and lastly 
// does a skill search. This new addition to HW 6 is 
#include "Arena.h"
#include <iostream>
#include "contestant.h"
#include "utility.h"
using namespace std;

int main() {

    Arena arena; //Initalize the battle arena
    Contestant Player("Player"), Computer("CPU"); //initalize the contestant

    // Set random seed ONCE
    srand(1025);

    arena.generateTerrain(); // Fill terrainMap with valid terrain
	arena.printTerrainForDebug(); 
    
    char choice;
    std::cout << "PLAYER: DO you want custom selection of Codemons? (y/n)\n";
    std::cin >> choice;   // user selects or random
    if (choice == 'y') {
<<<<<<< HEAD:main.cpp
        player.selectCodemons();      // choose three codemons
=======
        player.selectCodemons();
>>>>>>> origin/Lokii:src/main.cpp
    }
    else {
        player.generateCodemons();  // generate three codemons
    }
    computer.generateCodemons();

    //Deploy codemon to the unoccupied and valid grid in arena randomly
    int row, colm;
    do{
        row = rand() % 5;
        colm = rand() % 5;
    } while (arena.isOccupied(row, colm))

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
