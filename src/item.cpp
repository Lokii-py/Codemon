#include "item.h"
#include <iostream>
using namespace std;

Item::Item() {
    name = "Unnamed";
    description = "None";
    effectType = "None";
    effectAmount = 0;
}

// Parameterized constructor
Item::Item(const std::string& n, std::string& type, int dur, const std::string& des){
    name = n;
    effectType = type;
    effectAmount = dur;
    description = des;
}

string Item::getEffectType() const{
    return effectType;
}

int Item::getEffectAmount() const {
    return effectAmount;
}

void Item::print() const {
    std::cout << "  - " << name << " - " << description << " (Effect Amount: " << effectAmount << ")\n";
}
