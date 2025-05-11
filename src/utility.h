#ifndef UTILITY_H
#define UTILITY_H

#include "Codemon.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Desc: Counts the number of non-empty lines in a file
// Pre:  filename refers to a valid text file
// Post: Returns the number of lines in the file
int countLinesInFile(const string& filename);

// Desc: Loads Codémons from a file into an array
// Pre:  filename is the file path; codemonPool is a pre-allocated array; maxSize is the array size
// Post: Populates the array with Codémons read from the file (up to maxSize)
void loadCodemonsFromFile(const string& filename, Codemon codemonPool[], int maxSize);

// Desc: Template function to load data from a file into an array of objects
// Pre:  T must have a constructor that accepts (string name, string type, int amount, string description)
// Post: Reads objects from file into itemArray (up to maxSize)
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

        // Create and store the object in the array using its constructor
        itemArray[count] = T(name, type, amount, description);
        count++;
    }

    fin.close(); // Close the file 
    return;
}

#endif