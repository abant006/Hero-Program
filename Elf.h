#include <string>
#include "Character.h"

using namespace std;

#ifndef __ELF_H__
#define __ELF_H__

class Elf : public Character {
    private:
        string family;

    public:
        // user does not need to input the hero type as a parameter for the constructor
        // inherited data member HeroType is automatically set to ELF for objects of type Elf
        Elf(const string &, double, double, const string &);
        void attack(Character &);
};

#endif // __ELF_H__