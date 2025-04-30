#ifndef MECHANIC_H
#define MECHANIC_H

/*
Contestant can either: 
    - Move in cardinal and diagonal directiosn
    - scout: reveal adjacent cells
    - attack: if any enemy is within range

A contestant can only see terrain and enemies in the 3x3 area around their Codémon
*/

//Desc: This function will randomly deploy codemon to the unoccupied and valid grid in arena randomly
//Pre: takes a 2D array of codemon and a 2D array of terrain
//Post: randomly deploys codemon to the unoccupied and valid grid in arena randomly
void randomInit();

#endif 