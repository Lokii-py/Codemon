// Programmer: Henry Campbell (id: 12619823;hmcngb) and Lokesh Das (id: 12631232;ldd3g)
// Date: 5/5/25
// File: main.cpp
// Assignment: Final 
// Purpose: This is the Codemon simulation game player.


#include <iostream>
#include <cmath>
#include "Arena.h"
#include "mechanic.h"
#include "utility.h"
#include "contestant.h"
#include "skill.h"
#include "Codemon.h"
#include "item.h"
#include "Snuggle.h"

using namespace std;

void giveThreeSkills(Codemon* team, int teamSize, Skill* skillPool, int skillCount);

int main() {
    srand(950);
    Arena arena;
    
    const int MaxSkill = countLinesInFile("skills.txt");
    const int MaxItem = countLinesInFile("items.txt");
    const int MaxCodemons = countLinesInFile("codemons.txt");
    
    // Load skills & items from text files
    const int  MAX_CONTESTANTS = 8;
    Skill skills[MaxSkill];
    Item  items[MaxItem];
    Codemon codemonPool[MaxCodemons];

    loadCodemonsFromFile("codemons.txt", codemonPool, MaxCodemons);
    loadFromfile<Skill>("skills.txt", skills, MaxSkill);
    loadFromfile<Item>("items.txt", items, MaxItem);

    cout << "Welcome to Codemon Arena – United-We-Stand" << endl;

    // Player setup
    int numHumans, numAI;
    do {
        cout << "Enter number of human players: ";
        cin >> numHumans;
        cout << "Enter number of AI contestants: ";
        cin >> numAI;
    } while (numHumans + numAI < 2 || numHumans + numAI > MAX_CONTESTANTS);

    int totalContestants = numHumans + numAI;
    
    Contestant::initSharedQueue(2 * totalContestants);
    
    int codemonPerContestant;
    cout << "Enter the number of Codemon in Your Team: ";
    cin >> codemonPerContestant;

    Contestant* roster = new Contestant[totalContestants];

    for (int i = 0; i < numHumans; ++i) {
        cout << endl << "--- Player #" << (i+1) << " setup ---" << endl;
        string pname;
        cout << "Enter name for Player #" << (i + 1) << ": ";
        cin >> pname;
        
        roster[i] = Contestant(pname, true, codemonPerContestant);
        roster[i].setTeamSize(codemonPerContestant);

        char choice;
        cout << pname << ", Do you want custom selection of Codemons? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            roster[i].selectCodemons(codemonPool, MaxCodemons, false); // Choose Codemons
        }
        else {
            roster[i].selectCodemons(codemonPool, MaxCodemons, true); // Random Codemons
        }
        giveThreeSkills(roster[i].getTeam(), codemonPerContestant, skills, MaxSkill);
        
        // initial active selection
        int pick;
        cout << "Select your starting Codemon (0 - " << (codemonPerContestant-1) << "): ";
        cin >> pick;
        roster[i].setActiveCodemon(pick);
    }

    for (int i = 0; i < numAI; ++i) {
        std::string aiName = "AI" + to_string(i + 1);
        roster[numHumans + i] = Contestant(aiName, false, codemonPerContestant);
        roster[numHumans + i].selectCodemons(codemonPool, MaxCodemons, true);
        giveThreeSkills(roster[numHumans + i].getTeam(), codemonPerContestant, skills, MaxSkill);
        roster[numHumans + i].setActiveCodemon(rand() % codemonPerContestant);
    }
    
    char glyph[] = {'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I'};
    
    // Place each contestant's active Codémon
    for (int i = 0; i < totalContestants; i++) {;
        roster[i].placeRandomCodemon(arena);
        roster[i].spawn(arena, roster[i].getRow(), roster[i].getCol(), glyph[i]);
    }


    // Creat and place Snuggladon
    Snuggladon snug(totalContestants);
    snug.placeSnug(arena);
    //arena.setTerrainTile(snug.getRow(), snug.getCol(), 'E');  // show Enemy
    arena.setEnePos(snug.getRow(), snug.getCol());

    // Place battlefield items (20% of 12x12 grid)
    int numItemsOnField = ceil(144 * 0.2);
    arena.placeItemsOnGrid(items, MaxItem, numItemsOnField);

    // --- Game Loop ---
    int turnCounter = 0;
    bool gameOver = false;

    while (!gameOver) {
        turnCounter++;
        cout << endl << "=== TURN " << turnCounter << " ===" << endl;

        for (int i = 0; i < totalContestants; i++) {
            arena.resetVisibility();
            Contestant& current = roster[i];
            arena.setCurPos(current.getRow(), current.getCol());
            arena.updateVisibility(current.getRow(), current.getCol());
            arena.setOccupied(roster[i].getRow(), roster[i].getCol(), true);
            if (current.isHum()){
                current.printVisibleMap(arena);
            }
            
            if (current.isHum()) {
                char useIt;
                cout << current.getName() << ", Use next item? (y/n): ";
                cin >> useIt;
                if (useIt=='y' || useIt=='Y'){
                    current.useNextItem();
                }
            }
            
            current.takeTurn(arena, glyph[i]);

            int row = current.getRow();
            int col = current.getCol();
            arena.setOccupied(row, col, true);
            arena.setCurPos(row, col);
            arena.updateVisibility(row, col);
            
            // item pick-up phase
            if (arena.hasItemAt(row, col)) {
                Item found = arena.dequeueItemAt(row, col);
                current.enqueueItem(found);
                cout << "["<< current.getName() <<"] picked up: ";
                found.print();
            }
            
            if (arena.isSnugInRange(row, col)) {
                battle(current, snug, current.isHum());
            }
        }

        snug.takeTurn(arena, roster, totalContestants);
        arena.setEnePos(snug.getRow(), snug.getCol());
        arena.updateVisibility(snug.getRow(), snug.getCol());


        // Redistribute items every 5 turns
        if (turnCounter % 5 == 0) {
            arena.redistributeItems();
        }

        // Victory Check
        if (snug.getHP() <= 0) {
            cout << "Snuggladon is defeated! The Academy wins!" << endl;
            gameOver = true;
        }
        else {
            bool allFainted = false;
            for (int i = 0; i < totalContestants; i++) {
                if (roster[i].isAlive()) {
                    allFainted = true;
                    break;
                }
            }
            if (!allFainted) {
                cout << "All Codémons are fainted. Snuggladon wins!" << endl;
                gameOver = true;
            }
        }
    }
    delete[] roster;
    return 0;
}

// Assign 3 matching-type skills to each Codemon from the skill pool
void giveThreeSkills(Codemon* team, int teamSize, Skill* skillPool, int skillCount) {
    for (int i = 0; i < teamSize; ++i) {
        string codemonType = team[i].getType();
        int assigned = 0;
        for (int j = 0; j < skillCount && assigned < 3; ++j) {
            if (skillPool[j].getType() == codemonType) {
                team[i].addSkill(skillPool[j]);
                assigned++;
            }
        }
    }
}