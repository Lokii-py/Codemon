#include "Codemon.h"
#include "skill.h"
#include <iostream>
#include <string>
using namespace std;

Codemon::Codemon() {
	name = "Unnamed";
	type = "None";
	description = " ";
	level = 0;
	maxHP = 0;
	currentHP = 0;
	skillCount = 0;
}

Codemon::Codemon(const string n, const string desc, const string type, const int level, const int hp) {
	name = n;
	description = desc;
	this->type = type;

	if (level < 1) {
		this->level = 1;
	}
	else if (level > 20) {
		this->level = 20;
	}
	else {
		this->level = level;
	}

	if (hp < 200) {
		maxHP = 200;
	}
	else if (hp > 500) {
		maxHP = 500;
	}
	else {
		maxHP = hp;
	}
	currentHP = hp;
	skillCount = 0;
}

Codemon::Codemon(std::string name, std::string type, std::string desc) {
	this->name = name;
	this->type = type;
	this->description = desc;
	level = rand() % 20 + 1;
	maxHP = 200 + rand() % 301; // 200–500
	currentHP = maxHP;
	skillCount = 0;
}

int Codemon::getMaxHP() const {
	return maxHP;
}
int Codemon::getLevel() const {
	return level;
}
double Codemon::getCurrentHP() const {
	return currentHP;
}

string Codemon::getName() const {
	return name;
}

string Codemon::getType() const {
	return type;
}

int Codemon::getTypeIndex() const {
	const string typeList[11] = {
		"Fire", "Water", "Grass", "Electric", "Ice",
		"Rock", "Normal", "Psychic", "Dark", "Steel", "Fairy"
	};
	for (int i = 0; i < 11; ++i) {
		if (type == typeList[i]) {
			return i;
		}
	}
	return 0;
}

int Codemon::getSkillCount() const {
	return skillCount;
}

void Codemon::takeDamage(double dmg) {
    // apply shield first
    if (shieldAmount > 0) {
        double absorbed = std::min(static_cast<double>(shieldAmount), dmg);
        dmg -= absorbed;
        shieldAmount = 0;
    }
    currentHP -= dmg;
    if (currentHP < 0) currentHP = 0;
}

void Codemon::heal(double healHP) {
	if (currentHP > (0.7 * maxHP)) {
		cout << "OOPS!! Cannot Apply heal Now, Codemon's HP is above 70%." << endl;
		return;
	}
	currentHP += healHP;
	if (currentHP > maxHP) {
		currentHP = maxHP;
	}
}

bool Codemon::isFainted() const {
	return currentHP <= 0;
}

bool Codemon::addSkill(const Skill& s) {
	if (skillCount >= 5) {
		return false;
	}
	skills[skillCount++] = s;
	return true;
}

const Skill& Codemon::getSkill(int idx) const {
	if (idx < 0 || idx >= skillCount) {
		cerr << "Invalid skill index." << endl;
		exit(1);
	}
	return skills[idx];
}

void Codemon::print() const {
	cout << name << " (Type: " << type << ", Level: " << level << ", HP: " << currentHP << "/" << maxHP << ")\n";
	cout << "  Skills (sorted by base damage):\n";

	// Sort copy of skills array by base damage
	Skill sorted[5];
	for (int i = 0; i < skillCount; ++i) sorted[i] = skills[i];
	for (int i = 0; i < skillCount - 1; ++i) {
		for (int j = 0; j < skillCount - i - 1; ++j) {
			if (sorted[j].getBaseDamage() > sorted[j + 1].getBaseDamage()) {
				Skill temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < skillCount; ++i) {
		sorted[i].print();
	}
}

void Codemon::increaseDamage(int amount) {
    // store flat boost; applies only to the next attack
    damageBoost = amount;
}

void Codemon::setShield(int amount) {
    // store shield; applies only to the next incoming damage
    shieldAmount = amount;
}

bool operator==(const Codemon& lhs, const Codemon& rhs) {
	return lhs.name == rhs.name &&
		lhs.type == rhs.type &&
		lhs.description == rhs.description;
}