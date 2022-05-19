#include <iostream>
#include <string>
#include "Warrior.h"

using namespace std;

// Warrior Constructor
// remember for constructors for derived classes, you must FIRST use the base class's constructor to initialize the inherited data members
// (I didn't include the HeroType as a parameter bc I don't want the user to change the type of Hero)
// (i.e, user makes a Warrior object but sets the type to Elf... doesn't make sense)
// (so, each warrior object made will pass in the WARRIOR HeroType into the base class constructor for the data member)
// Each Warrior object will have a HeroType of WARRIOR and only WARRIOR (cannot be changed)
Warrior::Warrior(const string &pName,
                 double pHealth,
                 double pAttackStrength,
                 const string &pAllegiance)
: Character(WARRIOR, pName, pHealth, pAttackStrength), allegiance(pAllegiance) {}

