#include "Arena.h"
#include "Codemon.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

Arena::Arena() {
    generateTerrain();
	for (int r = 0; r < SIZE; ++r) {
		for (int c = 0; c < SIZE; ++c) {
			occupied[r][c] = false;
			visibleMap[r][c] = '#';
			itemGrid[r][c] = nullptr;
		}
	}
	curRow = -1; // not placed yet
	curCol = -1;
	eneRow = -1;
	eneCol = -1;
}

void Arena::generateTerrain() {
	// Fill terrainMap with valid terrain
	char terrainTypes[] = { 'F', 'M', 'P', 'W', 'S' }; // 'F' = Forest, 'M' = Mountain, 'P' = Plain, 'W' = Water, 'S' = Swamp
	// Initialize terrain grid
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			// Randomly pick a terrain type for this cell
			char newType;
			do {
				newType = terrainTypes[rand() % 5]; // Random terrain type
			} while (hasSameTypeNeighbor(i, j, newType)); // Ensure no neighbor has the same type

			terrainMap[i][j] = newType;
		}
	}
}

bool Arena::isOccupied(int row, int col) const {
	return occupied[row][col];
}

void Arena::setOccupied(int row, int col, bool val) {
	occupied[row][col] = val;
}

void Arena::setCurPos(int row,int col){ 
    curRow = row;
    curCol = col; 
}

char Arena::getTerrainTile(int row, int col) const {
	char type;
	type = terrainMap[row][col];
	return type;
}

bool Arena::hasSameTypeNeighbor(int x, int y, char type) const {
	// Check for neighbors (top, bottom, left, right) to ensure they are not the same type
	// Top
	if (x > 0 && terrainMap[x - 1][y] == type) {
		return true;
	}

	// Left
	if (y > 0 && terrainMap[x][y - 1] == type) {
		return true;
	}
	return false;
}

void Arena::updateVisibility(int r, int c) {
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            int nr = r + dr, nc = c + dc;
            if (nr>=0 && nr<SIZE && nc>=0 && nc<SIZE) {
                visibleMap[nr][nc] = terrainMap[nr][nc];
                // If snuggldon here, record last known
                if (nr==eneRow && nc==eneCol) {
                    lastKnownRow = eneRow;
                    lastKnownCol = eneCol;
                }
            }
        }
    }
}

void Arena::setTerrainTile(const int n_row, const int n_col, const char c) {
    // terrainMap[n_row][n_col] = c;
    visibleMap[n_row][n_col] = c;
	return;
}

int Arena::getCurRow() const {
	return curRow;
}

int Arena::getCurCol() const {
	return curCol;
}

void Arena::printVisibleMap(){
    
     for (int r = 0; r < SIZE; ++r) {
        for (int c = 0; c < SIZE; ++c) {
            visibleMap[r][c] = '#';
        }
    }
    
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            int nr = curRow + dr, nc = curCol + dc;
            if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE) {
                visibleMap[nr][nc] = terrainMap[nr][nc];
                // track last‐known if boss is here
                if (nr == eneRow && nc == eneCol) {
                    lastKnownRow = eneRow;
                    lastKnownCol = eneCol;
                }
            }
        }
    }
    
    for (int i = curRow - 1; i <= curRow + 1; ++i) {
        for (int j = curCol - 1; j <= curCol + 1; ++j) {
            if (i < 0 || j < 0 || i >= SIZE || j >= SIZE) {
                cout << "# ";
            } else {
                char ch = visibleMap[i][j];
                // overlay order
                if (i == curRow && j == curCol){
                    ch = '@';
                }else if (i == eneRow && j == eneCol){
                    ch = 'E';
                }else if (i == lastKnownRow && j == lastKnownCol){
                    ch = '?';
                }else if (itemGrid[i][j]){
                    ch = 'I';
                }else if (occupied[i][j]){
                    ch = 'A';
                }
                cout << ch << ' ';
            }
        }cout << endl;
    
    }cout <<"-----------------" << endl;
}

void Arena::placeItemsOnGrid(Item items[],int poolCount,int numToPlace) {
    int placed = 0;
    while (placed < numToPlace) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;
        if (!itemGrid[r][c] && !occupied[r][c]) {
            itemGrid[r][c] = new Item(items[rand() % poolCount]);
            ++placed;
        }
    }
}

Item Arena::dequeueItemAt(int row,int col) {
    Item ret = *itemGrid[row][col];
    delete itemGrid[row][col];
    itemGrid[row][col] = nullptr;
    return ret;
}

void Arena::redistributeItems() {
    // collect all items into buffer
    Item buffer[SIZE*SIZE];
    int count = 0;
    for (int r = 0; r < SIZE; ++r) {
        for (int c = 0; c < SIZE; ++c) {
            if (itemGrid[r][c]) {
                buffer[count++] = *itemGrid[r][c];
                delete itemGrid[r][c];
                itemGrid[r][c] = nullptr;
            }
        }
    }
    // re-scatter
    for (int i = 0; i < count; ++i) {
        int r, c;
        do {
            r = rand() % SIZE;
            c = rand() % SIZE;
        } while (itemGrid[r][c] || occupied[r][c]);
        itemGrid[r][c] = new Item(buffer[i]);
    }
}

bool Arena::isSnugInRange(int row, int col) const {
	for (int i = row - 1; i <= row + 1; ++i) {
		for (int j = col - 1; j <= col + 1; ++j) {
			if (i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
				if (i == eneRow && j == eneCol) {
					return true;
				}
			}
		}
	}
	return false;
}

void Arena::setEnePos(int row, int col){
    eneRow = row;
    eneCol = col;
    // lastKnownRow = row;
    // lastKnownCol = col;
}

bool Arena::hasItemAt(int r, int c) const {
    return itemGrid[r][c] != nullptr;
}

// In Arena.cpp:
// void Arena::printFullVisibleMap(int x, int y) {
void Arena::printFullVisibleMap(int x, int y) {
    for (int r = 0; r < SIZE; ++r) {
        for (int c = 0; c < SIZE; ++c) {
            visibleMap[r][c] = '#';
            if (isOccupied(r, c)) {
                visibleMap[r][c] = 'A';
            }
        }
    }
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
                visibleMap[nx][ny] = terrainMap[nx][ny];
            }
        }
    }
    visibleMap[x][y] = '@';
    if (lastKnownRow >= 0 && lastKnownCol >= 0) {
        visibleMap[lastKnownRow][lastKnownCol] = '?';
    }
    if (eneRow >= 0 && eneCol >= 0) {
        visibleMap[eneRow][eneCol] = 'E';
    }

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << visibleMap[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl;
    return;
}



void Arena::resetVisibility() {
    for (int r = 0; r < SIZE; ++r){
        for (int c = 0; c < SIZE; ++c){
            visibleMap[r][c] = '#';
        }
    }
}

int Arena::getEneRow() const{
    return eneRow;
}

int Arena::getEneCol() const{
    return eneCol;
}

int Arena::getLastKnownRow() const{
    return lastKnownRow;
}
    
int Arena::getlastKnownCol() const{
    return lastKnownCol;
}

/*
void Arena::printTerrainForDebug() const {
    // Print the terrain map for debugging
    cout << "Terrain Map:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << terrainMap[i][j] << " ";
        }
        cout << "\n";
    }
}
*/