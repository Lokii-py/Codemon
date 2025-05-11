#ifndef SNUGGLADON_H
#define SNUGGLADON_H
#include "contestant.h"

#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <cstring>

const int MAX_TYPES = 4;
const int MAX_TYPE_POOL = 10;
const int MAX_SKILLS = 5;

class Arena;

class Snuggladon {
private:
    int maxHP;
    int currentHP;
    int baseAttack;
    int row, col;
    std::string types[MAX_TYPES];
    int typeCount;

    std::string lastUsedSkill;
    std::string usedSkills[4]; // For tracking last 4 non-cataclysm skills
    int usedSkillCount;

    bool damageShield;
    bool attackBoost;

    std::string allSkills[5] = {
        "Ancient Renewal",
        "Primal Fury",
        "Stonehide Armor",
        "Savage Bite",
        "Cataclysm Strike"
    };

public:
    // Desc: Constructor that initializes a Snuggladon with a given number of contestants.
    // Pre: totalContestants must be a valid integer.
    // Post: Initializes Snuggladon's HP, attack, types, and internal state.
    Snuggladon(int totalContestants);

    // Desc: Assigns types to Snuggladon based on certain criteria.
    // Pre: None.
    // Post: Types are assigned to the Snuggladon.
    void assignTypes();

    // Desc: Prints the current types of the Snuggladon.
    // Pre: Types must have been assigned.
    // Post: Outputs type information to console.
    void printTypes() const;

    // Desc: Returns the base attack value of Snuggladon.
    // Pre: None.
    // Post: Returns an integer representing base attack.
    int getBaseAttack() const;

    // Desc: Reduces Snuggladon's HP based on the damage taken.
    // Pre: amount must be a positive integer.
    // Post: Reduces HP if damage shield is not active.
    void takeDamage(int amount);

    // Desc: Checks if Snuggladon is still alive.
    // Pre: None.
    // Post: Returns true if HP is greater than 0; false otherwise.
    bool isAlive() const { return currentHP > 0; }

    // Desc: Determines if a specific skill has been used before.
    // Pre: skill must be a valid string.
    // Post: Returns true if skill was used recently (excluding Cataclysm).
    bool skillPreviouslyUsed(const std::string& skill) const;

    // Desc: Determines whether Snuggladon can use a given skill.
    // Pre: skill must be valid and follow cooldown/use restrictions.
    // Post: Returns true if skill is usable at current turn.
    bool canUseSkill(const std::string& skill) const;

    // Desc: Executes a specified skill for Snuggladon.
    // Pre: Skill must be valid and usable based on logic.
    // Post: Applies effects of skill, updating state and cooldowns.
    void useSkill(const std::string& skill);

    // Desc: Retrieves a list of currently available (usable) skills.
    // Pre: output array must be preallocated; count is by reference.
    // Post: Fills output[] with names of usable skills; updates count.
    void getAvailableSkills(std::string output[], int& count) const;

    // Desc: Returns the current HP of Snuggladon.
    // Pre: None.
    // Post: Returns an integer value of current HP.
    int getHP() { return currentHP; }

    // Desc: Returns the number of types assigned to Snuggladon.
    // Pre: None.
    // Post: Returns an integer from 1 to MAX_TYPES.
    int getTypeCount() const { return typeCount; }

    // Desc: Returns a specific type assigned to Snuggladon.
    // Pre: index must be in range [0, typeCount).
    // Post: Returns type string at given index.
    std::string getType(int index) { return types[index]; }

    // Desc: Returns a pointer to all types assigned to Snuggladon.
    // Pre: None.
    // Post: Returns pointer to array of type strings.
    std::string* getTypes() { return types; }

    // Desc: Returns maximum HP of Snuggladon.
    // Pre: None.
    // Post: Returns an integer value for maximum HP.
    int getMaxHP() const { return maxHP; }

    // Desc: Checks whether Snuggladon currently has an active attack boost.
    // Pre: None.
    // Post: Returns true if boost is active.
    bool hasAttackBoost() const { return attackBoost; }

    // Desc: Checks whether Snuggladon currently has a damage shield.
    // Pre: None.
    // Post: Returns true if shield is active.
    bool hasDamageShield() const { return damageShield; }

    // Desc: Returns the current row position of Snuggladon.
    // Pre: None.
    // Post: Returns an integer row index.
    int getRow() const { return row; }

    // Desc: Returns the current column position of Snuggladon.
    // Pre: None.
    // Post: Returns an integer column index.
    int getCol() const { return col; }

    // Desc: Places Snuggladon on the arena at a valid unoccupied tile.
    // Pre: Arena object A must be valid and configured.
    // Post: Snuggladon is placed on the map; arena updated accordingly.
    void placeSnug(Arena& A);
    
    void takeTurn(Arena& arena, Contestant* roster, int totalContestants);


  
};
#endif