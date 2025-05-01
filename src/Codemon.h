#ifndef CODEMON_H
#define CODEMON_H

#include "skill.h"
#include <iostream>
#include <string>

class Codemon {
private:
    std::string name;
    std::string type;
    int level;
    int hp;
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
<<<<<<< HEAD:Codemon.h
    // Post: Assigns codemon’s name "None", sets the number of Codémons and items owned to 0. 
=======
    // Post: Assigns codemon�s name "None", sets the number of Cod�mons and items owned to 0. 
>>>>>>> origin/Lokii:src/Codemon.h
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

    ////////////  overload << to print
    // Desc: This functions sorts the skill by base damage then prints it out nicely
    // Pre: None
    // Post: uses bubble sort to order skills by increasing base damage then prints it out
    void print();

    
};
#endif
