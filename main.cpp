#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <fstream>
#include "menus.h"
#include "money.h"
#include "inv.h"
#include "create.h"
#include "enemies.h"
#include "battle.h"
#include "level1.h"

string answer;
using namespace std;
bool gameDone = false;
int main()
{
    //main game loop
    while (gameDone == false)
    {
        clearScreen();
        int playchoice = mainMenu();
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
}
