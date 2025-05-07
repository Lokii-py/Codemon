#ifndef CODEMON_H
#define CODEMON_H

#include "skill.h"
#include <iostream>
#include <string>

class Arena;
class Contestant;
class Skill;

class Codemon {
private:
    std::string name;
    std::string type;
    int level;
    int maxHP;
    int currentHP;
    Skill skills[6];
    int skillCount;

    // Desc: This function evolves a codemon's trait
    // Pre: None
    // Post: If chance >= 60, level increases by 1 and the base damage of a randomly select current skill increases by a random 
    // percentage between 0 % and 100 %. Then it displays a message.
    void evolve();

public:
    // Constructors
    // Desc: This is a default constructor that initializes all values of codemon
    // Pre: None
    // Post: Assigns codemon’s name "None", sets the number of Codémons and items owned to 0. 
    Codemon(); // Default constructor

    // Desc: This is a constructor that allows for the inputs of the codemon to be passed in as value.
    // Pre: need string arguements and int arguements
    // Post: Takes argument for the name, type, level, and hp and assigns them accordingly. 
    Codemon(const std::string name, const std::string type, const int level, const int hp); // paremeterized constructor

    // Functions
    // Desc: This functions returns the name of the codemon
    // Pre: none
    // Post: returns string of codemon name
    std::string getName() const;

    // Desc: This functions returns the level of the codemon
    // Pre: none
    // Post: returns int of codemon level
    int getLevel() const;

    // Desc: This function add skill to codemon if it doesn't already exist
    // Pre: takes a skill parameter
    // Post: checks if skills is already possessed then adds it to codemon skill array
    void addSkill(const Skill&);

    // Desc: This functions overloads the << operator
    // Pre: takes os and Codemon
    // Post: prints output nicely
    friend std::ostream& operator<<(std::ostream& os, const Codemon& c);


    // Desc: This functions returns the int of type index
    // Pre: none
    // Post: returns int of type index
    int getTypeIndex() const;


    // Desc: This functions returns the string of the Codemon type
    // Pre: none
    // Post:  returns the string of the Codemon type
    std::string getType() const { return type; }


    // Desc: This functions returns the int of current HP
    // Pre: none
    // Post: returns the int of current HP
    int getCurrentHP() const { return currentHP; }

    // Desc: This functions returns the int of max HP
    // Pre: none
    // Post: returns the int of max HP
    int getMaxHP() const { return maxHP; }

    // Desc: This functions overloads - operator and returns a copied Codemon
    // Pre: need int of damage
    // Post: returns copied codemon with lowered hp
    Codemon operator-(int damage) const {
        Codemon copy = *this;  // calling object
        copy.currentHP = copy.currentHP - damage;
        if (copy.currentHP < 0) {
            copy.currentHP = 0;
        }
        return copy;
    }

    // Desc: This functions overloads -= operator 
   // Pre: need int of damage
   // Post: returns  codemon with lowered hp
    Codemon& operator-=(int damage) {
        currentHP = currentHP - damage;
        if (currentHP < 0) {
            currentHP = 0;
        }
        return *this;
    }

    // Desc: This friend function runs the battle
    // Pre: needs contestants and arena
    // Post: returns nothing but edits contestants
    friend void battle(Contestant& player, Contestant& comp, Arena& arena, int row, int col);

    friend class Arena;
};
#endif
