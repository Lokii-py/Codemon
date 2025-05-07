#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item {
private:
    std::string name;
    std::string description;
    int duration;

public:
    // Desc: This default constructor sets the inital values for the item
    // Pre: None
    // Post: sets name to "Unnamed", description to "None", and duration to 0.
    Item();
    // Desc: This is a constructor that allows for the inputs of the item to be passed in as value.
    // Pre: need string arguements and int arguement
    // Post: Takes argument for the name, description, and duration and assigns them accordingly. 
    Item(const std::string& name, const std::string& description, int duration);

    // Desc: This functions returns the duration of the item
    // Pre: none
    // Post: returns int of duration of item
    int getDuration() const;

    // Desc: This functions prints out the items nicely
    // Pre: None
    // Post: formats and print line for each item
    void print() const;
};

#endif
