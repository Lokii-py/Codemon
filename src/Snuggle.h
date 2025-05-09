#ifndef SNUGGLADON_H
#define SNUGGLADON_H

#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <cstring>

const int MAX_TYPES = 4;
const int MAX_TYPE_POOL = 10;
const int MAX_SKILLS = 5;

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
    // Post: Snuggladon object is created with necessary properties.
    Snuggladon(int totalContestants);

    // Desc: Assigns types to Snuggladon based on certain criteria.
    // Pre: none
    // Post: Snuggladon is assigned a type.
    void assignTypes();

    // Desc: Prints the current types of the Snuggladon.
    // Pre: Types must have been assigned
    // Post: Outputs type information
    void printTypes() const;

    // Desc: Sets the position of Snuggladon in the arena
    // Pre: r and c must be valid row and column indices.
    // Post: Updates Snuggladon's position.
    void setPosition(int r, int c);

    // Desc: Returns the base attack value of Snuggladon.
    // Pre: none
    // Post: Returns an integer representing base attack.
    int getBaseAttack() const;

    // Desc: Reduces Snuggladon's HP based on the damage taken.
    // Pre: amount must be a positive integer.
    // Post: HP is decreased accordingly.
    void takeDamage(int amount);

    // Desc: Checks if Snuggladon is still alive.
    // Pre: none
    // Post: Returns true if HP is greater than 0, false otherwise.
    bool isAlive() const { return currentHP > 0; }

    // Desc: Determines if a specific skill has been used before.
    // Pre: skill must be a valid string.
    // Post: Returns true if skill has been used, false otherwise.
    bool skillPreviouslyUsed(const std::string& skill) const;

    // Desc: Determines whether Snuggladon can use a given skill.
    // Pre: skill must be a valid string.
    // Post: Returns true if skill can be used, false otherwise.
    bool canUseSkill(const std::string& skill) const;

    // Desc: Executes a specified skill for Snuggladon.
    // Pre: skill must be a valid string and Snuggladon must be able to use it.
    // Post: Skill is applied.
    void useSkill(const std::string& skill);

    // Desc: Retrieves a list of available skills for Snuggladon.
    // Pre: Output array must be properly allocated; count tracks available skills.
    // Post: Fills output array with skill names and updates count.
    void getAvailableSkills(std::string output[], int& count) const;

    // Desc: Moves Snuggladon toward a specified target position
    // Pre: targetRow and targetCol must be valid coordinates; 
    // Post: Updates Snuggladon's position accordingly.
    void moveTowards(int targetRow, int targetCol, char terrainMap[5][5], bool occupied[5][5]);

};

#endif
