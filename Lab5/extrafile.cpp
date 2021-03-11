#include <iostream>
#include <string>
#include <vector>
#include "extrafile.h"
using namespace std;


Ship::Ship(string shipName, string shipClass, unsigned int shipLength, unsigned int shieldCapacity, unsigned int numOfWeapons) {
	this->shipName = shipName;
	this->shipClass = shipClass;
	this->shipLength = shipLength;
	this->shieldCapacity = shieldCapacity;
	this->numOfWeapons = numOfWeapons;
}

string Ship::GetName() {
	return shipName;
}

string Ship::GetShipClass() {
	return shipClass;
}

unsigned int Ship::GetShipLength() {
	return shipLength;
}

unsigned int Ship::GetShieldCapacity() {
	return shieldCapacity;
}

unsigned int Ship::GetNumOfWeapons() {
	return numOfWeapons;
}