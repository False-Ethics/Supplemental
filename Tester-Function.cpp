#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
#include "Tester.h"
using namespace std;

//-------------------------------

void ConstructorTest() //poggers
{
	cout << "Constructor Test" << endl;
	myString greeting("Hello");
	greeting.WriteToConsole();
	myString copy(greeting);
	copy.WriteToConsole();
	cout << endl;
}
void AppendPrependTest() //It looks wrong but i made it work lmao
{
	cout << "Append Prepend Test" << endl;
	myString greeting("World");
	greeting.Append(myString(" :D"));
	greeting.WriteToConsole();

	greeting.Prepend(myString(" Hello"));
	greeting.WriteToConsole();
	cout << endl;
}
void UpperLowerTest() //poggers
{
	cout << "Upper/Lower Test" << endl;
	myString greeting("Hello World");
	greeting.ToUpper().WriteToConsole();
	greeting.ToLower().WriteToConsole();
	cout << endl;
}
void FindReplaceTest() //i hate this test
{
	cout << "Find and Replace Test!" << endl;
	myString greeting("Hello World!");
	size_t position = greeting.Find(myString("World"));
	cout << "Finder test: " << position << endl;
	greeting.Replace(myString("world"), myString("UNIVERSE!!")).WriteToConsole();
	cout << endl;
}
void EqualtoTest() //poggers
{
	cout << "Equal Test" << endl;
	myString one("Hello");
	myString two("Hello");
	myString three("World");
	if (one.EqualTo(two)) {
		cout << "1 = 2" << endl;
	}
	else {
		cout << "1 != 2" << endl;
	}
	if (one.EqualTo(three)) {
		cout << "1 = 3" << endl;
	}
	else {
		cout << "1 != 3" << endl;
	}
}
void CharacterAtTest()//poggers
{
	cout << "Character at Test" << endl;
	myString greeting("Hello");
	cout << "(1): " << greeting.CharacterAt(1) << endl;
	cout << endl;
}
void ReadWritreTest() //poggers
{
	cout << "Read and Write Test" << endl;
	myString input;
	cout << "enter a word: " << endl;
	input.ReadFromConsole(); //not me trying to cin >> input zzz
	input.WriteToConsole();
	cout << endl;
}