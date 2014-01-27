using namespace std;

// Management System for Weapon Items
//int moneybag = 0;
string playerInput;
int userInput = 0;
int itemType = 0;
int itemNumber;
int doneEquiping;
int pos1;
int pos2;
int etable;
int eitemNumber;
string findItemName(int itemNumber, int table);
string selection;
string item;
void addInventory(int table, int item);
void createItem();
void addPartyLiquor();
int itemRoll = 0;
void checkForItem();
int debugInventory();
int inventoryCheck();
void equipItem(int table, int itemNumber);
void equipWeapon(int table, int itemNumber);
void equipHelm(int table, int itemNumber);
void equipPlate(int table, int itemNumber);
void equipGauntlets(int table, int itemNumber);
void equipBoots(int table, int itemNumber);
void dropItem(int itemNumber);
void clearPlayerInv();

    const int NUM_WEAPONS = 13;
    string weapons[NUM_WEAPONS] = {
        "Sword",
        "Iron Sword",
        "Steel Sword",
        "Great Sword",
        "Axe",
        "Iron Axe",
        "Steel Axe",
        "Great Axe",
        "Hammer",
        "Iron Hammer",
        "Steel Hammer",
        "Great Hammer",
        "Dart"
    };
    
    const int weapon_prop_col = 5;
    const int weapon_prop_row = NUM_WEAPONS;
    int weapon_prop[weapon_prop_row][weapon_prop_col] = {
        {0, 5, 50, 6, 100} ,
        {1, 11, 75, 4, 85} ,
        {2, 17, 100, 3, 50} ,
        {3, 25, 300, 1, 5},
        {4, 8, 75, 8, 75} ,
        {5, 15, 100, 6, 50} ,
        {6, 23, 100, 5, 30} ,
        {7, 30, 300, 4, 5} ,
        {8, 12, 100, 10, 50} ,
        {9, 18, 150, 8, 25} ,
        {10, 27, 200, 7, 10} ,
        {11, 40, 300, 6, 5} ,
        {12, 5, 1, 2, 40}
    };


//Management System for Armor Items
    const int NUM_ARMOR = 13;
    string inv_armor[NUM_ARMOR] = {
        "Helm",
        "Iron Helm",
        "Steel Helm",
        "Gauntlets",
        "Iron Gauntlets",
        "Steel Gauntlets",
        "Boots",
        "Riding Boots",
        "Iron Boots",
        "Steel Boots",
        "Breast Plate",
        "Iron Breast Plate",
        "Steel Breast Plate"
    };
   
    const int armor_prop_col = 5;
    const int armor_prop_row = NUM_ARMOR;
    int armor_prop[armor_prop_row][armor_prop_col] = {
        {0, 3, 50, 100} ,
        {1, 5, 75, 75} ,
        {2, 7, 100, 50} ,
        {3, 1, 50, 100} ,
        {4, 3, 75, 75} ,
        {5, 4, 100, 50} ,
        {6, 1, 50, 100} ,
        {7, 1, 20, 75} ,
        {8, 4, 75, 75} ,
        {9, 7, 100, 50} ,
        {10, 5, 50, 100} ,
        {11, 7, 75, 75} ,
        {12, 9, 100, 50}
    };

    const int NUM_CONSUM = 10;
    string inv_consum[NUM_CONSUM] = {
        "Healing Potion",
        "Greater Healing Potion",
        "Magic Potion",
        "Greater Magic Potion",
        "Booze",
        "Party Liquor Brown",
        "Party Liquor Clear",
        "Small Rations",
        "Large Rations",
        "Mushrooms"
    };

    const int consum_prop_col = 5;
    const int consum_prop_row = NUM_CONSUM;
    int consum_prop[consum_prop_row][consum_prop_col] = {
        {0, 2, 0, 1, 70} ,
        {1, 5, 0, 3, 30} ,
        {2, 2, 0, 1, 70} ,
        {3, 5, 0, 3, 30} ,
        {4, 4, 1, 1, 70} ,
        {5, 8, 4, 10, 20} ,
        {6, 8, 4, 10, 20} ,
        {7, 4, 0, 1, 55} ,
        {8, 8, 0, 1, 35} ,
        {9, 5, 2, 1, 50}
        };

//Array for maintaining the player's inventory.
    int playerItemCount = 0;
    const int MAX_PLAYER_INV = 25;
    const int player_inv_col = 2;
    const int player_inv_row = MAX_PLAYER_INV;

    int player_inv[player_inv_row][player_inv_col];

//Arrays for player's equipped items

int player_eweapon[1][2] = {9,9};
int player_ehelm[1][2] = {9,9};
int player_egauntlets[1][2] = {9,9};
int player_eboots[1][2] = {9,9};
int player_eplate[1][2] = {9,9};

int inventoryCheck()
{
    debugopen();
    debugfile << "inventory check started\n";
    debugclose();
    system("clear");
    cout << menuBar;
    cout << "                 Your health is " << playerHealth << "\n";
    cout << "            You have " << moneybag << " gold pieces\n\n";
    cout << "              --Equipped--\n";
    displayEquipped();
    cout << "              --Inventory--\n";
    displayInventory();
    cout << "          (E)quip / Use Item (1)Return\n\n";
    cout << menuBar;
    cin >> playerInput;
    debugopen();
    debugfile << "player chose " << playerInput << "\n";
    debugclose();
    if (playerInput == "e")
    {
        equipMenu();
    }
    else if (playerInput == "1")
    {
        return 0;
    }
    debugopen();
    debugfile << "inventory check closed\n";
    debugclose();
}
int displayEquipped()
{
    debugopen();
    debugfile < "display equipped opened\n";
    debugclose();
    cout << "           Weapon:  ";
    pos1 = player_eweapon[0][0];
    pos2 = player_eweapon[0][1];
    debugopen();
    debugfile << "player_eweapon[" << pos1 << "][" << pos2 << "]\n";
    debugclose();
    if (pos1 == 9)
    {
        cout << "\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "\n";
    }
    cout << "           Helm:  ";
    pos1 = player_ehelm[0][0];
    pos2 = player_ehelm[0][1];
    debugopen();
    debugfile << "player_ehelm[" << pos1 << "][" << pos2 << "]\n";
    debugclose();
    if (pos1 == 9)
    {
        cout << "\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "\n";
    }
    cout << "           Breast plate:  ";
    pos1 = player_eplate[0][0];
    pos2 = player_eplate[0][1];
    debugopen();
    debugfile << "player_eplate[" << pos1 << "][" << pos2 << "]\n";
    debugclose();
    if (pos1 == 9)
    {
        cout << "\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "\n";
    }
    cout << "           Gauntlets:  ";
    pos1 = player_egauntlets[0][0];
    pos2 = player_egauntlets[0][1];
    debugopen();
    debugfile << "player_egauntlets[" << pos1 << "][" << pos2 << "]\n";
    debugclose();
    if (pos1 == 9)
    {
        cout << "\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "\n";
    }
    cout << "           Boots:  ";
    pos1 = player_eboots[0][0];
    pos2 = player_eboots[0][1];
    debugopen();
    debugfile << "player_eboots[" << pos1 << "][" << pos2 << "]\n";
    debugclose();
    if (pos1 == 9)
    {
        cout << "\n\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "\n\n";
    }

    debugopen();
    debugfile << "display equipped closed\n";
    debugclose();
}

int displayInventory()
{
    debugopen();
    debugfile << "display inventory opened\n";
    debugclose();
    for (int i = 0; i < playerItemCount; i++ )
    {
        string tableName;
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                pos1 = player_inv[i][j];
            }
            else if (j == 1)
            {
                pos2 = player_inv[i][j];
                cout << "                 " << findItemName(pos1, pos2) << "\n";
                debugopen();
                debugfile << "player_inv[" << i << "][" << j << "]\n";
                debugclose();
            }
        }
    }
    cout << "\n";
    debugopen();
    debugfile << "display inventory closed\n";
    debugclose();
}

int debugInventory()
{
    int itemPos;
//    system("clear");
    cout << "DEBUG INVENTORY\n";
    for (int i = 0; i < playerItemCount; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            itemPos = player_inv[i][j];
            cout << itemPos << ",";
        }
        cout << "\n";
    }
//    cout << "Press '1' to continue\n";
//    cin >> userInput;
}

string findItemName(int table, int itemNumber)
{
    if (table == 0)
    {
        item = weapons[itemNumber];
    }
    else if (table == 1)
    {
        item = inv_armor[itemNumber];
    }
    else if (table == 2)
    {
        item = inv_consum[itemNumber];
    }
    return item;
}

void addInventory(int table, int item)
{
    debugopen();
    debugfile << "add inventory started\n";
    debugfile << "playerItemCount is " << playerItemCount << "\n";
    debugclose();
    if (playerItemCount < MAX_PLAYER_INV )
    {
    player_inv[playerItemCount][0] = table;
    player_inv[playerItemCount][1] = item;
    debugopen();
    debugfile << "item ["  << table << "]["  << item << "] added to player_inv [" << playerItemCount << "]\n";
    debugclose();
    playerItemCount++;
    debugopen();
    debugfile << "playerItemCount is now " << playerItemCount << "\n";
    debugclose();
    }
    else
    {
        cout << "Inventory is full.";
        debugopen();
        debugfile << "item not added to player inventory\n";
        debugclose();
    }
}

void addPartyLiquor()
{
    player_inv[playerItemCount][0] = 2;
    player_inv[playerItemCount][1] = 5;
    playerItemCount++;
}
void createItem()
{
    debugopen();
    debugfile << "createItem function started\n";
    debugclose();
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    itemType = (randomNumber % 3);
    int percentRoll = (randomNumber % 100) + 1;
    debugopen();
    debugfile << "itemType is " << itemType << "\n";
    debugfile << "percentRoll is " << percentRoll << "\n";
    debugclose();
    string itemArray;

    if (itemType == 0)
    {
        itemRoll = (randomNumber % NUM_WEAPONS);
        debugopen();
        debugfile << "itemRoll is " << itemRoll << "\n";
        debugclose();
        bool wrongrare = true;
        while (wrongrare)
        {
            int checkItem = weapons[itemRoll][5];
            if (checkItem < percentRoll)
            {
                debugopen();
                debugfile << "item too rare \n";
                debugclose();
                srand(static_cast<unsigned int>(time(0)));
                randomNumber = rand();
                itemRoll = (randomNumber % NUM_WEAPONS);
                debugopen();
                debugfile << "itemRoll is now " << itemRoll << "\n";
                debugclose();
            }
            else
            {
                wrongrare = false;
            }
        }
        debugopen();
        debugfile << "create item has closed\n";
        debugclose();
        return;
    }
    else if (itemType == 1)
    {
        itemRoll = (randomNumber % NUM_ARMOR);
        debugopen();
        debugfile << "itemRoll is " << itemRoll << "\n";
        debugclose();
        bool wrongrare = true;
        while (wrongrare)
        {
            int checkItem = inv_armor[itemRoll][4];
            if (checkItem < percentRoll)
            {
                srand(static_cast<unsigned int>(time(0)));
                randomNumber = rand();
                itemRoll = (randomNumber % NUM_ARMOR);
                debugopen();
                debugfile << "item is too rare\n";
                debugfile << "itemRoll is now " << itemRoll << "\n";
                debugclose();
            }
            else
            {
                wrongrare = false;
            }
        }
        debugopen();
        debugfile << "createitem has ended\n";
        debugclose();
        return;
    }
    else if (itemType == 2)
    {
        itemRoll = (randomNumber % NUM_CONSUM);
        debugopen();
        debugfile << "itemRoll is " << itemRoll << "\n";
        debugclose();
        bool wrongrare = true;
        while (wrongrare)
        {
            int checkItem = inv_consum[itemRoll][5];
            if (checkItem < percentRoll)
            {
                srand(static_cast<unsigned int>(time(0)));
                randomNumber = rand();
                itemRoll = (randomNumber % NUM_CONSUM);
                debugopen();
                debugfile << "item too rare\n";
                debugfile << "itemRoll is now " << itemRoll << "\n";
                debugclose();
            }
            else
            {
                wrongrare = false;
            }
        }
        debugopen();
        debugfile << "createitem is closed\n";
        debugclose();
        return;
    }
}
void clearPlayerInv()
{
    for (int i=0; i < playerItemCount; ++i )
    {
        for (int j=0; j < 2; ++j)
        {
            player_inv[i][j]=0;
        }
    }
    playerItemCount = 0;
    debugopen();
    debugfile << "playerItemCount is " << playerItemCount <<"\n";
    debugfile << "player inventory cleared\n";
    debugclose();
}

int equipMenu()
{
    debugopen();
    debugfile << "equipMenu started\n";
    debugclose();
    doneEquiping = 0;
    while (doneEquiping == 0)
    {
        system("clear");
        cout << menuBar;
        cout << "          Choose Item to equip / use:\n\n";
        int startNumber = 0;
        for (int i = 0; i < playerItemCount; i++)
        {
            string tableName;
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                {
                    pos1 = player_inv[i][j];
                }
                else if (j == 1)
                {
                    pos2 = player_inv[i][j];
                    startNumber++;
                    debugopen();
                    debugfile << "player_inv[" << i << "][" << j << "]\n";
                    debugclose();
                    cout << "                 (" << startNumber << ")  " << findItemName(pos1, pos2) << "\n";
                }
            }
        }
        cout <<"\n";
        cout << menuBar;
        cin >> userInput;
        itemNumber = userInput - 1;
        pos1 = player_inv[itemNumber][0];
        pos2 = player_inv[itemNumber][1];
        item = findItemName(pos2, pos2);
        equipItem(pos1,pos2);
        dropItem(itemNumber);
    
        system("clear");
        cout << menuBar << "\n\n\n";
        cout <<"              " << item << " has been equipped!\n\n\n\n";
        cout << "                Press '1' to equip more items\n";
        cout << "                Press '2' to return to menu.\n\n\n\n";
        cout << menuBar;
        cin >> userInput;
        debugopen();
        debugfile << "userInput is " << userInput << "\n";
        debugclose();
        if (userInput == 2)
        {
            doneEquiping = 1;
            debugopen();
            debugfile << "equipMenu closed\n";
            debugclose();
            return 0;
        }
    }
}

void equipItem(int table, int itemNumber)
{
    debugopen();
    debugfile << "equipItem started\n";
    debugclose();
    item = findItemName(table, itemNumber);
    if (item.find("Sword") != string::npos || item.find("Axe") != string::npos || item.find("Hammer") != string::npos || item.find("Dart") != string::npos )
    {
        equipWeapon(table, itemNumber);
    }
    else if (item.find("Helm") != string::npos)
    {
        equipHelm(table, itemNumber);
    }
    else if (item.find("Gauntlets") != string::npos)
    {
        equipGauntlets(table, itemNumber);
    }
    else if (item.find("Boots") != string::npos)
    {
        equipBoots(table, itemNumber);
    }
    else if (item.find("Plate") != string::npos)
    {
        equipPlate(table, itemNumber);
    }
    debugopen();
    debugfile << "equipItem closed\n";
    debugclose();
}
void equipWeapon(int table, int itemNumber)
{
    if (player_eweapon[0][0] != 9)
    {
        etable = player_eweapon[0][0];
        eitemNumber = player_eweapon[0][1];
        addInventory(etable, eitemNumber);
    }
    player_eweapon[0][0] = table;
    player_eweapon[0][1] = itemNumber;
    playersAttack = weapon_prop[itemNumber][1];
    playersSpeed = weapon_prop[itemNumber][3];
    debugopen();
    debugfile << "playersAttack is " << playersAttack << "\n";
    debugfile << "playersSpeed is " << playersSpeed << "\n";
    debugclose();

}

void equipHelm(int table, int itemNumber)
{
    if (player_ehelm[0][0] != 9)
    {
        etable = player_ehelm[0][0];
        eitemNumber = player_ehelm[0][1];
        addInventory(etable, eitemNumber);
    }
    player_ehelm[0][0] = table;
    player_ehelm[0][1] = itemNumber;
    playersHelmAC = armor_prop[itemNumber][1];
    playersAC = playersHelmAC + playersGauntletAC + playersPlateAC + playersBootAC;
    debugopen();
    debugfile << "playersHelmAC is " << playersHelmAC << "\n";
    debugfile << "playersAC is " << playersAC << "\n";
    debugclose();
}

void equipPlate(int table, int itemNumber)
{
    if (player_eplate[0][0] != 9)
    {
        etable = player_eplate[0][0];
        eitemNumber = player_eplate[0][1];
        addInventory(etable, eitemNumber);
    }
    player_eplate[0][0] = table;
    player_eplate[0][1] = itemNumber;
    playersPlateAC = armor_prop[itemNumber][1];
    playersAC = playersHelmAC + playersGauntletAC + playersPlateAC + playersBootAC;

}

void equipGauntlets(int table, int itemNumber)
{
    if (player_egauntlets[0][0] != 9)
    {
        etable = player_egauntlets[0][0];
        eitemNumber = player_egauntlets[0][1];
        addInventory(etable, eitemNumber);
    }
    player_egauntlets[0][0] = table;
    player_egauntlets[0][1] = itemNumber;
    playersGauntletAC = armor_prop[itemNumber][1];
    playersAC = playersHelmAC + playersGauntletAC + playersPlateAC + playersBootAC;
}

void equipBoots(int table, int itemNumber)
{
    if (player_eboots[0][0] != 9)
    {
        etable = player_eboots[0][0];
        eitemNumber = player_eboots[0][1];
        addInventory(etable, eitemNumber);
    }
    player_eboots[0][0] = table;
    player_eboots[0][1] = itemNumber;
    playersBootAC = armor_prop[itemNumber][1];
    playersAC = playersHelmAC + playersGauntletAC + playersPlateAC + playersBootAC;
}

void checkForItem()
{
    string playerInput;
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    int percentRoll = (randomNumber % 100) + 1;
    if ( percentRoll < 25 )
    {
        system("clear");
        createItem();
        item = findItemName(itemType, itemRoll); 
        cout << menuBar << "\n";
        cout << "               You find a " << item << "!\n\n\n";
        cout << "             Press '1' to take it\n";
        cout << "             Press '2' to leave it\n\n\n\n";
        cout << menuBar;
        cin >> playerInput;
        if (playerInput == "1")
        {
            addInventory(itemType, itemRoll);
        }
        else if (playerInput == "2")
        {
            return;
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
}

void dropItem(int itemNumber)
{
    for (int i = itemNumber; i < playerItemCount + 1; i++ )
    {
        int movingI = i + 1;
        for (int j = 0; j < 2; j++)
        {
            player_inv[i][j] = player_inv[movingI][j];
        }
    }
    playerItemCount = playerItemCount - 1;
}
