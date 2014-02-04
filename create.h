using namespace std;

int playerInfo[2];
int playerLocation = 0;
void createCharacter();
void initialItems();

void createCharacter() 
{
    xp = 0;
    clearPlayerInv();
    cout << menuBar;
    cout << "         Welcome to Geoff's Text Adventure!\n\n";
    cout << "               Choose your sex:\n\n";
    cout << "                 1:  Male\n";
    cout << "                 2:  Female\n\n\n\n";
    cout << menuBar;
    cin >> userInput;
    playerInfo[0] = userInput;
    system("clear");
    cout << menuBar;
    cout << "            Choose your class:\n\n\n";
    cout << "                 1:  Warrior\n";
    cout << "                 2:  Druid\n";
    cout << "                 3:  Thief\n\n\n\n";
    cout << menuBar;
    cin >> userInput;
    playerInfo[1] = userInput;
    playerLocation = 1;
    initialItems();
    moneybag = initialFunds(playerInfo[1]);
    system("clear");
    cout << menuBar << "\n\n";
    cout << "      Your initial funds are " << moneybag << " gold pieces.\n\n";
    cout << "   New items have been added to your inventory!\n\n";
    cout << "         Press 1 to start your adventure!\n\n\n";
    cout << menuBar;
    cin >> userInput;
    return;
}

void initialItems()
{
    //Warrior Creation
    if (playerInfo[1] == 1)
    {
        //add sword
        addInventory(0, 0, 50);
        //add helm
        addInventory(1, 0, 50);
        //add gauntlets
        addInventory(1, 3, 50);
        //add boots
        addInventory(1, 6, 50);

    }
    //Druid Creation
    else if (playerInfo[1] == 2)
    {
        //add riding boots
        addInventory(1, 7, 20);
        //add magic potions
        addInventory(2, 2, 1);
        addInventory(2, 2, 1);
        addInventory(2, 2, 1);
        //add food
        addInventory(2, 9, 1);
    }
    //Thief Creation
    else if (playerInfo[1] == 3)
    {
        //Add axe
        addInventory(0,4,75);
        //add booze collection
        addInventory(2,4,1);
        addInventory(2,4,1);
        addInventory(2,4,1);
        //add rations
        addInventory(2,7,1);
        addInventory(2,7,1);
    }
}
