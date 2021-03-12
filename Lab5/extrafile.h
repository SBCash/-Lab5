#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class Weapon {
//public:
//	Weapon(string weaponName, unsigned int powerRating, float power);
//	string GetWeaponName();
//	unsigned int GetPowerRating();
//	float GetPower();
//
//private: 
//	string weaponName;
//	unsigned int powerRating;
//	float power;
//};
//
//Weapon::Weapon(string weaponName, unsigned int powerRating, float power) {
//	this->weaponName = weaponName;
//	this->powerRating = powerRating;
//	this->power = power;
//}
//
//string Weapon::GetWeaponName() {
//	return weaponName;
//}
//
//unsigned int Weapon::GetPowerRating() {
//	return powerRating;
//}
//
//float Weapon::GetPower() {
//	return power;
//}

class Ship {
public:
	/*class Weapon {
		string weaponName;
		unsigned int powerRating;
		float power;

		string GetWeaponName();
		unsigned int GetPowerRating();
		float GetPower();
	};*/

	Ship(string shipName, string shipClass, unsigned short shipLength, unsigned int shieldCapacity, float warpSpeed, string weaponName, unsigned int powerRating, float power);
	string GetName();
	string GetShipClass();
	unsigned short GetShipLength();
	unsigned int GetShieldCapacity();
	float GetWarpSpeed();
	string GetWeaponName();
	unsigned int GetPowerRating();
	float GetPower();
	//unsigned int GetNumOfWeapons();

private:
	string shipName;
	string shipClass;
	unsigned short shipLength;
	unsigned int shieldCapacity;
	float warpSpeed;
	string weaponName;
	unsigned int powerRating;
	float power;
	//unsigned int numOfWeapons;
};

Ship::Ship(string shipName, string shipClass, unsigned short shipLength, unsigned int shieldCapacity, float warpSpeed, string weaponName, unsigned int powerRating, float power) {
	this->shipName = shipName;
	this->shipClass = shipClass;
	this->shipLength = shipLength;
	this->shieldCapacity = shieldCapacity;
	this->warpSpeed = warpSpeed;
	this->weaponName = weaponName;
	this->powerRating = powerRating;
	this->power = power;
	//this->numOfWeapons = numOfWeapons;
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

//unsigned int Ship::GetNumOfWeapons() {
//	return numOfWeapons;
//}

string Ship::GetWeaponName() {
	return weaponName;
}

unsigned int Ship::GetPowerRating() {
	return powerRating;
}

float Ship::GetPower() {
	return power;
}


