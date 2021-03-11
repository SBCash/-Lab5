#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ship {
public:
	Ship(string shipName, string shipClass, unsigned int shipLength, unsigned int shieldCapacity, unsigned int numOfWeapons);
	string GetName();
	string GetShipClass();
	unsigned int GetShipLength();
	unsigned int GetShieldCapacity();
	unsigned int GetNumOfWeapons();

private:
	string shipName;
	string shipClass;
	unsigned int shipLength;
	unsigned int shieldCapacity;
	unsigned int numOfWeapons;
};

