#include "Codemon.h"
#include "skill.h"
#include <iostream>
#include <string>
using namespace std;

const double typeChart[11][11] = {
    /* Fire   */   {1.0, 0.5, 2.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0},
    /* Water  */   {2.0, 1.0, 0.5, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0},
    /* Grass  */   {0.5, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 1.0},
    /* Electric */ {1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0},
    /* Ice    */   {0.5, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0},
    /* Rock   */   {2.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0},
    /* Normal */   {1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 0.5, 0.5, 1.0},
    /* Psychic*/   {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 2.0, 0.5, 1.0},
    /* Dark   */   {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 2.0},
    /* Steel  */   {0.5, 0.5, 1.0, 0.5, 2.0, 2.0, 1.0, 1.0, 1.0, 0.5, 2.0},
    /* Fairy  */   {0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0}
};

int typeToIndex(const std::string& type) {
    if (type == "Fire") return 0;
    if (type == "Water") return 1;
    if (type == "Grass") return 2;
    if (type == "Electric") return 3;
    if (type == "Ice") return 4;
    if (type == "Rock") return 5;
    if (type == "Normal") return 6;
    if (type == "Psychic") return 7;
    if (type == "Dark") return 8;
    if (type == "Steel") return 9;
    if (type == "Fairy") return 10;
    return -1; // Invalid type
}

Skill::Skill() {
    name = " ";
    type = " ";
    description = " ";
    baseDamage = 0;
}

// Parameterized constructor
Skill::Skill(const std::string& n, const std::string& t, int baseDamage, const std::string& desc) {
    name = n;
    type = t;
    this->baseDamage = baseDamage;
    description = desc;
}

int Skill::getBaseDamage() const {
    return baseDamage;
}

string Skill::getName() const {
    return name;
}

void Skill::increaseDamage(int percent) {
    baseDamage += (baseDamage * percent / 100);
}

void Skill::print() const {
    cout << "  - " << name
        << " [" << type << "]  Dmg: " << baseDamage
        << "  — " << description << '\n';
}

double Skill::getMultiplier(const std::string& attacker, const std::string& defender) {
    int atkIndex = typeToIndex(attacker);
    int defIndex = typeToIndex(defender);

    if (atkIndex == -1 || defIndex == -1) {
        std::cerr << "Invalid type(s): " << attacker << " vs. " << defender << std::endl;
        return 1.0; // Default neutral effectiveness
    }

    return typeChart[atkIndex][defIndex];
}