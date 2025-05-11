#ifndef CODEMON_H
#define CODEMON_H

#include "skill.h"
#include <iostream>
#include <string>

class Arena;
class Skill;

class Codemon {
private:
    string name;
    string description;
    int maxHP;
    string type; // Fire, Water, etc.
    int level;
    Skill skills[5];
    double currentHP;
    int skillCount;
    int damageBoost = 0;    // adds flat damage to next attack
    int shieldAmount = 0;   // absorbs damage on next hit

public:
    // Desc: Default constructor.
    // Pre: None.
    // Post: Initializes a Codemon with default values.
    Codemon();

    // Desc: Full parameterized constructor.
    // Pre: Valid name, description, type, level, and HP values.
    // Post: Initializes a Codemon with full stats.
    Codemon(const string n, const string desc, const string type, const int level, const int hp);

    // Desc: Simplified constructor with just name, type, and description.
    // Pre: Valid name, type, and description.
    // Post: Initializes Codemon, likely used during early data loading.
    Codemon(std::string name, std::string type, std::string desc);

    // Desc: Returns the maximum HP of the Codemon.
    // Pre: None.
    // Post: Returns an integer representing max HP.
    int getMaxHP() const;

    // Desc: Returns the Codemon's level.
    // Pre: None.
    // Post: Returns an integer representing level.
    int getLevel() const;

    // Desc: Returns current HP of the Codemon.
    // Pre: None.
    // Post: Returns a double for current HP.
    double getCurrentHP() const;

    // Desc: Returns a numerical index based on Codemon type (for chart matching, etc.).
    // Pre: Codemon must have a valid type.
    // Post: Returns an integer representing the type index.
    int getTypeIndex() const;

    // Desc: Returns number of skills currently learned.
    // Pre: None.
    // Post: Returns an integer.
    int getSkillCount() const;

    // Desc: Returns the Codemon's name.
    // Pre: None.
    // Post: Returns a string.
    string getName() const;

    // Desc: Returns the Codemon's type.
    // Pre: None.
    // Post: Returns a string.
    string getType() const;

    // Desc: Reduces Codemon's current HP by a damage amount.
    // Pre: dmg must be a positive number.
    // Post: Codemon's HP is reduced accordingly.
    void takeDamage(double dmg);

    // Desc: Increases Codemon's HP up to maxHP.
    // Pre: healHP must be a positive number.
    // Post: HP is increased without exceeding maxHP.
    void heal(double healHP);

    // Desc: Checks if Codemon is fainted (HP ≤ 0).
    // Pre: None.
    // Post: Returns true if fainted, false otherwise.
    bool isFainted() const;

    // Desc: Adds a new skill to Codemon's skill list (up to 5).
    // Pre: s must be a valid Skill object.
    // Post: Adds skill and returns true if successful.
    bool addSkill(const Skill& s);

    // Desc: Gets a specific skill by index.
    // Pre: idx must be within 0 and skillCount - 1.
    // Post: Returns a reference to the Skill.
    const Skill& getSkill(int idx) const;

    // Desc: Prints the Codemon's stats and learned skills.
    // Pre: None.
    // Post: Outputs Codemon info to console.
    void print() const;
    
    // Desc: Apply a one-time flat damage boost to the next attack
    // Pre: amount ≥ 0
    // Post: next getDamage() will add this boost, then reset to 0
    void increaseDamage(int amount);

    // Desc: Apply a one-time shield that absorbs incoming damage
    // Pre: amount ≥ 0
    // Post: next takeDamage will subtract up to this amount, then reset to 0
    void setShield(int amount);

    // Desc: Equality operator to compare two Codemons by name.
    // Pre: lhs and rhs must be valid Codemon objects.
    // Post: Returns true if names match, false otherwise.
    friend bool operator==(const Codemon& lhs, const Codemon& rhs);

};

#endif