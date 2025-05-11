#ifndef SKILL_H
#define SKILL_H
#include <iostream>
using namespace std;

class Codemon;

class Skill {
private:
    string name;
    string type;
    string description;
    int baseDamage;
public:
    // Desc: Default constructor to initialize a Skill with default values.
    // Pre: None.
    // Post: Creates a Skill object with empty name/type and zero damage.
    Skill();

    // Desc: Parameterized constructor to initialize a Skill with specific values.
    // Pre: name and type must be valid strings, baseDamage must be non-negative, desc is a description string.
    // Post: Creates a Skill with the given properties.
    Skill(const std::string& name, const std::string& t, int baseDamage, const std::string& desc);

    // Desc: Returns the base damage value of the skill.
    // Pre: None.
    // Post: Returns an integer representing the skill's base damage.
    int getBaseDamage() const;

    // Desc: Returns the name of the skill.
    // Pre: None.
    // Post: Returns a string representing the skill's name.
    string getName() const;

    // Desc: Increases the skill's base damage by a given percentage.
    // Pre: percent must be a valid positive integer (e.g., 25 for +25%).
    // Post: baseDamage is increased accordingly.
    void increaseDamage(int percent);

    // Desc: Prints the skill's details (name, type, damage, description).
    // Pre: None.
    // Post: Outputs the skill information to the console.
    void print() const;

    // Desc: Returns the type of the skill.
    // Pre: None.
    // Post: Returns a string representing the skill's type.
    string getType() { return type; }

    // Desc: Computes type-based damage multiplier using attacker and defender types.
    // Pre: attacker and defender must be valid type strings.
    // Post: Returns a double representing the effectiveness multiplier.
    double getMultiplier(const std::string& attacker, const std::string& defender);

};

#endif