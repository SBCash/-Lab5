#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "extrafile.h"
using namespace std;

int main()
{	
	vector<Ship> ships;
	//cout << "Which file(s) to open?\n";
	//cout << "1. friendlyships.shp" << endl;
	//cout << "2. enemyships.shp" << endl;
	//cout << "3. Both files" << endl;
	//int option;
	//cin >> option;

	///* Load files here */
	unsigned int count = 0;
	ifstream inFileEnemy("enemyships.shp");
	inFileEnemy.read((char*)&count, sizeof(count));
	cout << count << endl;

	/*ifstream inFileFriendlyShips("friendlyships.shp", ios_base::binary);
	inFileFriendlyShips.read((char*)&count, sizeof(count));
	cout << count << endl;*/

	//cout << "1. Print all ships" << endl;
	//cout << "2. Starship with the strongest weapon" << endl;
	//cout << "3. Strongest starship overall" << endl;
	//cout << "4. Weakest ship (ignoring unarmed)" << endl;
	//cout << "5. Unarmed ships" << endl;

	//cin >> option;

	/* Work your magic here */
	//for (unsigned int i = 0; i < count; i++) {
	int length;

		//Read the length of the string
		inFileEnemy.read((char*)&length, sizeof(length));

		//Dynamicallly allocate an array of chars of that size
		char* buffer = new char[length];

		//Read into that dyname array
		inFileEnemy.read(buffer, length);

		//Copy dynamic array into a std::string
		string shipName = buffer;
		cout << shipName << endl;

		//Delete dynamic array
		delete[] buffer;

		//Read the class
		inFileEnemy.read((char*)&length, sizeof(length));
		buffer = new char[length];
		inFileEnemy.read(buffer, length);
		string shipClass = buffer;
		cout << shipClass << endl;
		delete[] buffer;
		
		//Read the ship length
		short shipLength;
		inFileEnemy.read((char*)&shipLength, sizeof(shipLength));
		cout << shipLength << endl;

		//Read the shield capacity
		int shieldCapacity;
		inFileEnemy.read((char*)&shieldCapacity, sizeof(shieldCapacity));
		cout << shieldCapacity << endl;

		//Read the warp speed
		float warpSpeed;
		inFileEnemy.read((char*)&warpSpeed, sizeof(warpSpeed));
		cout << warpSpeed << endl;

		//Read the number of weapons
		int numOfWeapons;
		inFileEnemy.read((char*)&numOfWeapons, sizeof(numOfWeapons));
		cout << numOfWeapons << endl;
	//	
	//	Ship ship(shipName, shipClass, shipLength, shieldCapacity, numOfWeapons);
	//	ships.push_back(ship);
	//}

	/*for (unsigned int i = 0; i < 2; i++) {
		cout << ships[i].GetName() << endl;
	}*/


	return 0;
}
