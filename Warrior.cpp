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

void Warrior::attack(Character &opponent) {
    // In order to access allegiance using the Character referenced passed in, we need to dynamic cast the Character reference to a Warrior reference
    // this dynamic casts a Character reference named opponent to Warrior reference named opp
    // without casting, we can't compare the allegiance's because Character class objects do not have a data member allegiance

    // if the opponent's type is a warrior, then make a conversion so you can compare the allegiances
    // REMEMBER, when we construct an object, we automatically pass in the corresponding hero type
    // so the parameter opponent has an associated hero type. Let's compare that
    // CANT CONVERT ANY OBJECT TYPE OTHER THAN WARRIOR TO A WARRIOR
    // (if opponent is a WARRIOR then we can convert the character object, but if opponent is not a WARRIOR than we cannot convert)
    if (this->type == opponent.getType() ) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);

        // compare the allegiance of the implicit parameter to the opp's (opponent) allegiance
        // we have to do it within the if conditional because without Warrior object opp being declared we can't access another object's allegiance -- doesn't exist
        // (i.e, no GetAllegiance() function)
        if (this->allegiance == opp.allegiance) {
            cout << "Warrior " << this->name << " does not attack Warrior " << opp.name << "." << endl;
            cout << "They share an allegiance with " << this->allegiance << endl;

          // if they are both warriors BUT from different families  
        } else {
            // damage done by Warrior is % of health remaining * warrior's attack strength
            double dmg = (this->health / MAX_HEALTH) * this->attackStrength;
            cout << "Warrior " << this->name << " attacks " << opp.name << " --- SLASH!!" << endl;
            // attack the opponent
            opp.damage(dmg);
        }
    } else {
        // damage done by Warrior is % of health remaining * warrior's attack strength
        double dmg = (this->health / MAX_HEALTH) * this->attackStrength;

        // attack dialogue
        cout << "Warrior " << this->name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;

        // attack the opponent
        // call damage() on opp object (the function will subtract that object's (the implicit param) health by variable dmg)
        opponent.damage(dmg);
    }
}