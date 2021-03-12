#include <iostream>
#include <string>
#include <vector>
#include "extrafile.h"
using namespace std;


Ship::Ship(string shipName, string shipClass, unsigned short shipLength, unsigned int shieldCapacity, float warpSpeed/*, unsigned int numOfWeapons*/) {
	this->shipName = shipName;
	this->shipClass = shipClass;
	this->shipLength = shipLength;
	this->shieldCapacity = shieldCapacity;
	this->warpSpeed = warpSpeed;
	this->numOfWeapons = numOfWeapons;
}

string Ship::GetName() {
	return shipName;
}

string Ship::GetShipClass() {
	return shipClass;
}

unsigned short Ship::GetShipLength() {
	return shipLength;
}

unsigned int Ship::GetShieldCapacity() {
	return shieldCapacity;
}

float Ship::GetWarpSpeed() {
	return warpSpeed;
}

unsigned int Ship::GetNumOfWeapons() {
	return numOfWeapons;
}

//Weapon::Weapon(string weaponName, unsigned int powerRating, float power) {
//	this->weaponName = weaponName;
//	this->powerRating = powerRating;
//	this->power = power;
//}
//
//string GetWeaponName() {
//	return weaponName;
//}
//
//unsigned int GetPowerRating() {
//	return powerRating;
//}
//
//float GetPower() {
//	return power;
//}
