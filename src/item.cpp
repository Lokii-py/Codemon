#include "item.h"

// Public functions 
// Default constructor
Item::Item() {
    name = "Unnamed";
    description = "None";
    effectType = "None";
    duration = 0;
}

// Parameterized constructor
Item::Item(const std::string& n, const std::string& des, std::string& type, int dur){
    name = n;
    description = des;
    effectType = type;
    duration = dur;
}

int Item::getDuration() const {
    return duration;
}

void Item::print() const {
    std::cout << "  - " << name << " - " << description << " (Duration: " << duration << ")\n";
}

void loadItemsFromFile(const string& filename, Item itemArray[], int maxSize) {
    ifstream fin(filename); // Open the file for reading 
    if (!fin) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1); // Exit the program if the file can't be opened
    }

    int count = 0;

    // Read up to maxSize items from the file
    while (count < maxSize) {
        string name, type, amountStr, description;

        // Read each field using comma as the delimiter
        getline(fin, name, ',');
        getline(fin, type, ',');
        getline(fin, amountStr, ',');
        getline(fin, description); // Reads the remainder of the line (until newline)

        // Debug output 
        // cout << name << endl; 
        // cout << type << endl; 
        // cout << amountStr << endl; 
        // cout << description << endl; 

        // Convert amount string to integer
        int amount = stoi(amountStr);

        // Create and store the Item in the array
        itemArray[count] = Item(name, description, type, amount);
        count++;
    }

    fin.close(); // Close the file 
}


