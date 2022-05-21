#include <iostream>
#include <string>
#include "Wizard.h"

using namespace std;

Wizard::Wizard(const string &wName,
               double wHealth,
               double wAttackStrength,
               int wRank)
: Character(WIZARD, wName, wHealth, wAttackStrength), rank(wRank) {}

void Wizard::attack(Character &opponent) {
    // if opponent is also a wizard
    if (this->type == opponent.getType()) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        // damage done to other wizards is the wizard's attack strength multiplied by the ratio of the attacking wizard's rank
        // over the defending wizard's rank

        // first must cast the ratio to a double since dividing 2 int will return a whole number
        // cast either rank to double, and the division will become floating-point division instead of interger division
        double dmg = (static_cast<double>(this->rank) / opp.rank) * this->attackStrength;

        // now attack the other wizard
        cout << "Wizard " << this->name << " atttacks " << opp.name << " --- POOF!!" << endl;
        // opponent wizard was attacked, and now takes damage
        opp.damage(dmg);
    } else {
        // damage done to non-wizards is just the attack strength

        // attack the opponent
        cout << "Wizard " << this->name << " atttacks " << opponent.getName() << " --- POOF!!" << endl;
        // opponent was attacked, and now takes damage
        opponent.damage(this->attackStrength);
    }
}