#include "money.h"

int initialFunds(int classmodifier)
{
    srand(static_cast<unsigned int>(time(0)));
    int fundModifier;
    int lowmod;
    if (classmodifier == 1)
    {
        fundModifier = 20; 
        lowmod = 5;
    }
    else if (classmodifier == 2)
    {
        fundModifier = 5;
        lowmod = 1;
    }
    else if (classmodifier == 3)
    {
        fundModifier = 35;
        lowmod = 15;
    }

    int randomNumber = rand();
    int roll = (randomNumber % fundModifier) + 1;
    if (roll < lowmod)
    {
        roll = lowmod;
    }
    int funds = roll * 10;
    return funds;
}
