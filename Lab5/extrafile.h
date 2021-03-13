#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Ship {
public:
	class Weapon {
	public:
		string weaponName;
		unsigned int powerRating;
		float power;

		Weapon(string weaponName, unsigned int powerRating, float power);
		string GetWeaponName();
		unsigned int GetPowerRating();
		float GetPower();
	};

	Ship(string shipName, string shipClass, unsigned short shipLength, unsigned int shieldCapacity, float warpSpeed, vector<Weapon> weapons);
	string GetName();
	string GetShipClass();
	unsigned short GetShipLength();
	unsigned int GetShieldCapacity();
	float GetWarpSpeed();
	vector<Weapon> weapons;

private:
	string shipName;
	string shipClass;
	unsigned short shipLength;
	unsigned int shieldCapacity;
	float warpSpeed;
};

Ship::Ship(string shipName, string shipClass, unsigned short shipLength, unsigned int shieldCapacity, float warpSpeed, vector<Weapon> weapons) {
	this->shipName = shipName;
	this->shipClass = shipClass;
	this->shipLength = shipLength;
	this->shieldCapacity = shieldCapacity;
	this->warpSpeed = warpSpeed;
	this->weapons = weapons;
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

Ship::Weapon::Weapon(string weaponName, unsigned int powerRating, float power){
	this->weaponName = weaponName;
	this->powerRating = powerRating;
	this->power = power;
}

string Ship::Weapon::GetWeaponName() {
	return weaponName;
}

unsigned int Ship::Weapon::GetPowerRating() {
	return powerRating;
}

float Ship::Weapon::GetPower() {
	return power;
}


