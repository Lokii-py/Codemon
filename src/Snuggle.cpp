#include "Snuggle.h"
#include "Arena.h"
#include "contestant.h"
#include <cmath>
#include <iostream>

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

void Snuggladon::placeSnug(Arena& A) {
    do {
        row = rand() % 12;
        col = rand() % 12;
    } while (A.isOccupied(row, col));
    return;
}

void Snuggladon::takeTurn(Arena& A, Contestant* roster, int total) {
    // 1) Move: choose adjacent tile that minimizes Euclidean distance to nearest Codémon
    int bestR = row, bestC = col;
    double bestDist = 1e9;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;
            int nr = row + dr, nc = col + dc;
            if (nr < 0 || nr >= Arena::SIZE || nc < 0 || nc >= Arena::SIZE) continue;
            if (A.isOccupied(nr, nc)) continue;
            // find distance to nearest contestant from that candidate tile
            double minD = 1e9;
            for (int i = 0; i < total; ++i) {
                int cr = roster[i].getRow(), cc = roster[i].getCol();
                double d = (nr - cr)*(nr - cr) + (nc - cc)*(nc - cc);
                if (d < minD) minD = d;
            }
            if (minD < bestDist) {
                bestDist = minD;
                bestR = nr;
                bestC = nc;
            }
        }
    }
    row = bestR; 
    col = bestC;
    A.setEnePos(row, col);

    // 2) Battle decision: gather adjacent contestants
    Contestant* adj[8];
    int adjCount = 0;
    for (int i = 0; i < total; ++i) {
        int cr = roster[i].getRow(), cc = roster[i].getCol();
        if (std::abs(cr - row) <= 1 && std::abs(cc - col) <= 1) {
            adj[adjCount++] = &roster[i];
        }
    }
    if (adjCount == 0) return;

    // 3) Skill priorities:
    //   a) Ancient Renewal if HP ≤ 35%
    if (currentHP <= 0.35 * maxHP) {
        useSkill("Ancient Renewal");
        return;
    }
    //   b) Cataclysm Strike if ≥2 adjacent and ready
    if (adjCount >= 2 && canUseSkill("Cataclysm Strike")) {
        useSkill("Cataclysm Strike");
        return;
    }
    //   c) Primal Fury if no buff up yet
    if (!attackBoost) {
        useSkill("Primal Fury");
        return;
    }
    //   d) Stonehide Armor if no shield yet
    if (!damageShield) {
        useSkill("Stonehide Armor");
        return;
    }
    //   e) Savage Bite otherwise
    useSkill("Savage Bite");
}
