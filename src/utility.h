#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int countLinesInFile(const string& filename);

template<typename T>
void loadFromfile(const string& filename, T itemArray[], int maxSize) {
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
        if (!fin || name.empty()) {
            break; // Stop if reached the end of the file or an empty line
        }
        getline(fin, type, ',');
        getline(fin, amountStr, ',');
        getline(fin, description); // Reads the remainder of the line (until newline)

        // Convert amount string to integer
        int amount = stoi(amountStr);

        // Create and store the Item in the array
        itemArray[count] = T(name, type, amount, description);
        count++;
    }

    fin.close(); // Close the file 
    return;
}

#endif
