#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "extrafile.h"
using namespace std;

void ReadFromFile(string inFile, vector<Ship>& ships) {
	ifstream file(inFile, ios::binary);

	//Read number of ships 
	unsigned int count = 0;
	file.read((char*)&count, sizeof(count));
	//cout << count << endl;

	for (unsigned int i = 0; i < count; i++) {
		int length;

		//Read the length of the string
		file.read((char*)&length, sizeof(length));

		//Dynamicallly allocate an array of chars of that size
		char* buffer = new char[length];

		//Read into that dyname array
		file.read(buffer, length);

		//Copy dynamic array into a std::string
		string shipName = buffer;

		//Delete dynamic array
		delete[] buffer;
		//cout << shipName << endl;

		//Read the class
		file.read((char*)&length, sizeof(length));
		buffer = new char[length];
		file.read(buffer, length);
		string shipClass = buffer;
		delete[] buffer;
		//cout << shipClass << endl;

		//Read the ship length
		short shipLength;
		file.read((char*)&shipLength, sizeof(shipLength));
		//cout << shipLength << endl;

		//Read the shield capacity
		int shieldCapacity;
		file.read((char*)&shieldCapacity, sizeof(shieldCapacity));
		//cout << shieldCapacity << endl;

		//Read the warp speed
		float warpSpeed;
		file.read((char*)&warpSpeed, sizeof(warpSpeed));
		//cout << warpSpeed << endl;

		//Read the number of weapons
		int numOfWeapons;
		file.read((char*)&numOfWeapons, sizeof(numOfWeapons));
		//cout << numOfWeapons << endl;

		vector<Ship::Weapon> weapons;
		for (int j = 0; j < numOfWeapons; j++) {
			file.read((char*)&length, sizeof(length));
			buffer = new char[length];
			file.read(buffer, length);
			string weaponName = buffer;
			delete[] buffer;

			int powerRating;
			file.read((char*)&powerRating, sizeof(powerRating));

			float power;
			file.read((char*)&power, sizeof(power));
			weapons.push_back(Ship::Weapon(weaponName, powerRating, power));
		}

		ships.push_back(Ship(shipName, shipClass, shipLength, shieldCapacity, warpSpeed, weapons));
	}
}

void PrintShips(vector<Ship>& ships) {
	unsigned int sum = 0;
	for (unsigned int i = 0; i < ships.size(); i++) {
		cout << "Name: " << ships[i].GetName() << endl;
		cout << "Class: " << ships[i].GetShipClass() << endl;
		cout << "Length: " << ships[i].GetShipLength() << endl;
		cout << "Shield capacity: " << ships[i].GetShieldCapacity() << endl;
		cout << "Maximum Warp: " << ships[i].GetWarpSpeed() << endl;
		cout << "Armaments: " << endl;
		unsigned int count = ships[i].weapons.size();
		if (count == 0) {
			cout << "Unarmed" << endl;
		}
		else {
			for (unsigned int j = 0; j < ships[i].weapons.size(); j++) {
				cout << ships[i].weapons[j].GetWeaponName() << ", " << ships[i].weapons[j].GetPowerRating() << ", " << ships[i].weapons[j].GetPower() << endl;
				sum += ships[i].weapons[j].GetPowerRating();
			}
			cout << "Total firepower: " << sum << endl;
			sum = 0;
		}
		cout << " " << endl;
	}
}

void StrongestWeapon(vector<Ship>& ships) {
	unsigned int max = 0;
	unsigned int sum = 0;
	for (unsigned int i = 0; i < ships.size(); i++) {
		for (unsigned int j = 0; j < ships[i].weapons.size(); j++) {
			if (ships[i].weapons[j].GetPowerRating() > max) {
				max = ships[i].weapons[j].GetPowerRating();
			}
		}
		break;
	}
	int index = 0;
	for (unsigned int i = 0; i < ships.size(); i++) {
		for (unsigned int j = 0; j < ships[i].weapons.size(); j++) {
			if (ships[i].weapons[j].GetPowerRating() == max) {
				index = i;
			}
		}
	}
	cout << "Name: " << ships[index].GetName() << endl;
	cout << "Class: " << ships[index].GetShipClass() << endl;
	cout << "Length: " << ships[index].GetShipLength() << endl;
	cout << "Shield capacity: " << ships[index].GetShieldCapacity() << endl;
	cout << "Maximum Warp: " << ships[index].GetWarpSpeed() << endl;
	cout << "Armaments: " << endl;
	for (unsigned int j = 0; j < ships[index].weapons.size(); j++) {
		cout << ships[index].weapons[j].GetWeaponName() << ", " << ships[index].weapons[j].GetPowerRating() << ", " << ships[index].weapons[j].GetPower() << endl;
		sum += ships[index].weapons[j].GetPowerRating();
	}
	cout << "Total firepower: " << sum << endl;
	sum = 0;
}

void StrongestOverall(vector<Ship>& ships) {
	vector<unsigned int> sums;
	unsigned int sum = 0;
	unsigned int max = 0;
	for (unsigned int i = 0; i < ships.size(); i++) {
		for (unsigned int j = 0; j < ships[i].weapons.size(); j++) {
			sum += ships[i].weapons[j].GetPowerRating();
		}
		sums.push_back(sum);
		sum = 0;
	}
	int index = 0;
	for (unsigned int k = 0; k < sums.size(); k++) {
		if (sums[k] > max) {
			max = sums[k];
			index = k;
		}
	}
	cout << "Name: " << ships[index].GetName() << endl;
	cout << "Class: " << ships[index].GetShipClass() << endl;
	cout << "Length: " << ships[index].GetShipLength() << endl;
	cout << "Shield capacity: " << ships[index].GetShieldCapacity() << endl;
	cout << "Maximum Warp: " << ships[index].GetWarpSpeed() << endl;
	cout << "Armaments: " << endl;
	for (unsigned int j = 0; j < ships[index].weapons.size(); j++) {
		cout << ships[index].weapons[j].GetWeaponName() << ", " << ships[index].weapons[j].GetPowerRating() << ", " << ships[index].weapons[j].GetPower() << endl;
		sum += ships[index].weapons[j].GetPowerRating();
	}
	cout << "Total firepower: " << sum << endl;
	sum = 0;
}

void WeakestOverall(vector<Ship>& ships) {
	vector<unsigned int> sums;
	unsigned int sum = 0;
	for (unsigned int i = 0; i < ships.size(); i++) {
		unsigned int count = ships[i].weapons.size();
		if (count > 0) {
			for (unsigned int j = 0; j < ships[i].weapons.size(); j++) {
				sum += ships[i].weapons[j].GetPowerRating();
			}
		}
		sums.push_back(sum);
		sum = 0;
	}
	/*for (int k = 0; k < sums.size(); k++) {
		cout << sums[k] << " ";
	}*/
	int index = 0;
	int min;
	for (unsigned int k = 0; k < sums.size(); k++) {
		if (sums[k] != 0) {
			min = sums[k];
		}
		if (sums[k] < min) {
			min = sums[k];
			cout << min << endl;
		}
	}
	/*cout << "Name: " << ships[index].GetName() << endl;
	cout << "Class: " << ships[index].GetShipClass() << endl;
	cout << "Length: " << ships[index].GetShipLength() << endl;
	cout << "Shield capacity: " << ships[index].GetShieldCapacity() << endl;
	cout << "Maximum Warp: " << ships[index].GetWarpSpeed() << endl;
	cout << "Armaments: " << endl;
	for (unsigned int j = 0; j < ships[index].weapons.size(); j++) {
		cout << ships[index].weapons[j].GetWeaponName() << ", " << ships[index].weapons[j].GetPowerRating() << ", " << ships[index].weapons[j].GetPower() << endl;
		sum += ships[index].weapons[j].GetPowerRating();
	}
	cout << "Total firepower: " << sum << endl;
	sum = 0;*/
}

void PrintUnarmedShips(vector<Ship>& ships) {
	for (unsigned int i = 0; i < ships.size(); i++) {
		unsigned int count = ships[i].weapons.size();
		if (count == 0) {
			cout << "Name: " << ships[i].GetName() << endl;
			cout << "Class: " << ships[i].GetShipClass() << endl;
			cout << "Length: " << ships[i].GetShipLength() << endl;
			cout << "Shield capacity: " << ships[i].GetShieldCapacity() << endl;
			cout << "Maximum Warp: " << ships[i].GetWarpSpeed() << endl;
			cout << "Armaments: " << endl;
			cout << "Unarmed" << endl;
		}
	}
}

int main()
{	
	vector<Ship> ships;
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	//Load files here 

	cout << " " << endl;
	if (option == 1) {
		ReadFromFile("friendlyships.shp", ships);
	}
	else if (option == 2) {
		ReadFromFile("enemyships.shp", ships);
	}
	else if (option == 3) {
		ReadFromFile("friendlyships.shp", ships);
		ReadFromFile("enemyships.shp", ships);
	}

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;
	cin >> option;

	/* Work your magic here */

	cout << " " << endl;
	if (option == 1) {
		PrintShips(ships);
	}
	else if (option == 2) {
		StrongestWeapon(ships);
	}
	else if (option == 3) {
		StrongestOverall(ships);
	}
	else if (option == 4) {
		WeakestOverall(ships);
	}
	else if (option == 5) {
		PrintUnarmedShips(ships);
	}
	
	return 0;
}
