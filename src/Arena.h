#ifndef ARENA_H
#define ARENA_H

#include <iostream>

class Arena {
private:
    static const int SIZE = 12;
	char terrainMap[SIZE][SIZE];
	bool occupied[SIZE][SIZE];
	char visibleMap[SIZE][SIZE];
	int curRow, curCol;
	int eneRow, eneCol;
	
	//Desc:Generates the terrain map using valid terrain symbols
	//Pre:None
	//Post:Each tile is initialized with a type, avoiding same-type neighbors
	void generateTerrain();
    
public:
    //Desc:Default constructor
    //Pre:None
    //Post:Initializes visibility and occupation arrays, then generates terrain
    //Stores the full terrain map (F, M, P, W, S)
    Arena();
    
    //Desc:Updates visibility around a Codémon (3x3 area) and overlays symbol at current position
    //Pre:x, y are Codémon coordinates; c is the Codémon symbol (e.g., '@')
    //Post:Updates the visibleMap with terrain and symbol in current position
    void updateVisibility(int x, int y, char c);
    
    //Desc:Prints the visible portion of the battlefield to console
    //Pre:None
    //Post:Shows revealed terrain and Codémon symbols, hides unexplored tiles with '#'
    void printVisibleMap() const;

    //Desc:Checks if a tile is already occupied
    //Pre:row and col are within bounds
    //Post:Returns true if the tile is currently occupied
    bool isOccupied(int row, int col) const;
    
    //Desc:Checks if a given terrain type exists adjacent to (x, y)
    //Pre:x, y are coordinates; type is terrain character to avoid
    //Post:Returns true if a neighbor has the same terrain type
    bool hasSameTypeNeighbor(int x, int y, char type) const;

    //Desc:Marks a tile as occupied
    //Pre:row and col are within bounds
    //Post:Sets occupied[row][col] to true
    void markOccupied(int row, int col);

    //Desc:Returns the terrain type at a given location
    //Pre:row and col are within bounds
    //Post:Returns terrainMap[row][col]
    char getTerrainTile(int row, int col) const;

    //Desc:Moves the Codémon to a new tile and updates terrain visibility
    //Pre:n_row and n_col specify the new coordinates; c is the Codémon symbol
    //Post:Clears old position, places Codémon in new tile, updates visibility
    void setTerrainTile(const int n_row, const int n_col, const char c);

    //Desc:Checks if enemy Codémon is in adjacent tile (3x3 zone)
    //Pre:row, col are current player Codémon coordinates
    //Post:Returns true if enemy is found in surrounding tiles
    bool isEnemyInRange(int row, int col) const;
};

#endif
