#include <iostream>
#include <string>
#include <cstdlib>
#include "inv.h"
#include "menus.h"
#include "create.h"
#include "level1.h"

string answer;
using namespace std;
bool gameDone = false;
int main()
{
    while (gameDone == false)
    {
        system("clear");
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
