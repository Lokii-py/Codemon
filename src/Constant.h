#ifndef CONSTANT_H
#define CONSTANT_H
#include <iostream>
#include <string>

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
#endif
