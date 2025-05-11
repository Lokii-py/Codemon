#include "mechanic.h"
#include "Arena.h"
#include "contestant.h"
#include "Snuggle.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Snuggladon;
class Contestant;

void movement(char move, char type, Arena& arena) {

    int row = arena.getCurRow();
    int col = arena.getCurCol();

    int n_row = row;
    int n_col = col;

    switch (move) {
    case 'W':
        n_row = row - 1;
        break;
    case 'A':
        n_col = col - 1;
        break;
    case 'S':
        n_row = row + 1;
        break;
    case 'D':
        n_col = col + 1;
        break;
    case 'Q':
        n_row = row - 1;
        n_col = col - 1;
        break;
    case 'E':
        n_row = row - 1;
        n_col = col + 1;
        break;
    case 'Z':
        n_row = row + 1;
        n_col = col - 1;
        break;
    case 'C':
        n_row = row + 1;
        n_col = col + 1;
        break;
    default:
        cout << "Invalid Input!" << endl;
        break;
        return;
    }

    if (n_row < 0 || n_row >= 12 || n_col < 0 || n_col >= 12) {
        cout << "Out of bounds." << endl;
        return;
    }

    // Example check tile is not blocked (optional)
    if (arena.isOccupied(n_row, n_col)) {
        cout << "Tile occupied." << endl;
        return;
    }
    arena.setCurPos(n_row, n_col);
    //arena.setTerrainTile(n_row, n_col, type);
    return;
}

void battle(Contestant& player, Snuggladon& snug, bool isHuman) {
    Codemon codemon = player.getActive();

    int skillCount = codemon.getSkillCount();

    if (isHuman) {
        // Show Codémon status
        cout << "\nYour Active Codémon:\n";
        codemon.print();

        // Show Snuggladon status
        cout << "\nSnuggladon Status:\n";
        snug.printTypes();
        cout << "HP: " << snug.getHP() << "/" << snug.getMaxHP() << "\n";
        if (snug.hasAttackBoost()) cout << "Status: Enraged (Attack Boosted)\n";
        if (snug.hasDamageShield()) cout << "Status: Shielded (Damage Reduced)\n";

        // Prompt user
        char choice;
        cout << "\nDo you want to battle Snuggladon? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            cout << "You chose not to battle this turn.\n";
            return;
        }

        // Show available skills
        cout << "\nAvailable Skills:\n";
        for (int i = 0; i < skillCount; i++) {
            cout << i << ". ";
            codemon.getSkill(i).print(); // Assuming Skill has a print() method
        }

        int chosen;
        do {
            cout << "Choose a skill to use (0-" << (skillCount - 1) << "): ";
            cin >> chosen;
        } while (chosen < 0 || chosen >= skillCount);
        Skill chosenSkill = codemon.getSkill(chosen);

        double multiplier = 1.0;
        for (int i = 0; i < snug.getTypeCount(); ++i) {
            std::string defenderType = snug.getType(i);
            multiplier *= chosenSkill.getMultiplier(chosenSkill.getType(), defenderType);
        }

        int finalDamage = static_cast<int>(chosenSkill.getBaseDamage() * multiplier);

        // Announce
        cout << "\nYou used " << chosenSkill.getName() << " (" << chosenSkill.getType() << ")!";
        cout << "\nEffectiveness multiplier: x" << multiplier << endl;
        cout << "Total damage: " << finalDamage << endl;

        snug.takeDamage(finalDamage);

    }
    else {
        // AI always attacks if adjacent
        int chosen = rand() % skillCount;
        Skill selectedSkill = codemon.getSkill(chosen);
        cout << player.getName() << "'s Codémon uses " << selectedSkill.getName() << "!\n";

        double multiplier = 1.0;
        for (int i = 0; i < snug.getTypeCount(); ++i) {
            std::string defenderType = snug.getType(i);
            multiplier *= selectedSkill.getMultiplier(selectedSkill.getType(), defenderType);
        }

        int finalDamage = static_cast<int>(selectedSkill.getBaseDamage() * multiplier);

        snug.takeDamage(finalDamage);
    }
}
