#ifndef CONTESTANT_H
#define CONTESTANT_H
#include "Arena.h"
#include "Codemon.h"
#include "item.h"
#include <string>
using namespace std;

class Contestant{
private: 
    Codemon* team = nullptr;
    int teamsize = 0;
    int activeCodemon = 0;

    int row = -1;
    int col = -1;

    string playerName;
    bool isHuman = true;

    //shared dynamic Item Queueu
    static Item* itemQueue;
    static int qCapacity;
    static int qSize;
    static int qFront;

    void resizeQueue(int newCapacity);
    void placeRandomCodemon(Arena& A);

public: 
    Contestant();
    
    // Desc: This is a constructor that allows for the input to be passed in as value.
    // Pre: need string arguement
    // Post: Takes argument for the name and sets the number of Cod�mons and items owned to 0. 
    Contestant(string name, bool human); // paremeterized constructor

    ~Contestant();

    Contestant(const Contestant& other);

    Contestant& operator = (const Contestant& rhs);

    static void initSharedQueue(int firstCap);

    void setTeamSize(int n);

    bool addCodemon(const Codemon& c, int idx);

    Codemon& getActive();

    void spawn(Arena& arena, int r, int c, char symbol);

    void takeTurn(Arena& arena, char symbol);

    void enqueueItem(const Item& item);
    
    bool useNextItem();
    
    void selectCodemons(Codemon pool[], int poolSize, bool random); 

    void printVisibleMap(const Arena& A) const;

    // Desc: This function returns the status of the player
    // Pre: none
    // Post: returns bool of isAlive
    bool isAlive() const;

// class Contestant {
// private:
//     std::string name;
//     int codemonCount;
//     Codemon pocket[3];
//     Codemon currentCodemon;
//     bool alive;

// public:
//     // Constructors
//     // Desc: This is default constructor that asks only the contestant's name
//     // Pre: None
//     // Post: Assigns contestant�s name from input and sets the number of Cod�mons and items owned to 0. 
//     Contestant(); // Default constructor

//     // Desc: This is a copy constructor that asks for a new name 
//     // Pre: need a contestant parameter
//     // Post: copies data then assigns new name form input
//     Contestant(const Contestant& clone);

//     //Functions
//     // Desc: This functions returns the name of the player
//     // Pre: none
//     // Post: returns string of contestant name
//     std::string getName() const;

//     // Desc: This function returns the number of Cod�mons the contestant has
//     // Pre: None
//     // Post: Returns the value of codemonCount
//     int getCodemonCount() const;

//     // Desc: This function updates a contestant's pocket by adding a new Cod�mon info. 
//     // Pre: need a codemon parameter
//     // Post: If pocket is not full and codemon does not already exist, it adds 
//     void updateCodemon(const Codemon&);

//     // Desc: This function allows for the player to select their codemons
//     // Pre: none
//     // Post: asks player to creat three codemons and assigns them to their pocket
//     void selectCodemons();

//     // Desc: This function generates three random codemons
//     // Pre: none
//     // Post: generates and assignns random codemons
//     void generateCodemons();

//     // Desc: This function overloads the << operator to print
//     // Pre: need os and codemon parameter
//     // Post: prints a codemon stats
//     friend std::ostream& operator<<(std::ostream& os, const Codemon& c);

//     // Desc: This friend function runs the battle
//     // Pre: needs contestants and arena
//     // Post: returns nothing but edits contestants
//     friend void battle(Contestant& player, Contestant& comp, Arena& arena);
};

#endif

