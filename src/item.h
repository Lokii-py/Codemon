#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <fstream> 
using namespace std;

class Item {
private:
    std::string name;
    std::string description;
    string effectType; // "Heal", "Boost", or "Shield"
    int duration;

public:
    // Desc: This default constructor sets the inital values for the item
    // Pre: None
    // Post: sets name to "Unnamed", description to "None", and duration to 0.
    Item();

    // Desc: This is a constructor that allows for the inputs of the item to be passed in as value.
    // Pre: need string arguements and int arguement
    // Post: Takes argument for the name, description, and duration and assigns them accordingly. 
    Item(const std::string& n, std::string& type, int dur, const std::string& des);

    // Desc: This functions returns the duration of the item
    // Pre: none
    // Post: returns int of duration of item
    int getDuration() const;

    // Desc: This functions prints out the items nicely
    // Pre: None
    // Post: formats and print line for each item
    void print() const;
    
    // Desc: This function loads items from a file into an array of Item objects
    // Pre: filename is the name of the file to read from, itemArray is the array to store items, maxSize is the maximum number of items
    // Post: Reads items from the file and populates the itemArray with Item objects
    // friend void loadItemsFromFile(const string& filename, Item itemArray[], int maxSize);
    //friend class Codemon;
};

#endif
