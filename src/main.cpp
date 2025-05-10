// debug_main.cpp
#include <iostream>
#include "Arena.h"
#include "mechanic.h"
#include "utility.h"   // loadFromfile template
#include "skill.h"
#include "Codemon.h"
#include "item.h"

using namespace std;

int main() {
    srand(950);

    // Load skills & items from text files
    const int MAX_POOL = 50;
    Skill skills[MAX_POOL];
    Item  items [MAX_POOL];

    loadFromfile<Skill>("skills.txt",  skills, MAX_POOL);
    loadFromfile<Item>("items.txt",    items,  MAX_POOL);

    cout << endl << "=== First 3 skills loaded ===" << endl;
    for (int i = 0; i < 3; ++i) skills[i].print();

    cout << endl << "=== First 3 items loaded ===" << endl;
    for (int i = 0; i < 3; ++i) items[i].print();

    //Codemon sanity check
    Codemon blaze("Blazix", "A blazing fire lion.", "Fire",10, 300); 

    // add up to 3 Fire‑type skills from the pool
    for (int i = 0; i < 3; ++i)
        blaze.addSkill(skills[i]);
    
    cout << endl << "=== Codemon initial state ===" << endl;
    blaze.print();

    // take damage and heal test
    blaze.takeDamage(20);
    cout << endl << "After taking 120 damage:" << endl;
    blaze.print();

    blaze.heal(50);  // HP < 70%, should Refuse
    cout << endl << "Attempted heal 50 (should Refuse):" << endl;
    blaze.print();

    blaze.takeDamage(150);  // bring HP low
    blaze.heal(50);         // now allowed
    cout << "\nAfter big damage and heal 50:\n";
    blaze.print();

    //Arena & movement check
    Arena battlefield;
    battlefield.setTerrainTile(5, 5, '@');
    cout << endl;
    battlefield.printVisibleMap();

    cout << "Move your Codemon (W A S D Q E Z C): ";
    char mv;  cin >> mv;
    movement(mv, '@', battlefield);
    cout << endl;
    battlefield.printVisibleMap();

    return 0;
}
