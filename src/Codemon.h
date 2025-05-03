#ifndef CODEMON_H
#define CODEMON_H
#include "skill.h"
#include <iostream>
#include <string>

// Codemon class represents a battle creature with type, skills, HP, and level.
class Codemon {
private:
    std::string name;      //Name of the Codemon
    std::string type;      //Type (e.g., Fire, Water, etc.)
    int level;             //Current level of Codemon
    int hp;                //Current HP of Codemon
    Skill skills[6];       //Maximum of 6 skills per Codemon
    int skillCount;        //Tracks number of current skills

    //Evolves the Codemon based on chance and increases level and a skill's damage
    void evolve();

public:
    Codemon();
    
    Codemon(const std::string name, const std::string type, const int level, const int hp);

    // Accessors
    std::string getName() const;      //Returns the name of the Codemon
    std::string getType() const;      //Returns the type of the Codemon
    int getLevel() const;             //Returns the level of the Codemon
    int getHP() const;                //Returns the current HP
    int getSkillCount() const;        //Returns the number of skills
    Skill getSkill(int index) const;  //Returns skill at specified index

    //Adds a new skill to Codemon if not already present
    void addSkill(const Skill& skill);

    //Prints Codemon info and its skills
    void print();

    //Returns the index of the Codemon's type for use in type effectiveness
    int getTypeIndex() const;

    //Returns true if Codemon has fainted (HP <= 0)
    bool isFainted() const;

    //Overloads << to print detailed Codemon info
    friend std::ostream& operator<<(std::ostream& os, const Codemon& c);

    //Gives Arena class access to private members
    friend class Arena;
};

#endif
