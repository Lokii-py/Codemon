#ifndef CONTESTANT_H
#define CONTESTANT_H

#include "codemon.h"
#include "item.h"
#include <string>

class Contestant {
private:
    std::string name;
    int codemonCount;
<<<<<<< HEAD:contestant.h
    Codemon pocket[3];
   
=======
    //Codemon pocket[3];
>>>>>>> origin/Lokii:src/contestant.h
    
public:
    // Constructors
    // Desc: This is default constructor that asks only the contestant's name
    // Pre: None
<<<<<<< HEAD:contestant.h
    // Post: Assigns contestant’s name from input and sets the number of Codémons and items owned to 0. 
=======
    // Post: Assigns contestant�s name from input and sets the number of Cod�mons and items owned to 0. 
>>>>>>> origin/Lokii:src/contestant.h
    Contestant(); // Default constructor
    
    // Desc: This is a constructor that allows for the input to be passed in as value.
    // Pre: need string arguement
<<<<<<< HEAD:contestant.h
    // Post: Takes argument for the name and sets the number of Codémons and items owned to 0. 
=======
    // Post: Takes argument for the name and sets the number of Cod�mons and items owned to 0. 
>>>>>>> origin/Lokii:src/contestant.h
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
    
<<<<<<< HEAD:contestant.h
    // Desc: This function updates a contestant's pocket by adding a new Codémon info. 
=======
    // Desc: This function updates a contestant's pocket by adding a new Cod�mon info. 
>>>>>>> origin/Lokii:src/contestant.h
    // Pre: need a codemon parameter
    // Post: If pocket is not full and codemon does not already exist, it adds 
    void updateCodemon(const Codemon&);
    
    
<<<<<<< HEAD:contestant.h
    // Desc: This function gets the contestant ready for battle by adding Codémons and items.
    // Pre: none
    // Post: updates the Codémons in the pocket and the items in the backpack. Prompt the user for update one by one until the user doesn’t want to anymore or when full
=======
    // Desc: This function gets the contestant ready for battle by adding Cod�mons and items.
    // Pre: none
    // Post: updates the Cod�mons in the pocket and the items in the backpack. Prompt the user for update one by one until the user doesn�t want to anymore or when full
>>>>>>> origin/Lokii:src/contestant.h
    //void prepare();
   

    ////////////  overload << to print
    // Desc: This function prints the contestant info nicely.
    // Pre: none
    // Post: sorts pocket and backpack then prints each 
    void print();



    ///////////////////////////////////


    void selectCodemons();

    void generateCodemons();



};

#endif

