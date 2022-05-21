#include <iostream>
#include <string>
#include "Character.h"
#include "Warrior.h"
#include "Elf.h"

using namespace std;

int main() {
    // create 2 Warriors and 2 Elves
    Warrior w1("Arthur", 100, 6, "King George");
    Warrior w2("Leo", 100, 9, "King George");
    Elf e1("Raegron", 100, 4, "Sylvarian");
    Elf e2("Melimion", 100, 5, "Sylvarian");

    // now have them attack each other
    w1.attack(e1);
    cout << endl;
    w1.attack(w2);
    cout << endl;
    e1.attack(e2);
    cout << endl;
    e1.attack(w2);
    cout << endl;

    return 0;
}