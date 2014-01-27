using namespace std;

int playerInfo[2];
int playerLocation = 0;
void createCharacter();
void initialItems();

void createCharacter() 
{
    debugopen();
    debugfile << "character creation started\n";
    debugclose();
    clearPlayerInv();
    cout << menuBar;
    cout << "         Welcome to Geoff's Text Adventure!\n\n";
    cout << "               Choose your sex:\n\n";
    cout << "                 1:  Male\n";
    cout << "                 2:  Female\n\n\n\n";
    cout << menuBar;
    cin >> userInput;
    debugopen();
    debugfile << "user chose " << userInput << " for sex\n";
    debugclose();
    playerInfo[0] = userInput;
    system("clear");
    cout << menuBar;
    cout << "            Choose your class:\n\n\n";
    cout << "                 1:  Warrior\n";
    cout << "                 2:  Druid\n";
    cout << "                 3:  Thief\n\n\n\n";
    cout << menuBar;
    cin >> userInput;
    debugopen();
    debugfile << "user chose " << userInput << " for class\n";
    debugclose();
    playerInfo[1] = userInput;
    playerLocation = 1;
    debugopen();
    debugfile << "player location is " << playerLocation << " \n";
    debugclose();
    initialItems();
    debugopen();
    debugfile << "inital items added to inventory\n";
    debugclose();
    moneybag = initialFunds(playerInfo[1]);
    debugopen();
    debugfile << "initial funds of " << moneybag << " goldpieces added\n";
    debugclose();
    system("clear");
    cout << menuBar << "\n\n";
    cout << "      Your initial funds are " << moneybag << " gold pieces.\n\n";
    cout << "   New items have been added to your inventory!\n\n";
    cout << "         Press 1 to start your adventure!\n\n\n";
    cout << menuBar;
    cin >> userInput;
    debugopen();
    debugfile << "character creation closed\n";
    debugclose();
    return;
}

void initialItems()
{
    //Warrior Creation
    if (playerInfo[1] == 1)
    {
        //add sword
        addInventory(0, 0);
        //add helm
        addInventory(1, 0);
        //add gauntlets
        addInventory(1, 3);
        //add boots
        addInventory(1, 6);

        debugopen();
        debugfile << "warrior initial items added successfully\n";
        debugclose();
    }
    //Druid Creation
    else if (playerInfo[1] == 2)
    {
        //add riding boots
        addInventory(1, 7);
        //add magic potions
        addInventory(2, 2);
        addInventory(2, 2);
        addInventory(2,2);
        //add food
        addInventory(2,9);
        debugopen();
        debugfile << "druid iniital items added successfully\n";
        debugclose();
    }
    //Thief Creation
    else if (playerInfo[1] == 3)
    {
        //Add axe
        addInventory(0,4);
        //add booze collection
        addInventory(2,4);
        addInventory(2,4);
        addInventory(2,4);
        //add rations
        addInventory(2,7);
        addInventory(2,7);
        debugopen();
        debugfile << "thief initial items added successfully\n";
        debugclose();
    }
}
