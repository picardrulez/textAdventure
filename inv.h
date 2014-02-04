using namespace std;

// Management System for Weapon Items
//int moneybag = 0;
string playerInput;
int userInput = 0;
int itemType = 0;
int enemy_inv[4][2]; 
int userMessage = 0;
int itemNumber;
int enemyInventorySize;
int percentRoll = 25;
int doneEquiping;
void equipMessage();
void healthMessage();
void magicMessage();
void drunkMessage();
int findItemValue(int table, int itemNumber);
int countloops = 0;
int pos1;
int sellItem(int itemTable, int itemNumber, int invnumber);
int pos2;
int storeSellMenu();
int buyItem(int itemTable, int itemNumber, int invnumber);
void useItem(int itemNumber);
int etable;
int storeBuyMenu();
int eitemNumber;
string lastEquipped;
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
void displayInventory();
void equipItem(int table, int itemNumber);
void equipWeapon(int table, int itemNumber);
void equipHelm(int table, int itemNumber);
int findItemPrice(int table, int itemNumber);
void equipPlate(int table, int itemNumber);
void equipGauntlets(int table, int itemNumber);
void equipBoots(int table, int itemNumber);
void dropItem(int itemNumber);
void clearPlayerInv();
int wizard_inv[4][2] = {
    {0,3},
    {2,3},
    {2,3},
    {2,9}
};

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
    
    const int weapon_prop_col = 6;
    const int weapon_prop_row = NUM_WEAPONS;
    int weapon_prop[weapon_prop_row][weapon_prop_col] = {
        {0, 5, 50, 6, 100, 3} ,
        {1, 11, 75, 4, 85, 7} ,
        {2, 17, 100, 3, 50, 10} ,
        {3, 25, 300, 1, 5, 15},
        {4, 8, 75, 8, 75, 5} ,
        {5, 15, 100, 6, 50, 9} ,
        {6, 23, 100, 5, 30, 12} ,
        {7, 30, 300, 4, 5, 17} ,
        {8, 12, 100, 10, 50, 7} ,
        {9, 18, 150, 8, 25, 11} ,
        {10, 27, 200, 7, 10, 15} ,
        {11, 40, 300, 6, 5, 20} ,
        {12, 5, 1, 2, 40, 2}
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
        {0, 3, 50, 100, 5} ,
        {1, 5, 75, 75, 7} ,
        {2, 7, 100, 50, 10} ,
        {3, 1, 50, 100, 2} ,
        {4, 3, 75, 75, 5} ,
        {5, 4, 100, 50, 8} ,
        {6, 1, 50, 100, 2} ,
        {7, 1, 20, 75, 5} ,
        {8, 4, 75, 75, 5} ,
        {9, 7, 100, 50, 7} ,
        {10, 5, 50, 100, 10} ,
        {11, 7, 75, 75, 13} ,
        {12, 9, 100, 50, 17}
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

    const int consum_prop_col = 7;
    const int consum_prop_row = NUM_CONSUM;
    int consum_prop[consum_prop_row][consum_prop_col] = {
        {0, 2, 0, 0, 1, 70, 5} ,
        {1, 5, 0, 0, 3, 30, 8} ,
        {2, 0, 2, 0, 1, 70, 5} ,
        {3, 0, 5, 0, 3, 30, 8} ,
        {4, 4, 0, 1, 1, 70, 1} ,
        {5, 8, 0, 4, 10, 20, 10} ,
        {6, 8, 0, 4, 10, 20, 10} ,
        {7, 4, 0, 0, 1, 55, 1} ,
        {8, 8, 0, 0, 1, 35, 5} ,
        {9, 5, 5, 2, 1, 50, 3}
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
    if (playerInput == "e")
    {
        equipMenu();
    }
    else if (playerInput == "1")
    {
        return 0;
    }
}
int displayEquipped()
{
    cout << "           Weapon:  ";
    pos1 = player_eweapon[0][0];
    pos2 = player_eweapon[0][1];
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
    if (pos1 == 9)
    {
        cout << "\n\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "\n\n";
    }

}

void displayInventory()
{
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
            }
        }
    }
    cout << "\n";
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
    if (playerItemCount < MAX_PLAYER_INV )
    {
    player_inv[playerItemCount][0] = table;
    player_inv[playerItemCount][1] = item;
    playerItemCount++;
    xp = xp + 1;
    }
    else
    {
        cout << "Inventory is full.";
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
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    itemType = (randomNumber % 3);
    if (difficultySetting == "Easy")
    {
        percentRoll = ((randomNumber % 100) + 1) - 20;
    }
    else if (difficultySetting == "Medium")
    {
        percentRoll = (randomNumber % 100) + 1;
    }
    else if (difficultySetting == "Hard")
    {
        percentRoll = (randomNumber % 100) + 1;
        if (percentRoll > 10)
        {
            percentRoll = percentRoll + 10;
        }
    }
    else if (difficultySetting == "easy")
    {
        percentRoll = 25;
    }
    string itemArray;

    if (itemType == 0)
    {
        itemRoll = (randomNumber % NUM_WEAPONS);
        bool wrongrare = true;
        while (wrongrare)
        {
            int checkItem = weapons[itemRoll][5];
            if (checkItem < percentRoll)
            {
                srand(static_cast<unsigned int>(time(0)));
                randomNumber = rand();
                itemRoll = (randomNumber % NUM_WEAPONS);
            }
            else
            {
                wrongrare = false;
            }
        }
        return;
    }
    else if (itemType == 1)
    {
        itemRoll = (randomNumber % NUM_ARMOR);
        bool wrongrare = true;
        while (wrongrare)
        {
            int checkItem = inv_armor[itemRoll][4];
            if (checkItem < percentRoll)
            {
                srand(static_cast<unsigned int>(time(0)));
                randomNumber = rand();
                itemRoll = (randomNumber % NUM_ARMOR);
            }
            else
            {
                wrongrare = false;
            }
        }
        return;
    }
    else if (itemType == 2)
    {
        itemRoll = (randomNumber % NUM_CONSUM);
        bool wrongrare = true;
        while (wrongrare)
        {
            int checkItem = inv_consum[itemRoll][6];
            if (checkItem < percentRoll)
            {
                srand(static_cast<unsigned int>(time(0)));
                randomNumber = rand();
                itemRoll = (randomNumber % NUM_CONSUM);
            }
            else
            {
                wrongrare = false;
            }
        }
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
    player_eweapon[0][0] = 9;
    player_eweapon[0][1] = 9;
    player_ehelm[0][0] = 9;
    player_ehelm[0][1] = 9;
    player_egauntlets[0][0] = 9;
    player_egauntlets[0][1] = 9;
    player_eboots[0][0] = 9;
    player_eboots[0][1] = 9;
    player_eplate[0][0] = 9;
    player_eplate[0][1] = 9;
}

int equipMenu()
{
    doneEquiping = 0;
    while (doneEquiping == 0)
    {
        system("clear");
        cout << menuBar;
        cout << "          Press '0' to return.\n";
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
                    cout << "                 (" << startNumber << ")  " << findItemName(pos1, pos2) << "\n";
                }
            }
        }
        cout <<"\n";
        cout << menuBar;
        if (userMessage == 1)
        {
            equipMessage();    
        }
        else if (userMessage == 2)
        {
            healthMessage();
        }
        else if (userMessage == 3)
        {
            magicMessage();
        }
        else if (userMessage == 4)
        {
            drunkMessage();
        }
        userMessage = 0;
        cin >> userInput;
        if (userInput == 0)
        {
            doneEquiping = 1;
            return 0;
        }
        itemNumber = userInput - 1;
        pos1 = player_inv[itemNumber][0];
        pos2 = player_inv[itemNumber][1];
        item = findItemName(pos2, pos2);
        if (pos1 == 2)
        {
            useItem(pos2);
        }
        else
        {
        equipItem(pos1,pos2);
        }
        dropItem(itemNumber);
    }
}

int dropItemMenu()
{
    int itemSelection;
    madechoice = 0;
    while (madechoice == 0)
    {
        system("clear");
        cout << menuBar;
        cout << "              Press '0' To Return\n";
        cout << "              Choose Item To Drop:\n\n";
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
                    cout << "                       (" << startNumber << ")  " << findItemName(pos1, pos2) << "\n";
                }
            }
        }
        cout << "\n";
        cout << menuBar;
        cin >> itemSelection;
        if (itemSelection == 0)
        {
            madechoice = 1;
            return 0;
        }
        else
        {
            itemNumber = itemSelection - 1;
            dropItem(itemNumber);
        }
    }
}
void equipItem(int table, int itemNumber)
{
    item = findItemName(table, itemNumber);
    lastEquipped = item;
    userMessage = 1;
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
    int difficultyPercentage;
    if (difficultySetting == "Easy")
    {
        difficultyPercentage = 50;
    }
    else if (difficultySetting == "Medium")
    {
        difficultyPercentage = 25;
    }
    else if (difficultySetting == "Hard")
    {
        difficultyPercentage = 5;
    }
    if ( percentRoll < difficultyPercentage ) {
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

void makeEnemyInventory(string enemy)
{
    countloops = 0;
    if (enemy == "wizard")
    {
       for (int i=0; i < 4; i++)
       {
           countloops++;
        for (int j = 0; j < 2; j++)
        {
            enemy_inv[i][j] = wizard_inv[i][j];
        }
       }
    }
    enemyInventorySize = countloops;
}

int hutGuyMoneybag = 1000;
const int MAX_HUTGUY_INV = 20;
int hutGuyItemCount = 10;
int hutGuy_inv[MAX_HUTGUY_INV][2] = {
    {0,1},
    {0,6},
    {0,11},
    {1,2},
    {1,4},
    {1,9},
    {1,10},
    {2,0},
    {2,3},
    {2,6}
};

void displayHutInventory()
{
    for (int i = 0; i < hutGuyItemCount; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                pos1 = hutGuy_inv[i][j];
            }
            else if (j == 1)
            {
                pos2 = hutGuy_inv[i][j];
                cout << "                    " << findItemName(pos1,pos2) << "\n";
            }
        }
    }
    cout << "\n";
}

int storeBuyMenu()
{
    int doneBuying = 0;
    while (doneBuying == 0)
    {
        system("clear");
        cout << menuBar;
        cout << "       Press '0' to return.\n";
        cout << "       Choose Item to Purchase:\n\n";
        int startNumber = 0;
        for (int i = 0; i < hutGuyItemCount; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                {
                    pos1 = hutGuy_inv[i][j];
                }
                else if (j == 1)
                {
                    pos2 = hutGuy_inv[i][j];
                    startNumber++;
                    cout << "             (" << startNumber << ") " << findItemName(pos1,pos2) << ": " << findItemPrice(pos1,pos2) << " GP" << "\n";
                }
            }
        }
        cout << "\n";
        cout << menuBar;
        cin >> userInput;
        if (userInput == 0)
        {
            doneBuying = 1;
            return 0;
        }
        int itemnumber = userInput - 1;
        pos1 = hutGuy_inv[itemnumber][0];
        pos2 = hutGuy_inv[itemnumber][1];
        item = findItemName(pos1,pos2);
        if (playerItemCount >= MAX_PLAYER_INV)
        {
            cout << "Inventory is Full\n";
            cout << "Press '1' to continue";
            cin >> userInput;
        }
        else if (findItemPrice(pos1,pos2) > moneybag)
        {
            cout << "Not enough money\n";
            cout << "Press '1' to continue";
            cin >> userInput;
        }
        else
        {
            buyItem(pos1,pos2,itemnumber);
        }
    }
}

int buyItem(int itemTable, int itemNumber, int invnumber)
{
    for (int i = invnumber; i < hutGuyItemCount + 1; i++ )
    {
        int movingI = i + 1;
        for (int j = 0; j < 2; j++)
        {
            hutGuy_inv[i][j] = hutGuy_inv[movingI][j];
        }
    }
    hutGuyItemCount = hutGuyItemCount - 1;
    moneybag = moneybag - findItemPrice(itemTable, itemNumber);
    addInventory(itemTable, itemNumber);
    xp = xp + findItemPrice(itemTable, itemNumber);
}

int storeSellMenu()
{
    int doneSelling = 0;
    while (doneSelling == 0)
    {
        system("clear");
        cout << menuBar;
        cout << "         Press '0' to return.\n";
        cout << "         Choose Item to Sell:\n\n";
        int startNumber = 0;
        for (int i = 0; i < playerItemCount; i++)
        {
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
                    cout << "            (" << startNumber << ") " << findItemName(pos1,pos2) << ": " << findItemValue(pos1,pos2) << " GP" << "\n";
                }
            }
        }
        cout << "\n";
        cout << menuBar;
        cin >> userInput;
        if (userInput == 0)
        {
            doneSelling = 1;
            return 0;
        }
        int itemnumber = userInput - 1;
        pos1 = player_inv[itemnumber][0];
        pos2 = player_inv[itemnumber][1];
        item = findItemName(pos1,pos2);
        if (hutGuyItemCount >= MAX_HUTGUY_INV)
        {
            cout << "Shop is full\n";
            cout << "Press '1' to continue";
            cin >> userInput;
        }
        else if (findItemValue(pos1,pos2) > hutGuyMoneybag)
        {
            cout << "Store doesn't have enough money\n";
            cout << "Press '1' to continue";
            cin >> userInput;
        }
        else
        {
            sellItem(pos1,pos2,itemnumber);
        }
    }
}
int sellItem(int itemTable, int itemNumber, int invnumber)
{
    hutGuy_inv[hutGuyItemCount][0] = itemTable;
    hutGuy_inv[hutGuyItemCount][1] = itemNumber;
    hutGuyItemCount++;
    dropItem(invnumber);
    hutGuyMoneybag = hutGuyMoneybag - findItemValue(itemTable, itemNumber);
    moneybag = moneybag + findItemValue(itemTable, itemNumber);
    xp = xp + findItemValue(itemTable, itemNumber);
}

int findItemPrice(int table, int itemNumber)
{
    int price;
    if (table == 0)
    {
        price = weapon_prop[itemNumber][5];
    }
    else if (table == 1)
    {
        price = armor_prop[itemNumber][4];
    }
    else if (table == 2)
    {
        price = consum_prop[itemNumber][6];
    }
    return price;
}

int findItemValue(int table, int itemNumber)
{
    int price = findItemPrice(table, itemNumber) / 2;
    return price;
}
void useItem(int itemNumber)
{
    xp = 5;
    playerHealth = playerHealth + consum_prop[itemNumber][1];
    playerDrunk = playerDrunk + consum_prop[itemNumber][3];
    playerMana = playerMana + consum_prop[itemNumber][2];
    if (playerHealth > 100)
    {
        playerHealth = 100;
    }
    if ((consum_prop[itemNumber][1] != 0) && (consum_prop[itemNumber][2] == 0) && (consum_prop[itemNumber][3] == 0))
    {
        userMessage = 2;
    }
    else if (consum_prop[itemNumber][1] == 0)
    {
        userMessage = 3;
    }
    else if (consum_prop[itemNumber][3] !=0)
    {
        userMessage = 4;
    }
}
void healthMessage()
{
    cout << "Health is now " << playerHealth << "\n";
}

void equipMessage()
{
    cout << lastEquipped << " has been equipped\n";
}

void magicMessage()
{
    cout << "Magic is now " << playerMana <<"\n";
}

void drunkMessage()
{
    cout << "Health is now " << playerHealth << "\n";
    cout << "Magic is " << playerMana << "\n";
    cout << "Innebriation is now " << playerDrunk << "\n";
}
