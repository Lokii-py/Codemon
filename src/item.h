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
	// Public functions
	// Default constructor
	Item();

	// Parameterized constructor
	Item(const std::string& n, std::string& type, int dur, const std::string& des);

	int getEffectAmount() const;

	void print() const;
};

#endif