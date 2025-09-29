#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
using namespace std;

string intro();
string outro();

class playerItem
{
private:
	int itemCount = 0;
	string item[3];
public:
	playerItem() {
		item[0] = "Item Holder 1";
		item[1] = "Item Holder 2";
		item[2] = "Item Holder 3";
	};
public:
	
}

class Game
{
public:

	Game();
	~Game();
public:

private:

public:

	bool operator==(const Game& other) const
	{
		return false;
	}
};
// 
Game::Game()
{
}
Game::~Game()
{
}

