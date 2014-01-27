#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "debug.h"
#include "menus.h"
#include "money.h"
#include "inv.h"
#include "create.h"
#include "battle.h"
#include "enemies.h"
#include "level1.h"

string answer;
using namespace std;
bool gameDone = false;
int main()
{
debugopen();
debugfile << "Game started\n";
debugclose();
    while (gameDone == false)
    {
debugopen();
debugfile << "Game loop started\n";
debugclose();
        system("clear");
        int playchoice = mainMenu();
debugopen();
debugfile << "Main Menu loaded\n";
debugclose();
        if (playchoice == 0)
        {
            gameDone = true;
            return 0;
        }
        else if (playchoice == 1)
        {
            createCharacter();
            level1();
        }
    }
    debugopen();
    debugfile << "Game exited\n";
    debugclose();
}
