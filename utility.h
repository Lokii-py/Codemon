#ifndef UTILITY_H
#define UTILITY_H

#include "contestant.h"

class Arena {
private:
	char terrainMap[5][5]; // 2D array for terrain

public:
	void generateTerrain(); // generates terrain
	bool hasSameTypeNeighbor(int x, int y, char type) const; // checks if tile has same type neighbor
	//char getTile(int x, int y) const;
	void printTerrainForDebug() const;
	//bool isTileValid(int x, int y) const;


	//void placeCodemon(Contestant& contestant); // places codemon in the arena
	//void executeTurn(Contestant& active, Contestant& opponent); // executes turn for active contestant
	//printVisibleMap(const Contestant& contestant); // prints visible map for the contestant
};


#endif
