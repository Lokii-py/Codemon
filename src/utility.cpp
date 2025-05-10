#include "utility.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int countLinesInFile(const string& filename) {
    ifstream fin(filename); // Open the file for reading 
    string line;
    int count = 0;

    // Read the file line by line 
    while (getline(fin, line)) {
        count++;
    }

    fin.close(); // Close the file 
    return count;
}
