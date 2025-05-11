#ifndef CONTESTANT_H
#define CONTESTANT_H
#include "Arena.h"
#include "Codemon.h"
#include "item.h"
#include <string>
using namespace std;

class Contestant {
private:
    Codemon* team = nullptr;
    int teamsize = 0;
    int activeCodemon = 0;
    
    char symbol; // Contestant's char

    int row = -1;
    int col = -1;

    string playerName;
    bool isHuman = true;

    //shared dynamic Item Queueu
    static Item* itemQueue;
    static int qCapacity;
    static int qSize;
    static int qFront;

    // Desc: Resizes the shared item queue
    // Pre: newCapacity > current capacity
    // Post: Resizes and copies old items to new array
    void resizeQueue(int newCapacity);

public:
    // Desc: Default constructor
    // Pre: None
    // Post: Initializes contestant with defaults
    Contestant();

    // Desc: Parameterized constructor that sets name, human status, and team size
    // Pre: name is a valid string, codemonNum ≥ 0
    // Post: Initializes player with name and sets up team
    Contestant(string name, bool human, int codemonNum);

    // Desc: Destructor
    // Pre: None
    // Post: Cleans up dynamic team memory
    ~Contestant();
    
    Codemon* getTeam() const;
    
    // Desc: Copy constructor
    // Pre: other must be a valid Contestant
    // Post: Deep copies other into this Contestant
    Contestant(const Contestant& other);

    // Desc: Returns the contestant's name
    string getName() const;

    // Desc: Assignment operator overload
    // Pre: rhs must be a valid Contestant
    // Post: Assigns rhs's data into this Contestant
    Contestant& operator = (const Contestant& rhs);

    // Desc: Places all Codemons randomly on the map
    // Pre: Arena must be initialized
    // Post: Codemons placed in valid cells
    void placeRandomCodemon(Arena& A);

    // Desc: Sets active Codemon by index
    // Pre: n must be a valid team index
    // Post: Updates activeCodemon index
    void setActiveCodemon(const int n);

    // Desc: Initializes shared item queue with first capacity
    // Pre: firstCap > 0
    // Post: Allocates static queue
    static void initSharedQueue(int firstCap);

    // Desc: Sets the team size for the contestant
    // Pre: n ≥ 0
    // Post: Allocates dynamic team array
    void setTeamSize(int n);

    // Desc: Adds a Codemon to the team at specified index
    // Pre: idx < team size
    // Post: Adds Codemon at idx
    bool addCodemon(const Codemon& c, int idx);

    // Desc: Returns reference to currently active Codemon
    // Pre: Team must be initialized
    // Post: Returns Codemon& reference
    Codemon& getActive();

    // Desc: Spawns contestant at a position in arena
    // Pre: r and c are valid coordinates
    // Post: Updates row/col, places player on arena
    void spawn(Arena& arena, int r, int c, char symbol);

    // Desc: Takes a turn (move, attack, etc.)
    // Pre: Arena must be initialized
    // Post: Applies contestant's actions
    void takeTurn(Arena& arena, char symbol);

    // Desc: Enqueues an item to the shared queue
    // Pre: item must be valid
    // Post: Item added to the rear of queue
    void enqueueItem(const Item& item);

    // Desc: Uses the next item in queue
    // Pre: Queue must not be empty
    // Post: Applies effect to active Codemon
    bool useNextItem();

    // Desc: Selects team Codemons from pool (manual or random)
    // Pre: pool must be valid, poolSize ≥ n
    // Post: Team is populated with selected Codemons
    void selectCodemons(Codemon pool[], int poolSize, bool random);

    // Desc: Prints a 3x3 visible portion of arena centered on the contestant
    // Pre: Arena must be initialized
    // Post: Outputs partial map view
    void printVisibleMap(const Arena& A) const;

    // Desc: Returns current row position
    // Pre: row must be initialized
    // Post: Returns int row
    int getRow() const;

    // Desc: Returns current column position
    // Pre: col must be initialized
    // Post: Returns int col
    int getCol() const;

    // Desc: Returns true if the player is human
    // Pre: none
    // Post: Returns bool isHuman
    bool isHum() const;

    // Desc: Returns true if any Codemon is still alive
    // Pre: Team must be initialized
    // Post: Returns true if at least one Codemon is alive
    bool isAlive() const;
    
    const Codemon& getActive() const;
};

#endif