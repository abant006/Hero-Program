#include <iostream>
#include <string>
#include "Elf.h"

// Elf Constructor
// remember for constructors for derived classes, you must FIRST use the base class's constructor to initialize the inherited data members
// (I didn't include the HeroType as a parameter bc I don't want the user to change the type of Hero)
// (i.e, user makes a Elf object but sets the type to Wizard... doesn't make sense)
// (so, each Elf object made will pass in the ELF HeroType into the base class constructor for the data member)
// Each Elf object will have a HeroType of ELF and only ELF (cannot be changed)
Elf::Elf(const string &eName,
         double eHealth,
         double eAttackStrength,
         const string &eFamily)
: Character(ELF, eName, eHealth, eAttackStrength), family(eFamily) {}

void Elf::attack(Character &opponent) {

    // if the opponent's type is an elf, then make a conversion so you can compare the families
    // REMEMBER, when we construct an object, we automatically pass in the corresponding hero type
    // so the parameter opponent has an associated hero type. Let's compare that
    // CANT CONVERT ANY OBJECT TYPE OTHER THAN ELF TO AN ELF
    // (if opponent is an ELF then we can convert the character object, but if opponent is not an ELF than we cannot convert)
    if (this->type == opponent.getType()) {
        Elf &opp = dynamic_cast<Elf &>(opponent);

        // compare the family of the implicit parameter to the opp's (opponent) family
        // we have to do it within the if conditional because without Elf object opp being declared we can't access another object's family -- doesn't exist
        // (i.e, no GetFamily() function)
        if (this->family == opp.family) {
            cout << "Elf " << this->name << " does not attack Elf " << opp.name << "." << endl;
            cout << "They are both members of the " << this->family << " family." << endl;
        
          // if they are both elves BUT are from different families
        } else {
            double dmg = (this->health / MAX_HEALTH) * this->attackStrength;
            // attack dialogue
            cout << "Elf " << this->name << " shoots an arrow at " << opp.name << " --- TWANG!!" << endl;
            // attack the opponent
            opp.damage(dmg);
        }
     } else {
        double dmg = (this->health / MAX_HEALTH) * this->attackStrength;

        // attack dialogue
        cout << "Elf " << this->name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;

        // attack the opponent
        // call damage() on opp object (the function will subtract that object's (the implicit param) health by variable dmg)
        // when this function is called with an opponent object in the parameter, then the function will subract THE OPPONENT'S health based on variable dmg above
        opponent.damage(dmg);
    }
}