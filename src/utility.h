#ifndef UTILITY_H
#define UTILITY_H

#include "contestant.h"
#include <iostream>
#include <string>

class Arena {
private:
	char terrainMap[5][5]; // 2D array for terrain

public:
	//Desc: This function will generate the terrain map for he arena
	//pre: None
	//post: generates a 5 * 5 grid of terrain types
	void generateTerrain();

	// checks if tile has same type neighbor
	bool hasSameTypeNeighbor(int x, int y, char type) const;

	//bool isTileValid(int x, int y) const;
};


#endif
