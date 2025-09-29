#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
#include "Declerations.h"
#include "TBA-RPG-Declerations.h"
using namespace std;


//texts
string intro() {
	cout << "===================={ Text Based RPG }====================" << endl;
	cout << " " << endl;
	cout << "You enter a haunted house" << endl;
	return 0;
}

string outro() {
	cout << " " << endl;
	cout << "===================={ Text Game Over }====================" << endl;
	return 0;
}
//=============================

inline playerItem::~playerItem()
{
}
