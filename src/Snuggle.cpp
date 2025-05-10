#include "Snuggle.h"

Snuggladon::Snuggladon(int totalContestants) {
    maxHP = 1500 + 200 * totalContestants;
    baseAttack = 150 + 20 * (totalContestants - 3);
    currentHP = maxHP;
    row = 0;
    col = 0;
    typeCount = 0;
    usedSkillCount = 0;
    lastUsedSkill = "";
    damageShield = false;
    attackBoost = false;
    assignTypes();
}

void Snuggladon::assignTypes() {
    std::string allTypes[MAX_TYPE_POOL] = {
        "Fire", "Water", "Grass", "Electric", "Psychic",
        "Dark", "Steel", "Rock", "Ghost", "Dragon"
    };

    bool chosen[MAX_TYPE_POOL] = { false };
    int count = 1 + rand() % MAX_TYPES;

    while (typeCount < count) {
        int index = rand() % MAX_TYPE_POOL;
        if (!chosen[index]) {
            types[typeCount++] = allTypes[index];
            chosen[index] = true;
        }
    }
}

void Snuggladon::printTypes() const {
    std::cout << "Snuggladon Types: ";
    for (int i = 0; i < typeCount; ++i) {
        std::cout << types[i] << " ";
    }
    std::cout << std::endl;
}

void Snuggladon::setPosition(int r, int c) {
    row = r;
    col = c;
}


//If attackBoost is true (or a nonzero value), it returns int(baseAttack * 1.3).
//If attackBoost is false (or zero), it returns baseAttack without any modification.
int Snuggladon::getBaseAttack() const {
    return attackBoost ? int(baseAttack * 1.3) : baseAttack;
}

void Snuggladon::takeDamage(int amount) {
    if (damageShield) {
        amount = std::max(0, amount - 50);
        damageShield = false;
    }
    currentHP -= amount;
    std::cout << "Snuggladon took " << amount << " damage, HP now " << currentHP << "/" << maxHP << "\n";
}

bool Snuggladon::skillPreviouslyUsed(const std::string& skill) const {
    for (int i = 0; i < usedSkillCount; ++i) {
        if (usedSkills[i] == skill)
            return true;
    }
    return false;
}

bool Snuggladon::canUseSkill(const std::string& skill) const {
    if (skill == lastUsedSkill) return false;
    if (skill == "Cataclysm Strike") {
        return usedSkillCount == 4;
    }
    return true;
}

void Snuggladon::useSkill(const std::string& skill) {
    if (!canUseSkill(skill)) {
        std::cout << "Cannot use skill: " << skill << " yet!\n";
        return;
    }

    std::cout << "Snuggladon used " << skill << "!\n";

    if (skill == "Ancient Renewal") {
        currentHP = std::min(maxHP, currentHP + maxHP / 4);
    }
    else if (skill == "Primal Fury") {
        attackBoost = true;
    }
    else if (skill == "Stonehide Armor") {
        damageShield = true;
    }
    else if (skill == "Cataclysm Strike") {
        usedSkillCount = 0;
    }

    if (skill != "Cataclysm Strike") {
        if (!skillPreviouslyUsed(skill) && usedSkillCount < 4) {
            usedSkills[usedSkillCount++] = skill;
        }
    }

    lastUsedSkill = skill;
}

void Snuggladon::getAvailableSkills(std::string output[], int& count) const {
    count = 0;
    for (int i = 0; i < 5; ++i) {
        if (allSkills[i] == lastUsedSkill) continue;
        if (allSkills[i] == "Cataclysm Strike" && usedSkillCount != 4) continue;
        output[count++] = allSkills[i];
    }
}

void Snuggladon::moveTowards(int targetRow, int targetCol, char terrainMap[5][5], bool occupied[5][5]) {
    int bestRow = row;
    int bestCol = col;
    double minDist = 1e9;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < 5 && newCol >= 0 && newCol < 5 && !occupied[newRow][newCol]) {
                double dist = pow(targetRow - newRow, 2) + pow(targetCol - newCol, 2); //euclids thingy
                if (dist < minDist) {
                    minDist = dist;
                    bestRow = newRow;
                    bestCol = newCol;
                }
            }
        }
    }

    std::cout << "Snuggladon moved from (" << row << "," << col << ") to (" << bestRow << "," << bestCol << ")\n";
    row = bestRow;
    col = bestCol;
}