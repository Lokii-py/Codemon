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
    alive = true;
}

// Parameterized constructor
Contestant::Contestant(std::string n) {
    name = n;
    codemonCount = 0;
    alive = true;
}

// Copy constructor
Contestant::Contestant(const Contestant& clone) {
    std::cout << "Cloning contestant: " << clone.name << "\n";
    std::cout << "Enter name for cloned contestant: ";
    std::getline(std::cin, name); // copy constructor only changes the name
    codemonCount = clone.codemonCount;

    for (int i = 0; i < codemonCount; ++i) // copies over all data
        pocket[i] = clone.pocket[i];
    alive = true;
}
 
std::string Contestant::getName() const {
    return name;
}

int Contestant::getCodemonCount() const {
    return codemonCount;
}


void Contestant::updateCodemon(const Codemon& codemon) {
    if (codemonCount >= 10) {
        std::cout << "Pocket is full.\n"; // can't add more than 10 codemons
        return;
    }

    for (int i = 0; i < codemonCount; i++) { // can't add codemon with same name
        if (pocket[i].getName() == codemon.getName()) {
            std::cout << "Codemon with the same name already exists. Can't add Codemon.\n";
            return;
        }
    }

    pocket[codemonCount++] = codemon;  // assigns codemon at index then increases count
    
}

void Contestant::selectCodemons() {
    for (int i = 0; i < 3; i++) {
        std::string codemonName, type;
        int level, hp;

        std::cin.ignore();
        std::cout << "Enter Codemon #" << i + 1 << " name: "; // taking in parameters
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
        for (int i = 0; i < 6; i++) {
            char skillChoice;
            std::cout << "Add a skill to " << codemonName << "? (y/n): ";
            std::cin >> skillChoice;
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

const int POOL_SIZE = 12;

const std::string CODEMON_NAMES[POOL_SIZE] = {
    "Flareth", // Fire
    "Aquagon", // Water
    "Leafowl", // Grass 
    "Voltiguana", // Electric 
    "Infermouse", // Fire
    "Bubbletail", // Water
    "Shrubling", // Grass 
    "Zapkit", // Electric
    "Cindermole", // Fire
    "Torrentoise", // Water 
    "Thornabbit", // Grass
    "Shockpup" // Electric
};

const std::string CODEMON_TYPES[4] = {
    "Fire",
    "Water",
    "Grass",
    "Electric",
};

const int CODEMON_HP[POOL_SIZE] = {
    40, 42, 38, 35,
    34, 45, 37, 32,
    39, 48, 40, 36
};

const int CODEMON_LEVELS[POOL_SIZE] = {
    5, 4, 2, 6,
    7, 3, 1, 0,
    8, 9, 10, 11
};

const std::string CODEMON_SKILLS[POOL_SIZE] = {
    "Flame Burst", "Aqua Jet", "Razor Leaf", "Thunder Jolt",
    "Fire Claw", "Bubble Beam", "Vine Whip", "Static Bolt",
    "Ember Rage", "Water Pulse", "Spore Shot", "Spark Bite"
};

const int CODEMON_SKILL_DAMAGE[POOL_SIZE] = {
    12, 10, 11, 13,
    15, 14, 19, 17,
    16, 18, 20, 21
};

void Contestant::generateCodemons() {
    for (int i = 0; i < 3; i++) {
        std::string codemonName, type;
        int level, hp;
        int random = rand() % 12;
        codemonName = CODEMON_NAMES[random];
        type = CODEMON_TYPES[random % 4];
        level = CODEMON_LEVELS[rand() % 12];
        hp = CODEMON_HP[rand() % 12];

        Codemon codemon(codemonName, type, level, hp); // initializes codemon with values

        // Add Skills to Cod�mon
        std::string skillName;
        int damage;

        skillName = CODEMON_SKILLS[random];
        damage = CODEMON_SKILL_DAMAGE[rand() % 12];

        Skill skill(skillName, damage); // intializes skill
        codemon.addSkill(skill);        // then adds skill
        

        updateCodemon(codemon); // adds codemon

    }

}

void Contestant::death() {
    codemonCount -= 1;
    if (codemonCount == 0) {
        alive = false;
    }
    return;
}

bool Contestant::isAlive() {
    return alive;
}

std::ostream& operator<<(std::ostream& os, const Codemon& c) {
    os << "Name: " << c.getName() << "\n";
    os << "Type: " << c.getType() << "\n";
    os << "Level: " << c.getLevel() << "\n";
    os << "HP: " << c.getCurrentHP() << "/" << c.getMaxHP() << "\n";
    return os;
}

