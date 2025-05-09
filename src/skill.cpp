#include "skill.h"
#include "Codemon.h" 
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

Skill::Skill() {
    name = " ";
    baseDamage = 0;
}

// Parameterized constructor
Skill::Skill(const string& n, int baseDamage) {
    name = n;
    this->baseDamage = baseDamage;
}

int Skill::getBaseDamage() const {
    return baseDamage;
}

std::string Skill::getName() const {
    return name;
}

void Skill::increaseDamage(int percent) {
    baseDamage += (baseDamage * percent / 100);
}

void Skill::print() const {
    std::cout << "  - " << name << " (Damage: " << baseDamage << ")\n";
}

//New function to calculate effective damage based on type chart
double Skill::getEffectiveDamage(const Codemon& attacker, const Codemon& defender) {
    int attackerType = attacker.getTypeIndex();
    int defenderType = defender.getTypeIndex();
    return baseDamage * typeChart[attackerType][defenderType];
}


