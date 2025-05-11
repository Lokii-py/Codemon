#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

class Item {
private:
	string name;
	string description;
	string effectType; // "Heal", "Boost", or "Shield"
	int effectAmount;
public:
    // Desc: Default constructor that creates an uninitialized item.
    // Pre: None.
    // Post: Item fields are set to default/empty values.
    Item();

    // Desc: Parameterized constructor to initialize all fields of an Item.
    // Pre: n must be a valid name, type must be "Heal", "Boost", or "Shield", dur is a positive int, des is a description string.
    // Post: Initializes the item with given properties.
    Item(const std::string& n, std::string& type, int dur, const std::string& des);

    // Desc: Returns the effect amount of the item.
    // Pre: None.
    // Post: Returns an integer representing the magnitude of the effect.
    int getEffectAmount() const;

    // Desc: Prints the item's name, type, description, and effect amount.
    // Pre: None.
    // Post: Outputs the item’s details to the console.
    void print() const;
};

#endif