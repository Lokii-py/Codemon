#ifndef SKILL_H
#define SKILL_H
 
#include <iostream>
#include <string>

class Codemon;

class Skill {
private:
    std::string name;
    int baseDamage;

public:
    // Desc: This default constructor sets the inital values for the skill
    // Pre: None
    // Post: sets name to "Unnamed" and base damage to 0.
    Skill();
    // Desc: This is a constructor that allows for the inputs of the skill to be passed in as value.
    // Pre: need string arguement and int arguement
    // Post: Takes argument for the name and base damage and assigns them accordingly.
    Skill(const std::string& name, int baseDamage);

    // Desc: This functions returns the base damage of the skill
    // Pre: none
    // Post: returns int base damage of skill
    int getBaseDamage() const;
    // Desc: This functions returns the name of the skill
    // Pre: none
    // Post: returns string name of skill
    std::string getName() const;

    // Desc: This functions increases the damage of the skill
    // Pre: percent integer
    // Post: updates new basedamage of skill with percent increase
    void increaseDamage(int percent);

    // Desc: This functions prints out the skill nicely
    // Pre: None
    // Post: formats and print line for each skill
    void print() const;

    //Desc: This function calculates the effective damage based on the type chart
    //Pre: attacker and defender are Codemon objects
    //Post: returns the effective damage as a double
    double getEffectiveDamage(const Codemon& attacker, const Codemon& defender);
};

#endif
