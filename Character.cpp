#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

// constructor (inline)
Character::Character(HeroType pType, 
                     const string &pName, 
                     double pHealth,
                     double pAttackStrength)
: type(pType), name(pName), health(pHealth), attackStrength(pAttackStrength) {}

HeroType Character::getType() const {
    return this->type; // returns the hero type
}

const string & Character::getName() const {
    return this->name; // returns the hero's name
}

int Character::getHealth() const {
    return static_cast<int>(this->health); // returns the whole number of health value
}

void Character::damage(double d) {
    this->health = this->health - d; // reduces characters health by the given amount in parameter

    // output a message showing how much damage was sustained by the object (implicit param)
    cout << this->name << " takes " << d << " damage." << endl;
}

bool Character::isAlive() const {
    // if the getHealth() function on an object returns an amount > 0, return true
    if (getHealth() > 0) {
        return true;
    } else {
        return false;
    }
}