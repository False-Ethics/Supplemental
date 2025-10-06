#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
#include "Declerations.h"        
#include "TBA-RPG-Declerations.h"
using namespace std;

int main()
{
    game game;
    game.roomsSetup();
    game.Start();

    myString moveNorth("move north");
    myString moveSouth("move south");
    myString moveWest("move west");
    myString moveEast("move east");
    myString useItem("use item");
    myString checkSpells("check spells");
    myString quitGame("quit");

    while (true) {
        cout << "Enter command (move north, move west, move east, use item, quit, or check spells.): " << endl;
        myString userCommand;
        userCommand.ReadFromConsole();
        userCommand.ToLower();

        if (userCommand == moveNorth) {
            game.move("north");
        }
        else if (userCommand == moveWest) {
            game.move("west");
        }
        else if (userCommand == moveEast) {
            game.move("east");
        }
        else if (userCommand == useItem) {
            game.useItem();
        }
        else if (userCommand == checkSpells) {
            game.checkSpells();
        }
        else if (userCommand == quitGame) {
            cout << "Quitting game..." << endl;
            break;
        }
        else {
            cout << "Invalid command." << endl;
        }
    }
    return 0;
}