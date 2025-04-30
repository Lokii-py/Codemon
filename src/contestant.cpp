#include "contestant.h"
#include <iostream>
#include <string>
using namespace std;

// Member Function Definition
// Default constructor
Contestant::Contestant() {
    std::cout << "Enter contestant name: ";
    std::getline(std::cin, name);
    codemonCount = 0;
}

// Parameterized constructor
Contestant::Contestant(std::string n) {
    name = n;
    codemonCount = 0;
}

// Copy constructor
Contestant::Contestant(const Contestant& clone) {
    std::cout << "Cloning contestant: " << clone.name << "\n";
    std::cout << "Enter name for cloned contestant: ";
    std::getline(std::cin, name); // copy constructor only changes the name
    codemonCount = clone.codemonCount;

    //for (int i = 0; i < codemonCount; ++i) // copies over all data
    //    pocket[i] = clone.pocket[i];

}

std::string Contestant::getName() const {
    return name;
}
/*
void Contestant::updateCodemon(const Codemon& codemon) {
    if (codemonCount >= 10) {
        std::cout << "Pocket is full.\n"; // can't add more than 10 codemons
        return;
    }

    for (int i = 0; i < codemonCount; ++i) { // can't add codemon with same name
        if (pocket[i].getName() == codemon.getName()) {
            std::cout << "Codemon with the same name already exists. Can't add Codemon.\n";
            return;
        }
    }

    pocket[codemonCount++] = codemon;  // assigns codemon at index then increases count
}


void Contestant::prepare() {
    std::cout << "\nPreparing contestant: " << name << "\n";

    // Add Cod�mons
    while (codemonCount < 10) {
        char choice;
        std::cout << "Add a Codemon? (y/n): ";
        std::cin >> choice;
        if (choice != 'y') break;

        std::string codemonName, type;
        int level, hp;

        std::cin.ignore();
        std::cout << "Enter Codemon name: "; // taking in parameters
        std::getline(std::cin, codemonName);
        std::cout << "Enter type: ";
        std::getline(std::cin, type);
        std::cout << "Enter level: ";
        std::cin >> level;
        std::cout << "Enter HP: ";
        std::cin >> hp;
        std::cin.ignore();

        Codemon codemon(codemonName, type, level, hp); // initializes codemon with values

        // Add Skills to Cod�mon
        for (int i = 0; i < 6; ++i) {
            char skillChoice;
            std::cout << "Add a skill to " << codemonName << "? (y/n): ";
            std::cin >> skillChoice ;
            if (skillChoice != 'y') {
                break;
            }
            std::string skillName;
            int damage;

            std::cin.ignore();
            std::cout << "  Enter skill name: "; // taking in skills info
            std::getline(std::cin, skillName);
            std::cout << "  Enter base damage: ";
            std::cin >> damage;
            std::cin.ignore();

            Skill skill(skillName, damage); // intializes skill
            codemon.addSkill(skill);        // then adds skill
        }

        updateCodemon(codemon); // adds codemon
    }

}

void Contestant::print() {
    std::cout << "\nContestant name: " << name << "\n";
    std::cout << "Number of Codemons owned: " << codemonCount << "\n";

    // Sort pocket by level
    for (int i = 0; i < codemonCount - 1; ++i) {  // bubble sort method
        for (int j = 0; j < codemonCount - i - 1; ++j) {
            if (pocket[j].getLevel() > pocket[j + 1].getLevel()) {
                Codemon temp = pocket[j];
                pocket[j] = pocket[j + 1];
                pocket[j + 1] = temp;
            }
        }
    }

    std::cout << "Pocket list (sorted by level):\n"; // prints out pocket
    for (int i = 0; i < codemonCount; ++i) {
        std::cout << "  " << (i + 1) << ") ";
        pocket[i].print();
    }

}
*/

/////////////////////////////////

void Contestant::selectCodemons() {

}

void Contestant::generateCodemons() {

}



