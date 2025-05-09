// Programmer: Henry Campbell (id: 12619823;hmcngb) and Lokesh Das (id: 12631232;ldd3g)
// Date: 4/5/25
// File: main.cpp
// Assignment: Final 
// Purpose: This is the Codemon simulation game player.


// remember to overload  == and !=


#include "Arena.h"
#include "contestant.h"
#include "mechanic.h"
#include "Snuggle.h"
#include <iostream>
#include <cstdlib>
#include <cstring> // for strchr
using namespace std;

const int MAX_CONTESTANTS = 8;

int main() {
    srand(950); // Set random seed once

    Arena arena; // Initialize the battle arena
    

    
    // Player setup
    int numHumans, numAI;
    do {
        cout << "Enter number of human players: ";
        cin >> numHumans;
        cout << "Enter number of AI contestants: ";
        cin >> numAI;
    } while (numHumans + numAI < 2 || numHumans + numAI > MAX_CONTESTANTS);

    int totalContestants = numHumans + numAI;

    int codemonPerContestant;
    cout << "How many Codemons per contestant? ";
    cin >> codemonPerContestant;

/*


   --dynamically create an array of contestants and an array of Codémons for each contestant’s team.
   -- initialize contesants-  do loop

   1. computer controlled codemons read in
   2. randomly assign to teams

   *////////////////////////



    
    // same human player gameplay as HW7
    // do loop for multiple players
    // Codémon selection
    char choice;
    cout << "PLAYER: Do you want custom selection of Codemons? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
       // player.selectCodemons(); // Choose 3 Codemons
    }
    else {
        //player.generateCodemons(); // Random Codemons
    }
    //computer.generateCodemons(); // CPU always uses random

    //SKILLS
    //read in skills and assign randomly for the computer controlled contestants
    // option player controlled contestants do loop


    //ITEMS
    //load items
    //After reading the list of available items into a temporary array, 
    // randomly select items from it to populate the shared item queue to its full capacity. 
    // create shared item queue

    // place items on battlefield

    // initialize snuggledon
    //Randomly place the active Codémons and Snuggladon


    // main loop
    // contestants take turns then snuggledon


    //END
    //




    /////////////////////////////////// end of outline

    // Place Player Codemon
    int playerRow, playerCol;
    do {
        playerRow = rand() % 12;
        playerCol = rand() % 12;
    } while (arena.isOccupied(playerRow, playerCol));
    arena.setTerrainTile(playerRow, playerCol, '@');
    arena.updateVisibility(playerRow, playerCol, '@');
    arena.markOccupied(playerRow, playerCol);

    // Place CPU Codemon
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

        movement(move, '@', arena);

        // Check if enemy is in range and handle battle
        if (arena.isEnemyInRange(playerRow, playerCol)) {
            cout << "Enemy in range! Initiating battle..." << endl;
            string response;
            cout << "Do you want to attack? (yes/no): ";
            cin >> response;
            if (response == "yes") {
                battle(player, computer, arena, playerRow, playerCol); // ? updated call
            }
            else {
                cout << "You chose not to attack.\n";
            }
            continue; // Skip CPU move if battle occurs
        }

        // CPU move (random)
        char moves[] = { 'W', 'A', 'S', 'D', 'Q', 'E', 'Z', 'C' };
        char cpuMove = moves[rand() % 8];
        movement(cpuMove, 'E', arena);
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

/*
// Programmer: Henry Campbell (id: 12619823;hmcngb) and Lokesh Das (id: 12631232;ldd3g)
// Date: 4/25/25
// File: main.cpp
// Assignment: HW7
// Purpose: Codemon simulation game entry point.

#include "Arena.h"
#include "contestant.h"
#include "mechanic.h"
#include "Snuggle.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const int MAX_CONTESTANTS = 8;
const int MAX_GRID = 5;
const int TOTAL_CELLS = MAX_GRID * MAX_GRID;

int main() {
    srand(950);  // Set fixed random seed

    Arena arena;
    arena.generateTerrain();
    arena.printTerrainForDebug();  // Optional for debugging

    // Player setup
    int numHumans, numAI;
    do {
        cout << "Enter number of human players: ";
        cin >> numHumans;
        cout << "Enter number of AI contestants: ";
        cin >> numAI;
    } while (numHumans + numAI < 2 || numHumans + numAI > MAX_CONTESTANTS);

    int totalContestants = numHumans + numAI;

    int codemonPerContestant;
    cout << "How many Codémons per contestant? ";
    cin >> codemonPerContestant;

    // Load Codémon, Skills, Items
    Codemon codemonPool[100];
    int codemonCount = loadCodemonFile(codemonPool);

    Skill skillPool[100];
    int skillCount = loadSkillFile(skillPool);

    Item itemPool[50];
    int itemCount = loadItemFile(itemPool);

    // Shared item queue
    Item sharedQueue[20];
    int sharedQueueSize = 10;
    fillSharedItemQueue(sharedQueue, sharedQueueSize, itemPool, itemCount);

    // Create contestants (objects)
    Contestant contestants[MAX_CONTESTANTS];

    for (int i = 0; i < totalContestants; i++) {
        string name;
        if (i < numHumans) {
            name = "Player" + to_string(i + 1);
        } else {
            name = "CPU" + to_string(i + 1 - numHumans);
        }

        contestants[i].setName(name.c_str());

        char choice = 'n';
        if (i < numHumans) {
            cout << name << ": Do you want custom Codémon selection? (y/n): ";
            cin >> choice;
        }

        if (choice == 'y' || choice == 'Y') {
            contestants[i].selectCodemons(codemonPerContestant);
        } else {
            contestants[i].generateCodemons(codemonPool, codemonCount, codemonPerContestant);
        }

        contestants[i].assignSkillsToCodemons(skillPool, skillCount);
    }

    // Place battlefield items (20% of 5x5 grid)
    int numItemsOnField = ceil(TOTAL_CELLS * 0.2);
    arena.placeItemsOnGrid(itemPool, itemCount, numItemsOnField);

    // Place each contestant's active Codémon
    for (int i = 0; i < totalContestants; i++) {
        contestants[i].chooseActiveCodemon();
        arena.placeCodemonRandomly(contestants[i].getActiveCodemon(), i);
    }

    // Place Snuggladon
    Snuggle snug("Snuggladon");
    arena.placeSnuggladon(snug);

    // --- Game Loop ---
    int turnCounter = 0;
    bool gameOver = false;

    while (!gameOver) {
        turnCounter++;
        cout << "\n=== TURN " << turnCounter << " ===\n";

        for (int i = 0; i < totalContestants; i++) {
            arena.printVisibleMapForContestant(i);
            contestants[i].takeTurn(arena, sharedQueue, sharedQueueSize);
        }

        snug.takeTurn(arena, contestants, totalContestants);

        // Redistribute items every 5 turns
        if (turnCounter % 5 == 0) {
            arena.redistributeItems();
        }

        // Victory Check
        if (snug.getHP() <= 0) {
            cout << "Snuggladon is defeated! The Academy wins!\n";
            gameOver = true;
        } else {
            bool allFainted = true;
            for (int i = 0; i < totalContestants; i++) {
                if (contestants[i].hasAliveCodemon()) {
                    allFainted = false;
                    break;
                }
            }
            if (allFainted) {
                cout << "All Codémons are fainted. Snuggladon wins!\n";
                gameOver = true;
            }
        }
    }

    return 0;
}

*/