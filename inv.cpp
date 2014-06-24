#include "menus.h"
#include "inv.h"

//Arrays for player's equipped items


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
    itemUses = player_eweapon[0][2];
    if (pos1 == 9)
    {
        cout << "\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item <<  "     uses:  " << itemUses << "\n";
    }
    cout << "           Helm:  ";
    pos1 = player_ehelm[0][0];
    pos2 = player_ehelm[0][1];
    itemUses = player_ehelm[0][2];
    if (pos1 == 9)
    {
        cout << "\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "     uses:  " << itemUses << "\n";
    }
    cout << "           Breast plate:  ";
    pos1 = player_eplate[0][0];
    pos2 = player_eplate[0][1];
    itemUses = player_eplate[0][2];
    if (pos1 == 9)
    {
        cout << "\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "     uses:  " << itemUses << "\n";
    }
    cout << "           Gauntlets:  ";
    pos1 = player_egauntlets[0][0];
    pos2 = player_egauntlets[0][1];
    itemUses = player_egauntlets[0][2];
    if (pos1 == 9)
    {
        cout << "\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "     uses:  " << itemUses << "\n";
    }
    cout << "           Boots:  ";
    pos1 = player_eboots[0][0];
    pos2 = player_eboots[0][1];
    itemUses = player_eboots[0][2];
    if (pos1 == 9)
    {
        cout << "\n\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "     uses:  " << itemUses << "\n\n";
    }

}

void displayInventory()
{
    for (int i = 0; i < playerItemCount; i++ )
    {
        string tableName;
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                pos1 = player_inv[i][j];
            }
            else if (j == 1)
            {
               pos2 = player_inv[i][j];
            }
            else if (j == 2)
            {
                itemUses = player_inv[i][j];
                cout << "                 " << findItemName(pos1, pos2) << " Uses " << itemUses << "\n";
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

void addInventory(int table, int item, int itemUses)
{
    if (playerItemCount < MAX_PLAYER_INV )
    {
    player_inv[playerItemCount][0] = table;
    player_inv[playerItemCount][1] = item;
    player_inv[playerItemCount][2] = itemUses;
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
            for (int j = 0; j < 3; j++)
            {
                if (j == 0)
                {
                    pos1 = player_inv[i][j];
                }
                else if (j == 1)
                {
                    pos2 = player_inv[i][j];
                }
                else if (j == 2)
                {
                    itemUses = player_inv[i][j];
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
        equipItem(pos1,pos2, itemUses);
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
void equipItem(int table, int itemNumber, int uses)
{
    item = findItemName(table, itemNumber);
    lastEquipped = item;
    userMessage = 1;
    if (item.find("Sword") != string::npos || item.find("Axe") != string::npos || item.find("Hammer") != string::npos || item.find("Dart") != string::npos )
    {
        equipWeapon(table, itemNumber, uses);
    }
    else if (item.find("Helm") != string::npos)
    {
        equipHelm(table, itemNumber, uses);
    }
    else if (item.find("Gauntlets") != string::npos)
    {
        equipGauntlets(table, itemNumber, uses);
    }
    else if (item.find("Boots") != string::npos)
    {
        equipBoots(table, itemNumber, uses);
    }
    else if (item.find("Plate") != string::npos)
    {
        equipPlate(table, itemNumber, uses);
    }
}
void equipWeapon(int table, int itemNumber, int uses)
{
    if (player_eweapon[0][0] != 9)
    {
        etable = player_eweapon[0][0];
        eitemNumber = player_eweapon[0][1];
        euses = player_eweapon[0][2];
        addInventory(etable, eitemNumber, euses);
    }
    player_eweapon[0][0] = table;
    player_eweapon[0][1] = itemNumber;
    player_eweapon[0][2] = uses;
    playersAttack = weapon_prop[itemNumber][1];
    playersSpeed = weapon_prop[itemNumber][3];

}

void equipHelm(int table, int itemNumber, int uses)
{
    if (player_ehelm[0][0] != 9)
    {
        etable = player_ehelm[0][0];
        eitemNumber = player_ehelm[0][1];
        euses = player_ehelm[0][2];
        addInventory(etable, eitemNumber, euses);
    }
    player_ehelm[0][0] = table;
    player_ehelm[0][1] = itemNumber;
    player_ehelm[0][2] = uses;
    playersHelmAC = armor_prop[itemNumber][1];
    playersAC = playersHelmAC + playersGauntletAC + playersPlateAC + playersBootAC;
}

void equipPlate(int table, int itemNumber, int uses)
{
    if (player_eplate[0][0] != 9)
    {
        etable = player_eplate[0][0];
        eitemNumber = player_eplate[0][1];
        euses = player_eplate[0][2];
        addInventory(etable, eitemNumber, euses);
    }
    player_eplate[0][0] = table;
    player_eplate[0][1] = itemNumber;
    player_eplate[0][2] = uses;
    playersPlateAC = armor_prop[itemNumber][1];
    playersAC = playersHelmAC + playersGauntletAC + playersPlateAC + playersBootAC;

}

void equipGauntlets(int table, int itemNumber, int uses)
{
    if (player_egauntlets[0][0] != 9)
    {
        etable = player_egauntlets[0][0];
        eitemNumber = player_egauntlets[0][1];
        euses = player_egauntlets[0][2];
        addInventory(etable, eitemNumber, euses);
    }
    player_egauntlets[0][0] = table;
    player_egauntlets[0][1] = itemNumber;
    player_egauntlets[0][2] = uses;
    playersGauntletAC = armor_prop[itemNumber][1];
    playersAC = playersHelmAC + playersGauntletAC + playersPlateAC + playersBootAC;
}

void equipBoots(int table, int itemNumber, int uses)
{
    if (player_eboots[0][0] != 9)
    {
        etable = player_eboots[0][0];
        eitemNumber = player_eboots[0][1];
        euses = player_eboots[0][2];
        addInventory(etable, eitemNumber, euses);
    }
    player_eboots[0][0] = table;
    player_eboots[0][1] = itemNumber;
    player_eboots[0][2] = uses;
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
            itemUses = findItemUses(itemType, itemRoll);
            addInventory(itemType, itemRoll, itemUses);
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
    uses = findItemUses(itemTable, itemNumber);
    addInventory(itemTable, itemNumber, uses);
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

int findItemUses(int table, int itemNumber)
{
    if (table == 0)
    {
        itemUses = weapon_prop[itemNumber][2];
    }
    else if (table == 1)
    {
        itemUses = armor_prop[itemNumber][2];
    }
    else if (table == 2)
    {
        itemUses = consum_prop[itemNumber][4];
    }
    return itemUses;
}
