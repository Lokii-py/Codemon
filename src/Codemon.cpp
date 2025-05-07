#include "Codemon.h"
#include "skill.h"

/*
// Member Function Definitions
// Private functions 
void Codemon::evolve() {
    int baseLuck = rand() % 71;
    int evolutionChance = baseLuck + (skillCount * 5);

    if (evolutionChance >= 60) {
        level++;
        int index = rand() % skillCount;
        int boost = rand() % 101;
        std::cout << name << " evolved! " << skills[index].getName() << " damage increased by " << boost << "%.\n";
        skills[index].increaseDamage(boost);
    }
}

// Public functions 
// Default constructor
Codemon::Codemon() {
    name = "Unnamed";
    type = "None";
    level = 0;
    maxHP = 0;
    currentHP = 0;
    skillCount = 0;
}

// Parameterized constructor
Codemon::Codemon(const std::string n, const std::string t, const int l, const int hpp) {
    name = n;
    type = t;
    level = l;
    maxHP = hpp;
    currentHP = hpp;
    skillCount = 0;
}

std::string Codemon::getName() const {
    return name;
}

int Codemon::getLevel() const {
    return level;
}

void Codemon::addSkill(const Skill& s) { //called from prepare function
    for (int i = 0; i < skillCount; ++i) // checks if skills is already possessed
        if (skills[i].getName() == s.getName()) {
            std::cout << "Skill already known by Codemon. Can't add skill.\n";
            return;
        }

    if (skillCount < 6) { // add skill then updates count
        skills[skillCount++] = s;
        evolve();
    }
}


int Codemon::getTypeIndex() const {
    if (type == "Fire") {
        return 0;
    }
    if (type == "Water") {
        return 1;
    }
    if (type == "Grass") {
        return 2;
    }
    if (type == "Electric") {
        return 3;
    }
    std::cout << "type index not found";
    return -1;
}

void Codemon::print() {
    /*std::cout << name << " (Type: " << type << ", Level: " << level << ", HP: " << hp << ")\n";
    std::cout << "  Skills (sorted by base damage):\n";
    // Sort skills by base damage
    for (int i = 0; i < skillCount - 1; ++i) { // bubble sort method
        for (int j = 0; j < skillCount - i - 1; ++j) {
            if (skills[j].getBaseDamage() > skills[j + 1].getBaseDamage()) {
                Skill temp = skills[j];
                skills[j] = skills[j + 1];
                skills[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < skillCount; ++i)
        skills[i].print();
    
}
*/