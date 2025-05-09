#ifndef CONTESTANT_H
#define CONTESTANT_H
#include "Codemon.h"
#include <string>

class Contestant {
private:
    std::string name;
    int codemonCount;
    Codemon pocket[3];
    Codemon currentCodemon;
    bool alive;

public:
    // Constructors
    // Desc: This is default constructor that asks only the contestant's name
    // Pre: None
    // Post: Assigns contestant�s name from input and sets the number of Cod�mons and items owned to 0. 
    Contestant(); // Default constructor

    // Desc: This is a constructor that allows for the input to be passed in as value.
    // Pre: need string arguement
    // Post: Takes argument for the name and sets the number of Cod�mons and items owned to 0. 
    Contestant(std::string n); // paremeterized constructor

    // Desc: This is a copy constructor that asks for a new name 
    // Pre: need a contestant parameter
    // Post: copies data then assigns new name form input
    Contestant(const Contestant& clone);

    //Functions
    // Desc: This functions returns the name of the player
    // Pre: none
    // Post: returns string of contestant name
    std::string getName() const;

    // Desc: This function returns the number of Codémons the contestant has
    // Pre: None
    // Post: Returns the value of codemonCount
    int getCodemonCount() const;

    // Desc: This function updates a contestant's pocket by adding a new Codémon info. 
    // Pre: need a codemon parameter
    // Post: If pocket is not full and codemon does not already exist, it adds 
    void updateCodemon(const Codemon&);

    // Desc: This function allows for the player to select their codemons
    // Pre: none
    // Post: asks player to creat three codemons and assigns them to their pocket
    void selectCodemons();

    // Desc: This function generates three random codemons
    // Pre: none
    // Post: generates and assignns random codemons
    void generateCodemons();

    // Desc: This function kills the object and ends the game
    // Pre: none
    // Post: sets alive to false
    void death();

    // Desc: This function returns the status of the player
    // Pre: none
    // Post: returns bool of isAlive
    bool isAlive();

    // Desc: This function overloads the << operator to print
    // Pre: need os and codemon parameter
    // Post: prints a codemon stats
    friend std::ostream& operator<<(std::ostream& os, const Codemon& c);

    // Desc: This function returns the current codemon being used by the player
    // Pre: none
    // Post: returns Codemon type of active codemon
    Codemon& getActiveCodemon();


    // Desc: This friend function runs the battle
    // Pre: needs contestants and arena
    // Post: returns nothing but edits contestants
   // friend void battle(Contestant& player, Contestant& comp, Arena& arena);

};

#endif

