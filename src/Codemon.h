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

public:
    Codemon();

    Codemon(const string n, const string desc, const string type, const int level, const int hp);
    
    Codemon(std::string name, std::string type, std::string desc);

    int getMaxHP() const;
    int getLevel() const;
    double getCurrentHP() const;

    int getTypeIndex() const;

    int getSkillCount() const;
    
    string getName() const;
    
    string getType() const;

    void takeDamage(double dmg);

    void heal(double healHP);

    bool isFainted() const;

    bool addSkill(const Skill& s);

    const Skill& getSkill(int idx) const;

    void print() const;

    friend bool operator==(const Codemon& lhs, const Codemon& rhs);
};

#endif