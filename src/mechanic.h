#ifndef MECHANIC_H
#define MECHANIC_H
#include "Arena.h"
#include "contestant.h"


/*
Contestant can either:
    - Move in cardinal and diagonal directiosn
    - scout: reveal adjacent cells
    - attack: if any enemy is within range

A contestant can only see terrain and enemies in the 3x3 area around their Codémon
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
void movement(const char move, int& row, int& col, Arena& arena);


// Desc: This friend function runs the battle
// Pre: needs contestants and arena
// Post: returns nothing but edits contestants
void battle(Contestant& player, Contestant& comp, Arena& arena, int row, int col);

#endif