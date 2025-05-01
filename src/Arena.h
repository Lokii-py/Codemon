#ifndef ARENA_H
#define ARENA_H

class Arena {
private: 
    static const int SIZE = 5;
	char terrainMap[SIZE][SIZE]; // 2D array for terrain
    bool occupied[SIZE][SIZE]{};

public:

    Arena();

	//Desc: This function will generate the terrain map for he arena
	//pre: None
	//post: Generates a 5 * 5 grid of terrain types
	void generateTerrain();

    //Desc: This function will generate True if codemon is already there
    //Pre: None
    //Post: Returns Boolean value
    bool isOccupied(int row, int col) const;

    //Desc: This function will reserve a tile
    //Pre: row and col are integers
    //Post: None
    void markOccupied(int row, int col);

    //Desc: This function will return back the terrain tile
    //Pre: Row and col are integers
    //Post: Return 'F' = Forest, 'M' = Mountain, 'P' = Plain, 'W' = Water, 'S' = Swamp
    char getTerrainTile(int row, int col) const;

	//Desc: checks if tile has same type neighbor
    //Pre: x, t are integer and type is char
    //Post: Check for neighbors (top, bottom, left right) to ensure they are not same type
	bool hasSameTypeNeighbor(int x, int y, char type) const;

    //for debugging
	void printTerrainForDebug() const;
};

#endif