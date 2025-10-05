#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
using namespace std;

string intro();
string outro();


class item {
public: 
	virtual void Use() {}
	virtual void Description() {}
	virtual ~item() {}
};
class treasureChest :public item
{
private:
	bool closeOpen;
	int gold;
public:
	treasureChest() {
		closeOpen = false;
		gold = 1;
	}

	void Use() {
		if (!closeOpen) {
			closeOpen = true;
			cout << "You found a Treasure chest (Totally not a mimic) and find " << gold << " Gold!" << endl;
			gold = 0;
		}
		else {
			cout << "Oh no! Chest is empty!" << endl;
		}
	}

	void Description() {

	}

};
class magicLantern :public item
{
private:
	bool on;

public:
	magicLantern() {
		on = false;
	}
	void Use() {
		if (on) {
			on = false;
			cout << "Magic Lantern is off" << endl;
		}
		else {
			on = true;
			cout << "Magic Lantern is on" << endl;
		}
	}
	void Description() {
		if (on) {
			cout << "The lantern is glowing. (Magically)" << endl;
		}
		else {
			cout << "The lantern is off. (Magically)" << endl;
		}
	}
};
class donutBox :public item
{
private:
	int donutNum;
public:
	donutBox() {
		donutNum = 3;
	}

	void Use() {
		if (donutNum > 0) {
			donutNum = donutNum - 1;
			cout << "You eat a doughnuts. " << donutNum << " doughnuts left" << endl; //Yes, this was written correctly. 
		}
		else {
			cout << "Doughnut Box is empty." << endl;
		}
	}

	void Description() {
		cout << "A box of doughnuts. " << donutNum << "doughnuts left." << endl;
	}
};
class playerSpells {
private:
	string spellList[3];
public:
	playerSpells() {
		spellList[0] = "Light";
		spellList[1] = "FireBolt";
		spellList[2] = "FrostBolt";
	}
	void checkSpells() {
		cout << "Available Spells:" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "- " << spellList[i] << endl;
		}
	}
	void castSpell(string spellName) {
		for (int i = 0; i < spellName.length(); i++) {
			spellName[i] = tolower(spellName[i]);
		}
		if (spellName == "fireball") {
			cout << "You cast light! The room is now illuminated!" << endl;
		}
		else if (spellName == "fireball") {
			cout << "You cast Fireball! The room is now scorching!" << endl;
		}
		else if (spellName == "frostbolt") {
			cout << "You cast Frostbolt! The room is now freezing!" << endl;
		}
		else {
			cout << "You can't cast that spell yet wizard!" << endl;
		}
	}
};
class playerItem
{
private:
	int itemCount;
	string item[3];
public:
	playerItem() {
		itemCount = 0;
		item[0] = "A Box of Donuts.";
		item[1] = "Magic Lantern";
		item[2] = "Treasure Chest";
	};
	void additem(string newitem) {
		if (itemCount < 3) {
			item[itemCount] = newitem;
			itemCount = itemCount + 1;
		}
		else {
			cout << "Inventory Full!" << endl;
		}

	}
	void showItems() {
		cout << "Invetory: " << endl;
		for (int i = 0; i < 3; i++) {
			cout << item[i] << endl;
		}
	}
};

class Room {
public:
	string Description;
	item* roomItem;
	Room* north;
	Room* south;
	Room* east;
	Room* west;
	
	Room() {
		roomItem = NULL;
		north = south = east = west = NULL;
	}
	void EnterRoom() {
		cout << Description << endl;
		if (roomItem != NULL) {
			roomItem->Description(); //accessing pointer brocode way
		}
	}
};
class game
{
public:
	Room mainRoom;
	Room northRoom;
	Room westRoom;
	Room eastRoom;
	Room* currentRoom;

	playerSpells spells;

	void roomsSetup() {
		mainRoom.Description = "You are in the starting Area. You see a north, west, and east door.";
		westRoom.Description = "You are in the West Room. It is dry and damp.";
		northRoom.Description = "You are in the North Room. It is hot and humid.";
		eastRoom.Description = "You are in the East Room. It is dark and dreary.";

		northRoom.roomItem = new donutBox();
		eastRoom.roomItem = new treasureChest();
		westRoom.roomItem = new magicLantern();

		mainRoom.north = &northRoom;
		mainRoom.west = &westRoom;
		mainRoom.east = &eastRoom;
		northRoom.south = &mainRoom;
		westRoom.east = &mainRoom;
		eastRoom.west = &mainRoom;
		currentRoom = &mainRoom;
	}

	void Start() {
		if (currentRoom != nullptr)
			currentRoom->EnterRoom();
	}
	void useItem() {
		if (currentRoom->roomItem != nullptr) {
			currentRoom->roomItem->Use();
		}
		else
		{
			cout << "There is no item here" << endl;
		}
	}
	void checkSpells() {
		spells.checkSpells();
		cout << "Type a spell name to cast it" << endl;
		string spellName;
		getline(cin, spellName);
		if (spellName != "") {
			spells.castSpell(spellName);
		}
	}
	void move(string direction) {
		if (direction == "north" && currentRoom->north != nullptr) {
			currentRoom = currentRoom->north;
		}
		else if (direction == "west" && currentRoom->west != nullptr) {
			currentRoom = currentRoom->west;
		}
		else if (direction == "east" && currentRoom->east != nullptr) {
			currentRoom = currentRoom->east;
		}
		else {
			cout << "You can't move that way." << endl;
			return;
		}
		currentRoom->EnterRoom();
	}
};