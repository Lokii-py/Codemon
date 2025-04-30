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

	//Desc: This function will deploy the codemon to the unoccupied and valid grid in arena
	//Pre: takes a codemon represented as @
	//Post: randomly deploys codemon to the unoccupied and valid grid in arena randomly
	/* Example output: 
		# # # # #
		# M P M #
		# P @ F #
		# S S E # 
		# # # # # 
	========= */
	void placeCodemon(char @, int x, int y);

	void printTerrainForDebug() const;


	//char getTile(int x, int y) const;
	void printTerrainForDebug() const;


	//bool isTileValid(int x, int y) const;

	//void placeCodemon(Contestant& contestant); // places codemon in the arena
	//void executeTurn(Contestant& active, Contestant& opponent); // executes turn for active contestant
	//printVisibleMap(const Contestant& contestant); // prints visible map for the contestant
};


#endif
