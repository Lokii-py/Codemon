#include "utility.h"

void Arena::generateTerrain() {
    // Fill terrainMap with valid terrain
    char terrainTypes[] = { 'F', 'M', 'P', 'W', 'S' }; // 'F' = Forest, 'M' = Mountain, 'P' = Plain, 'W' = Water, 'S' = Swamp
    // Initialize terrain grid
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Randomly pick a terrain type for this cell
            char newType;
            do {
                newType = terrainTypes[rand() % 5]; // Random terrain type
            } while (hasSameTypeNeighbor(i, j, newType)); // Ensure no neighbor has the same type

            terrainMap[i][j] = newType;
        }
    }
}

bool Arena::isOccupied(int row, int col) const{
    return occupied[row][col];
}

void Arena::markOccupied(int row, int col){
    occupied[row][col] = true;
}

char Arena::getTerrainTile(int row, int col) const{
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
    // Bottom
    if (x < 4 && terrainMap[x + 1][y] == type) {
        return true;
    }
    // Left
    if (y > 0 && terrainMap[x][y - 1] == type) {
        return true;
    }
    // Right
    if (y < 4 && terrainMap[x][y + 1] == type) {
        return true;
    }

    return false;
}

void Arena::printTerrainForDebug() const {
	// Print the terrain map for debugging
	std::cout << "Terrain Map:\n";
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
		    cout << terrainMap[i][j] << " ";
		}
		std::cout << "\n";
	}
}




const int POOL_SIZE = 12;

const std::string CODEMON_NAMES[POOL_SIZE] = {
    "Flareth", // Fire
    "Aquagon", // Water
    "Leafowl", // Grass 
    "Voltiguana", // Electric 
    "Infermouse", // Fire
    "Bubbletail", // Water
    "Shrubling", // Grass 
    "Zapkit", // Electric
    "Cindermole", // Fire
    "Torrentoise", // Water 
    "Thornabbit", // Grass
    "Shockpup" // Electric
};

const int CODEMON_HP[POOL_SIZE] = {
    40, 42, 38, 35,
    34, 45, 37, 32,
    39, 48, 40, 36
};

const int CODEMON_LEVELS[POOL_SIZE] = {
    5, 4, 2, 6,
    7, 3, 1, 0,
    8, 9, 10, 11
};

const std::string CODEMON_SKILLS[POOL_SIZE] = {
    "Flame Burst", "Aqua Jet", "Razor Leaf", "Thunder Jolt",
    "Fire Claw", "Bubble Beam", "Vine Whip", "Static Bolt",
    "Ember Rage", "Water Pulse", "Spore Shot", "Spark Bite"
};

const int CODEMON_SKILL_DAMAGE[POOL_SIZE] = {
    12, 10, 11, 13,
    15, 14, 19, 17,
    16, 18, 20, 21
};
