// Programmer: Henry Campbell
// Date: 4/25/25
// File: main.cpp
// Assignment: HW7
// Purpose: This is the Cod�mon simulation. The simulation creates three contestants who assemble
// their codemon teams, assign skills, and find items. It then prints out the data nicely and lastly 
// does a skill search. This new addition to HW 6 is 
#include "Arena.h"
#include "contestant.h"
#include "Constant.h"
#include "mechanic.h"
#include <iostream>
using namespace std;

int main() {

    Arena arena; //Initalize the battle arena
    Contestant Player("Player"), Computer("CPU"); //initalize the contestant
    BattleGround battle;

    // Set random seed ONCE
    srand(1025);

    arena.generateTerrain(); // Fill terrainMap with valid terrain
	arena.printTerrainForDebug();
    
    char choice;
    std::cout << "Would player like custom selection of Codemons? (y/n)\n";
    std::cin >> choice;   // user selects or random
    if (choice == 'y') {
        player.selectCodemons();
    }
    else {
        player.generateCodemons();
    }
    computer.generateCodemons();

    //Deploy codemon to the unoccupied and valid grid in arena randomly
    int row, col;
    do{
        row = rand() % 5;
        col = rand() % 5;
    }  while (arena.isOccupied(row, col));
    
    char move;
    cout << "Please choose the place to position your codemon: ";
    cin >> move;
    
    movement(move, row, col, arena);
    //row and col afterward this place is the position you can use it to specify the codemon position
    // TO DO: Put codemon position in the arena grid displaying 3 *3 grid .
    
    //Movement for computer:
    bool Random = true;
    if (Random) {
        int num = rand() % 8;
        char moves[] = {'W', 'A', 'S', 'D', 'Q', 'E', 'Z', 'C'};
        movement(moves[num], row, col, arena, true);
    }

    if(Player && battle.isEnemyInRange(row, col, arena)){
        cout<< "Enemy in range! Initiating battle..." << endl;
        string response, skill;
        cout << "Do you want to attack? (yes/no)";
        cin >> response;
        if (response == "yes") {
            cout << "Select a skill to attack with: ";
            cin >> skill;
        } else {
            cout << "Not attacking." << endl;
        }
    }

    if(Computer && battle.isEnemyInRange(row, col, arena)){
        // start attacter
    }
    
    return 0;
}
