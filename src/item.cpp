#include "item.h"

// Public functions 
// Default constructor
Item::Item() {
    name = "Unnamed";
    description = "None";
    duration = 0;
}

// Parameterized constructor
Item::Item(const std::string& n, const std::string& des, int dur) {
    name = n;
    description = des;
    duration = dur;
}

int Item::getDuration() const {
    return duration;
}

void Item::print() const {
    std::cout << "  - " << name << " - " << description << " (Duration: " << duration << ")\n";
}

