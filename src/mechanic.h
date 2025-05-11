#ifndef MECHANIC_H
#define MECHANIC_H
#include "Arena.h"
#include "contestant.h"
#include <string>
#include <fstream>
using namespace std;

class Snuggladon;
/*
Contestant can either:
    - Move in cardinal and diagonal directiosn
    - scout: reveal adjacent cells
    - attack: if any enemy is within range

A contestant can only see terrain and enemies in the 3x3 area around their Cod�mon
*/

/* W, A, S, D for cardinal directions, Q, E, Z, C for diagonals
-----------------------------
W - Up      | Q - Up left
A - Left    | E - Up Right
S - Down    | Z - Down left
D - Right   | C - Down Right
-----------------------------
- Implement Random Movement for Computer
- This will take the current position of codemon */

//Desc: This function move the codemon aroun the arena
//pre: needs a move direction, coordinates, and arena
//post: moves codemon to new spot based of input move
void movement(char move, char type, Arena& arena);

// Desc: This friend function runs the battle
// Pre: needs contestants and arena
// Post: returns nothing but edits contestants
void battle(Contestant& player, Snuggladon& snug, bool isHuman);

// Desc: Utility function to count the number of lines in a file.
// Pre: 'filename' must be a valid string path to a readable text file.
// Post: Returns an integer representing the number of lines in the file.
int countLinesInFile(const string& filename);



#endif