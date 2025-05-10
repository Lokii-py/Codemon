#include "contestant.h"
#include "item.h"
#include "Arena.h"
#include "Codemon.h"
#include "mechanic.h"
#include <iostream>
#include <string>
using namespace std;

void Contestant::resizeQueue(int newCapacity) {
    Item* newQueue = new Item[newCapacity];
    for (int i = 0; i < qSize; i++) {
        newQueue[i] = itemQueue[(qFront + i) % qCapacity];
    }
    delete[] itemQueue;
    itemQueue = newQueue;
    qCapacity = newCapacity;
    qFront = 0;
}


void Contestant::placeRandomCodemon(Arena& A) {
	do {
		row = rand() % 12;
		col = rand() % 12;
	} while( A.isOccupied(row, col));
	return;
}

Contestant::Contestant() {
	teamsize = 3;
	activeCodemon = 0;
	row = -1;
	col = -1;

	cout << "Please enter your name: ";
	getline(cin, playerName);

	isHuman = true;

	team = new Codemon[teamsize];
}

Contestant::Contestant(string name, bool human){
    playerName = name;
    isHuman = human;
}

Contestant::~Contestant() {
	delete[] team;
}

Contestant::Contestant(const Contestant& other) {
	cout << "Copying Contestant: " << other.playerName << endl;
	cout << "Enter name for cloned Contestant: ";
	getline(cin, playerName);

	teamsize = other.teamsize;
	activeCodemon = other.activeCodemon;
	row = other.row;
	col = other.col;
	isHuman = other.isHuman;

	team = new Codemon[teamsize];
	for (int i = 0; i < teamsize; ++i) {
		team[i] = other.team[i];
	}
}

Contestant& Contestant::operator = (const Contestant& rhs) {
	if (this == &rhs) {
		return *this;
	}

	delete[] team;

	this->playerName = rhs.playerName;
	this->teamsize = rhs.teamsize;
	this->activeCodemon = rhs.activeCodemon;
	this-> row = rhs.row;
	this->col = rhs.col;
	this->isHuman = rhs.isHuman;

	team = new Codemon[teamsize];
	for(int i = 0; i < teamsize; ++i) {
		team[i] = rhs.team[i];
	}
	return *this;
}

void Contestant::initSharedQueue(int firstCap) {
    delete[] itemQueue;
    itemQueue = new Item[firstCap];
    qCapacity = firstCap;
    qSize = 0;
    qFront = 0;
}


void Contestant::setTeamSize(int n) {
	delete[] team;
	teamsize = n;
	activeCodemon = 0;
	team = new Codemon[teamsize];
}

bool Contestant::addCodemon(const Codemon& c, int idx) {
	if (idx < 0 || idx >= teamsize) return false;
	team[idx] = c;
	return true;
}

Codemon& Contestant::getActive() {
	return team[activeCodemon];
}

void Contestant::spawn(Arena& arena, int r, int c, char symbol) {
	row = r;
	col = c;
	arena.setTerrainTile(row, col, symbol);
}

void Contestant::takeTurn(Arena& arena, char symbol) {
	if (isHuman) {
		arena.printVisibleMap();
		cout << "[" << playerName << "] move (W A S D Q E Z C): ";
		char mv;
		cin >> mv;
		movement(mv, symbol, arena);
	} else {
		const char dir[8] = { 'W','A','S','D','Q','E','Z','C' };
		char mv = dir[rand() % 8];
		movement(mv, symbol, arena);
	}
	row = arena.getCurRow();
	col = arena.getCurCol();
}

void Contestant::enqueueItem(const Item& item) {
	if (qSize == qCapacity) {
		resizeQueue(qCapacity*2);
	}
	int pos = (qFront + qSize) % qCapacity;
	itemQueue[pos] = item;
	qSize++;
}
bool Contestant::useNextItem() {
	if (qSize == 0) return false;
	const Item& item = itemQueue[qFront];
	cout << "Using item: ";
	item.print();
	// Apply effect to active codemon if needed
	qFront = (qFront + 1) % qCapacity;
	qSize--;
	if (qCapacity > 4 && qSize < qCapacity / 4) resizeQueue(qCapacity / 2);
	return true;
}

void Contestant::printVisibleMap(const Arena& A) const {
    cout << "=== " << playerName << "'s visible map ===\n";
    A.printVisibleMap();
}

bool Contestant::isAlive() const {
	return !(team[activeCodemon].isFainted());
}

// Static member initialization
Item* Contestant::itemQueue = nullptr;
int   Contestant::qCapacity = 0;
int   Contestant::qSize     = 0;
int   Contestant::qFront    = 0;


// std::string Contestant::getName() const {
//     return playerName;
// }

// int Contestant::getCodemonCount() const {
//     return codemonCount;
// }


// void Contestant::updateCodemon(const Codemon& codemon) {
//     if (codemonCount >= 10) {
//         std::cout << "Pocket is full.\n"; // can't add more than 10 codemons
//         return;
//     }

//     for (int i = 0; i < codemonCount; i++) { // can't add codemon with same name
//         if (pocket[i].getName() == codemon.getName()) {
//             std::cout << "Codemon with the same name already exists. Can't add Codemon.\n";
//             return;
//         }
//     }

//     pocket[codemonCount++] = codemon;  // assigns codemon at index then increases count

// }

// void Contestant::selectCodemons() {
//     for (int i = 0; i < 3; i++) {
//         std::string codemonName, type;
//         int level, hp;

//         std::cin.ignore();
//         std::cout << "Enter Codemon #" << i + 1 << " name: "; // taking in parameters
//         std::getline(std::cin, codemonName);
//         std::cout << "Enter type: ";
//         std::getline(std::cin, type);
//         std::cout << "Enter level: ";
//         std::cin >> level;
//         std::cout << "Enter HP: ";
//         std::cin >> hp;
//         std::cin.ignore();

//         Codemon codemon(codemonName, type, level, hp); // initializes codemon with values

//         // Add Skills to Codo?=mon
//         for (int i = 0; i < 6; i++) {
//             char skillChoice;
//             std::cout << "Add a skill to " << codemonName << "? (y/n): ";
//             std::cin >> skillChoice;
//             if (skillChoice != 'y') {
//                 break;
//             }
//             std::string skillName;
//             int damage;

//             std::cin.ignore();
//             std::cout << "  Enter skill name: "; // taking in skills info
//             std::getline(std::cin, skillName);
//             std::cout << "  Enter base damage: ";
//             std::cin >> damage;
//             std::cin.ignore();

//             Skill skill(skillName, damage); // intializes skill
//             codemon.addSkill(skill);        // then adds skill
//         }

//         updateCodemon(codemon); // adds codemon
//     }

// }

// const int POOL_SIZE = 12;

// const std::string CODEMON_NAMES[POOL_SIZE] = {
//     "Flareth", // Fire
//     "Aquagon", // Water
//     "Leafowl", // Grass
//     "Voltiguana", // Electric
//     "Infermouse", // Fire
//     "Bubbletail", // Water
//     "Shrubling", // Grass
//     "Zapkit", // Electric
//     "Cindermole", // Fire
//     "Torrentoise", // Water
//     "Thornabbit", // Grass
//     "Shockpup" // Electric
// };

// const std::string CODEMON_TYPES[4] = {
//     "Fire",
//     "Water",
//     "Grass",
//     "Electric",
// };

// const int CODEMON_HP[POOL_SIZE] = {
//     40, 42, 38, 35,
//     34, 45, 37, 32,
//     39, 48, 40, 36
// };

// const int CODEMON_LEVELS[POOL_SIZE] = {
//     5, 4, 2, 6,
//     7, 3, 1, 0,
//     8, 9, 10, 11
// };

// const std::string CODEMON_SKILLS[POOL_SIZE] = {
//     "Flame Burst", "Aqua Jet", "Razor Leaf", "Thunder Jolt",
//     "Fire Claw", "Bubble Beam", "Vine Whip", "Static Bolt",
//     "Ember Rage", "Water Pulse", "Spore Shot", "Spark Bite"
// };

// const int CODEMON_SKILL_DAMAGE[POOL_SIZE] = {
//     12, 10, 11, 13,
//     15, 14, 19, 17,
//     16, 18, 20, 21
// };

// void Contestant::generateCodemons() {
//     for (int i = 0; i < 3; i++) {
//         std::string codemonName, type;
//         int level, hp;
//         int random = rand() % 12;
//         codemonName = CODEMON_NAMES[random];
//         type = CODEMON_TYPES[random % 4];
//         level = CODEMON_LEVELS[rand() % 12];
//         hp = CODEMON_HP[rand() % 12];

//         Codemon codemon(codemonName, type, level, hp); // initializes codemon with values

//         // Add Skills to Codo?=mon
//         std::string skillName;
//         int damage;

//         skillName = CODEMON_SKILLS[random];
//         damage = CODEMON_SKILL_DAMAGE[rand() % 12];

//         Skill skill(skillName, damage); // intializes skill
//         codemon.addSkill(skill);        // then adds skill


//         updateCodemon(codemon); // adds codemon

//     }

// }

// void Contestant::death() {
//     codemonCount -= 1;
//     if (codemonCount == 0) {
//         alive = false;
//     }
//     return;
// }

// bool Contestant::isAlive() {
//     return alive;
// }

// std::ostream& operator<<(std::ostream& os, const Codemon& c) {
//     os << "Name: " << c.getName() << "\n";
//     os << "Type: " << c.getType() << "\n";
//     os << "Level: " << c.getLevel() << "\n";
//     os << "HP: " << c.getCurrentHP() << "/" << c.getMaxHP() << "\n";
//     return os;
// }

