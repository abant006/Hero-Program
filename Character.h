#include <string>

using namespace std;

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

enum HeroType {WARRIOR, ELF, WIZARD};

const double MAX_HEALTH = 100.0;

class Character {
 protected:
	HeroType type;
	string name;
	double health;
	double attackStrength;

 public:
 	Character(HeroType, const string &, double, double); // character constructor
 	HeroType getType() const;
 	const string & getName() const;
 	int getHealth() const; // returns the whole number of the health value (static_cast to int)
 	void damage(double d); // reduces health value by the amount passed in 
 	bool isAlive() const; // returns true if getHealth() returns an integer greater than 0, otherwise false
	
	// PURE VIRTUAL FUNCTION THAT MUST BE IMPLEMENTED BY DERIVED CLASSES
	// Polymorphism can also be used for references to objects like seen here in the parameter
	// Declares a reference that can refer to to Character or derived class objects
 	virtual void attack(Character &) = 0;
 };

#endif