#ifndef SKILL_H
#define SKILL_H
#include <iostream>
using namespace std;

class Codemon;

class Skill{
private: 
    string name;
    string type;
    string description;
    int baseDamage;
public:
    Skill();

    // Parameterized constructor
    Skill(const std::string& name, const std::string& t, int baseDamage, const std::string& desc);

    int getBaseDamage() const;

    string getName() const;

    void increaseDamage(int percent) ;

    void print() const;
    
    //New function to calculate effective damage based on type chart
    double getEffectiveDamage(const Codemon& attacker, const Codemon& defender);
};

#endif