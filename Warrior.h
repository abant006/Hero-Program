#include <string>
#include <iostream>
#include "Character.h"

using namespace std;

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

// class derived from character
class Warrior : public Character {
    private:
        string allegiance;

    public:
        // user does not need to input the hero type as a parameter for the constructor
        // inherited data member HeroType is automatically set to WARRIOR for objects of type Warrior
        Warrior(const string &, double, double, const string &);
        void attack(Character &);
};

#endif //__WARRIOR_H__