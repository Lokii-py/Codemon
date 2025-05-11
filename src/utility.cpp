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

void loadCodemonsFromFile(const string& filename, Codemon codemonPool[], int maxSize) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error: cannot open file " << filename << endl;
        exit(1);
    }

    int count = 0;
    while (count < maxSize) {
        std::string name, type, desc;
        getline(fin, name, ',');
        if (!fin || name.empty()) break;
        getline(fin, type, ',');
        getline(fin, desc);  // till newline

        codemonPool[count] = Codemon(name, type, desc);
        count++;
    }

    fin.close();
}