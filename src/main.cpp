// Programmer: Henry Campbell (id: 12619823;hmcngb) and Lokesh Das (id: 12631232;ldd3g)
// Date: 4/5/25
// File: main.cpp
// Assignment: Final 
// Purpose: This is the Codemon simulation game player.


#include <iostream>
#include "Arena.h"
#include "mechanic.h"
#include "utility.h"
#include "contestant.h"
#include "skill.h"
#include "Codemon.h"
#include "item.h"

using namespace std;

int main() {
    srand(950);
    Arena arena;

    // Load skills & items from text files
    const int MAX_POOL = 50;
    const int  MAX_CONTESTANTS = 8;
    Skill skills[MAX_POOL];
    Item  items[MAX_POOL];
    Codemon codemonPool[MAX_POOL];

    loadCodemonsFromFile("codemons.txt", codemonPool, MAX_POOL);
    loadFromfile<Skill>("skills.txt", skills, MAX_POOL);
    loadFromfile<Item>("items.txt", items, MAX_POOL);

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

    Contestant* roster = new Contestant[totalContestants];

    for (int i = 0; i < numHumans; ++i) {
        string pname;
        cout << "Enter name for human #" << (i + 1) << ": ";
        cin >> pname;
        roster[i] = Contestant(pname, true, codemonPerContestant);

        char choice;
        cout << pname << ", Do you want custom selection of Codemons? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            roster[i].selectCodemons(codemonPool, MAX_POOL, true, codemonPerContestant); // Choose Codemons
        }
        else {
            roster[i].selectCodemons(codemonPool, MAX_POOL, false, codemonPerContestant); // Random Codemons
        }
    }

    for (int i = 0; i < numAI; ++i) {
        std::string aiName = "AI" + to_string(i + 1);
        roster[numHumans + i] = Contestant(aiName, false, codemonPerContestant);
        roster[numHumans + i].selectCodemons(codemonPool, MAX_POOL, false, codemonPerContestant);
    }

    // Place each contestant's active Codémon
    for (int i = 0; i < totalContestants; i++) {

        contestants[i].chooseActiveCodemon();
        arena.placeCodemonRandomly(contestants[i].getActiveCodemon(), i);
    }

    // Place Snuggladon
    Snuggladon snug(totalContestants);
    arena.placeSnuggladon(snug);

    Skill skillPool[100];
    int skillCount = loadSkillFile(skillPool);

    Item itemPool[50];
    int itemCount = loadItemFile(itemPool);

    // Shared item queue
    Item sharedQueue[20];
    int sharedQueueSize = 10;
    fillSharedItemQueue(sharedQueue, sharedQueueSize, itemPool, itemCount);

    
    // place items on battlefield

    // initialize snuggledon
    //Randomly place the active Codémons and Snuggladon

    // Place battlefield items (20% of 12x12 grid)
    int numItemsOnField = ceil(144 * 0.2);
    arena.placeItemsOnGrid(itemPool, itemCount, numItemsOnField);


    // main loop
    // contestants take turns then snuggledon
    // --- Game Loop ---
    int turnCounter = 0;
    bool gameOver = false;

    while (!gameOver) {
        turnCounter++;
        cout << "\n=== TURN " << turnCounter << " ===\n";

        for (int i = 0; i < totalContestants; i++) {
            Contestant current = roster[i];
            current.printVisibleMap(arena);
            char symbol = i;
            current.takeTurn(arena, symbol);
        }

        snug.takeTurn(arena, totalContestants);

        // Redistribute items every 5 turns
        if (turnCounter % 5 == 0) {
            arena.redistributeItems();
        }

        // Victory Check
        if (snug.getHP() <= 0) {
            cout << "Snuggladon is defeated! The Academy wins!\n";
            gameOver = true;
        }
        else {
            bool allFainted = true;
            for (int i = 0; i < totalContestants; i++) {
                if (roster[i].isAlive()) {
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

    //END
    //
