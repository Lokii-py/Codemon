#ifndef ARENA_H
#define ARENA_H

#include <iostream>

class Arena {
private:
    static constexpr int SIZE = 5;
    char terrainMap[SIZE][SIZE]; // 2D array for terrain
    bool occupied[SIZE][SIZE]{};
    char visibleMap[SIZE][SIZE];
    int curRow;
    int curCol;
    
public:

    Arena();

    //Desc: This function will generate the terrain map for he arena
    //pre: None
    //post: Generates a 5 * 5 grid of terrain types
    void generateTerrain();

    //Desc: This function will return True if a Codemon is already there
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

    
    void setTerrainTile(const int n_row, const int n_col, const char c);
    
    
    void updateVisibility(int x, int y);
    
    void printVisibleMap() const;

};

#endif