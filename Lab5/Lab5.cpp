#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "extrafile.h"
using namespace std;

//void ReadFromFile(string inFile, vector<Ship>& ships) {
//	ifstream file(inFile, ios::binary);
//
//	//Read number of ships 
//	unsigned int count = 0;
//	file.read((char*)&count, sizeof(count));
//	cout << count << endl;
//
//	for (unsigned int i = 0; i < count; i++) {
//		int length;
//
//		//Read the length of the string
//		file.read((char*)&length, sizeof(length));
//
//		//Dynamicallly allocate an array of chars of that size
//		char* buffer = new char[length];
//
//		//Read into that dyname array
//		file.read(buffer, length);
//
//		//Copy dynamic array into a std::string
//		string shipName = buffer;
//
//		//Delete dynamic array
//		delete[] buffer;
//		//cout << shipName << endl;
//
//		//Read the class
//		file.read((char*)&length, sizeof(length));
//		buffer = new char[length];
//		file.read(buffer, length);
//		string shipClass = buffer;
//		delete[] buffer;
//		//cout << shipClass << endl;
//
//		//Read the ship length
//		short shipLength;
//		file.read((char*)&shipLength, sizeof(shipLength));
//		//cout << shipLength << endl;
//
//		//Read the shield capacity
//		int shieldCapacity;
//		file.read((char*)&shieldCapacity, sizeof(shieldCapacity));
//		//cout << shieldCapacity << endl;
//
//		//Read the warp speed
//		float warpSpeed;
//		file.read((char*)&warpSpeed, sizeof(warpSpeed));
//		//cout << warpSpeed << endl;
//
//		//Read the number of weapons
//		int numOfWeapons;
//		file.read((char*)&numOfWeapons, sizeof(numOfWeapons));
//		//cout << numOfWeapons << endl;
//
//		Ship ship(shipName, shipClass, shipLength, shieldCapacity, warpSpeed);
//		ships.push_back(ship);
//	}
//}

int main()
{	
	vector<Ship> ships;
	//vector<Weapon> weapons;
	//cout << "Which file(s) to open?\n";
	//cout << "1. friendlyships.shp" << endl;
	//cout << "2. enemyships.shp" << endl;
	//cout << "3. Both files" << endl;
	//int option;
	//cin >> option;

	////Load files here 
	//if (option == 1) {
	//	ReadFromFile("enemyships.shp", ships, weapons);
	//}

	//cout << "1. Print all ships" << endl;
	//cout << "2. Starship with the strongest weapon" << endl;
	//cout << "3. Strongest starship overall" << endl;
	//cout << "4. Weakest ship (ignoring unarmed)" << endl;
	//cout << "5. Unarmed ships" << endl;

	//cin >> option;

	/* Work your magic here */

	ifstream file("enemyships.shp", ios::binary);

	//Read number of ships 
	unsigned int count = 0;
	file.read((char*)&count, sizeof(count));
	cout << count << endl;

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
	cout << shipName << endl;

	//Read the class
	file.read((char*)&length, sizeof(length));
	buffer = new char[length];
	file.read(buffer, length);
	string shipClass = buffer;
	delete[] buffer;
	cout << shipClass << endl;

	//Read the ship length
	short shipLength;
	file.read((char*)&shipLength, sizeof(shipLength));
	cout << shipLength << endl;

	//Read the shield capacity
	int shieldCapacity;
	file.read((char*)&shieldCapacity, sizeof(shieldCapacity));
	cout << shieldCapacity << endl;

	//Read the warp speed
	float warpSpeed;
	file.read((char*)&warpSpeed, sizeof(warpSpeed));
	cout << warpSpeed << endl;

	//Read the number of weapons
	int numOfWeapons;
	file.read((char*)&numOfWeapons, sizeof(numOfWeapons));
	cout << numOfWeapons << endl;

	//Read the weapon name
	file.read((char*)&length, sizeof(length));
	buffer = new char[length];
	file.read(buffer, length);
	string weaponName = buffer;
	delete[] buffer;
	cout << weaponName << endl;

	//Read the power rating
	int powerRating;
	file.read((char*)&powerRating, sizeof(powerRating));
	cout << powerRating << endl;

	//Read the power
	float power;
	file.read((char*)&power, sizeof(power));
	cout << power << endl;

	
	/*for (unsigned int i = 0; i < 2; i++) {
		cout << ships[i].GetName() << endl;
		cout << ships[i].GetShipClass() << endl;
		cout << ships[i].GetShipLength() << endl;
		cout << ships[i].GetShieldCapacity() << endl;
		cout << ships[i].GetWarpSpeed() << endl;
	}*/


	return 0;
}
