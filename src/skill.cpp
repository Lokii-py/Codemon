#include "skill.h"
<<<<<<< HEAD
#include "Constant.h"
#include "codemon.h" 
#include <iostream>
#include <string>
using namespace std;

=======

// Public functions 
// Default constructor
>>>>>>> 9a36f292603eb6ebf62a928e7da95af194c2c7d6
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
double Skill::getEffectiveDamage(const Codemon& attacker, const Codemon& defender) const {
    int attackerType = attacker.getTypeIndex();
    int defenderType = defender.getTypeIndex();
    return baseDamage * typeChart[attackerType][defenderType];
}
