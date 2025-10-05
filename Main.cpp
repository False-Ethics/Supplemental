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

    while (true) {
        cout << "Enter command (move north, move west, move east, use item, quit, or check spells.): " << endl;
        myString userCommand;
        userCommand.ReadFromConsole();
        userCommand.ToLower();

        if (userCommand == "move north") {
            game.move("north");
        }
        else if (userCommand == "move west") {
            game.move("west");
        }
        else if (userCommand == "move east") {
            game.move("east");
        }
        else if (userCommand == "use item") {
            game.useItem();
        }
        else if (userCommand == "check spells") {
            game.checkSpells();
        }
        else if (userCommand == "quit") {
            cout << "Quitting game..." << endl;
            break;
        }
        else {
            cout << "Invalid command." << endl;
        }
    }
    return 0;
}