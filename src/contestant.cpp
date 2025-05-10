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

void Contestant::selectCodemons(Codemon pool[], int poolSize, bool random) {
    setTeamSize(3);

    if (random) {
        for (int i = 0; i < 3; ++i)
            team[i] = pool[rand() % poolSize];
    } else {
        for (int i = 0; i < 3; ++i) {
            cout << "\nPick Codemon #" << i + 1 << ":\n";
            for (int j = 0; j < poolSize; ++j) {
                cout << j << ": " << pool[j].getName() << " (" << pool[j].getType() << ")\n";
            }

            int choice;
            cin >> choice;
            while (choice < 0 || choice >= poolSize) {
                cout << "Invalid. Try again: ";
                cin >> choice;
            }
            team[i] = pool[choice];
        }
    }
}


// Static member initialization
Item* Contestant::itemQueue = nullptr;
int   Contestant::qCapacity = 0;
int   Contestant::qSize     = 0;
int   Contestant::qFront    = 0;
