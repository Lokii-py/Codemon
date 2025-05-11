#ifndef ARENA_H
#define ARENA_H

#include "item.h"
#include <iostream>
class Contestant;
class Snuggladon;

class Arena {
public:
    static const int SIZE = 12;
private:
    char terrainMap[SIZE][SIZE];
    bool occupied[SIZE][SIZE];
    Item* itemGrid[SIZE][SIZE];
    char visibleMap[SIZE][SIZE];
    int curRow, curCol;
    int eneRow, eneCol;
    int lastKnownRow, lastKnownCol;

    // Desc: Generates the terrain map using valid terrain symbols
    // Pre: None
    // Post: Each tile is initialized with a terrain type, avoiding adjacent duplicates
    void generateTerrain();
    
    Contestant* rosterPtr = nullptr;
    int rosterSize = 0;
    Snuggladon*  bossPtr = nullptr;


public:
    // Desc: Default constructor
    // Pre: None
    // Post: Initializes terrainMap, occupied, visibleMap; then generates terrain
    Arena();

    // Desc: Gets the current row of the active player/Codémon
    // Pre: None
    // Post: Returns curRow
    int getCurRow() const;

    // Desc: Gets the current column of the active player/Codémon
    // Pre: None
    // Post: Returns curCol
    int getCurCol() const;

    // Desc: Updates visibility around a Codémon in a 3x3 radius
    // Pre: x and y are current coordinates; c is the Codémon symbol
    // Post: Updates visibleMap with surrounding terrain and current symbol
    void updateVisibility(int r, int c);

    // Desc: Prints the visible portion of the arena (fog-of-war applied)
    // Pre: None
    // Post: Displays known terrain and symbols; unexplored tiles are shown as '#'
    void printVisibleMap();

    // Desc: Checks if a tile is occupied
    // Pre: row and col are valid indices (0–11)
    // Post: Returns true if occupied[row][col] is true
    bool isOccupied(int row, int col) const;

    // Desc: Checks if any adjacent tile shares the same terrain type
    // Pre: x and y are valid indices; type is the terrain char to avoid repeating
    // Post: Returns true if adjacent tile matches the type
    bool hasSameTypeNeighbor(int x, int y, char type) const;

    // Desc: Marks a tile as occupied
    // Pre: row and col are valid indices
    // Post: Sets occupied[row][col] = true
    void setOccupied(int row, int col, bool val);

    // Desc: Returns the terrain type of a given tile
    // Pre: row and col are valid indices
    // Post: Returns terrainMap[row][col]
    char getTerrainTile(int row, int col) const;

    // Desc: Moves Codémon to new position and updates visibility
    // Pre: n_row and n_col are destination coordinates; c is Codémon symbol
    // Post: Codémon is placed in new location and visibility is updated
    void setTerrainTile(const int n_row, const int n_col, const char c);

    // Desc: Checks if an enemy is in adjacent 3x3 area
    // Pre: row and col are player Codémon coordinates
    // Post: Returns true if enemy is nearby
    bool isSnugInRange(int row, int col) const;

    // Desc: Sets enemy row position
    // Pre: r is a valid row index
    // Post: Sets eneRow
    void setEneRow(int r) { eneRow = r; }

    // Desc: Sets enemy column position
    // Pre: c is a valid column index
    // Post: Sets eneCol
    void setEneCol(int c) { eneCol = c; }
    
    void placeItemsOnGrid(Item items[], int poolCount, int numToPlace);
    Item dequeueItemAt(int row, int col);
    void redistributeItems();
    void setEnePos(int row, int col);
    void setCurPos(int row, int col);
    // Return true if there’s an item on that cell
    bool hasItemAt(int r, int c) const;
    
    // In Arena.h, under public:
    void printFullVisibleMap(int x, int y);
    
    void resetVisibility() ;
    
    int getEneRow() const;
    
    int getEneCol() const;
    
    int getLastKnownRow() const;
    
    int getlastKnownCol() const;
    
};

#endif