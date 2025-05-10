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

//New function to calculate effective damage based on type chart
double Skill::getEffectiveDamage(const Codemon& attacker, const Codemon& defender) {
    int attackerType = attacker.getTypeIndex();
    int defenderType = defender.getTypeIndex();
    return baseDamage * typeChart[attackerType][defenderType];
}
