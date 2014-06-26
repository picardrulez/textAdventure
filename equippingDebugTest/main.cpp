#include <iostream>
#include <string>

using namespace std;

int player_inv[25][3] = {
    {0,0,50},
    {0,1,75},
    {0,2,100},
};

int player_eweapon[1][3] = {69,69,69};
int player_ehelm[1][3] = {9,9,9};
int player_egauntlets[1][3] = {9,9,9};
int player_eboots[1][3] = {9,9,9};
int player_eplate[1][3] = {9,9,9};
int equipMenu();
int pos1;
int pos2;
int displayEquipped();
string findItemName(int itemNumber, int table);
string item;
int userInput;
int playerinput;
void equipItem(int table, int itemNumber, int uses);
void dropItem(int itemNumber);
void equipWeapon(int table, int itemNumber, int uses);
int playerItemCount = 3;
int itemUses;
int etable = 0;
int eitemNumber = 0;
int euses = 0;
void addInventory(int table, int item, int itemUses);
void displayInventory();

string weapons[13] = {
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

int weapon_prop[13][6] = {
    {0, 5, 50, 6, 100, 3},
    {1, 11, 75, 4, 85, 7},
    {2, 17, 100, 3, 50, 10},
    {3, 25, 300, 1, 5, 15},
    {4, 8, 75, 8, 75, 5},
    {5, 15, 100, 6, 50, 9},
    {6, 23, 100, 5, 30, 12},
    {7, 30, 300, 4, 5, 17},
    {8, 12, 100, 10, 50, 7},
    {9, 18, 150, 8, 25, 11},
    {10, 27, 200, 7, 10, 15},
    {11, 40, 300, 6, 5, 20},
    {12, 5, 1, 2, 40, 2}
};

int main()
{
    bool stillActive = true;
    while (stillActive)
    {
        cout << "--------\n";
        displayEquipped();
        cout << "----------\n";
        displayInventory();
        cout << "1 - Equip Menu\n";
        cout << "0 - exit\n";
        cout << "------\n";
        cin >> playerinput;
        if (playerinput == 0)
        {
            stillActive = false;
        }
        else if (playerinput == 1)
        {
            equipMenu();
        }
    }
    return 0;
}









int equipMenu()
{
    cout << "starting equipMenu function\n";
    cout << "playerItemCount is " << playerItemCount << "\n";
    int doneEquiping = 0;
    while (doneEquiping == 0)
    {
        cout << "Press '0' to return.\n";
        cout << " Choose Item to equip / use:\n\n";
        int startNumber = 0;
        for (int i = 0; i < playerItemCount;  i++)
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
//                    cout << "about to put value in itemUses.  Current value is " << itemUses << "\n";
//                    itemUses = player_inv[i][j];
//                    cout << "new value for itemUses is now " << itemUses <<"\n";
                    startNumber++;
                    cout << "    (" << startNumber << ") "  << findItemName(pos1, pos2) << "\n";
                }
            }
        }
        cout << "\n";
        cout << "------------";
        cin >> userInput;
        if (userInput == 0)
        {
            doneEquiping = 1;
            return 0;
        }
        int itemNumber = userInput - 1;
        pos1 = player_inv[itemNumber][0];
        pos2 = player_inv[itemNumber][1];
        cout << "defining itemUses variable.  current value is " << itemUses << "\n";
        int itemUses = player_inv[itemNumber][2];
        cout << "itemUses value is now " << itemUses << "\n";
        string item = findItemName(pos2, pos2);
        cout << "sending itemUses to equipItem().  current value is  " << itemUses << "\n";
        equipItem(pos1,pos2,itemUses);
        dropItem(itemNumber);
    }
    cout << "ending equipMenu()";
}

void equipItem(int table, int itemNumber, int uses)
{
    cout << "starting equipItem().  The uses value I received is " << uses << "\n";
    equipWeapon(table, itemNumber, uses);
}

void equipWeapon(int table, int itemNumber, int uses)
{
    cout << "starting equipWeapon().  The uses value I received is " << uses << "\n";
    if (player_eweapon[0][0] != 69)
    {
        etable = player_eweapon[0][0];
        eitemNumber = player_eweapon[0][1];
        cout << "creating euses variable.  The current value is" << euses << "\n";
        euses = player_eweapon[0][2];
        cout << "The new value of euses is" << euses << "\n";
        addInventory(etable, eitemNumber, euses);
    }
    player_eweapon[0][0] = table;
    player_eweapon[0][1] = itemNumber;
    cout << "makein player_eweapon uses equal to uses variable which is " << uses << "\n";
    player_eweapon[0][2] = uses;
    cout << "player_eweapon[0][2] is now " << player_eweapon[0][2] << "\n";
    cout << "ending equipWeapon()\n";
}

void dropItem(int itemNumber)
{
    for (int i = itemNumber; i < playerItemCount; i++ )
    {
        int movingI = i + 1;
        for (int j = 0; j < 2; j++)
        {
            player_inv[i][j] = player_inv[movingI][j];
        }
    }
    playerItemCount = playerItemCount - 1;
}

void addInventory(int table, int item, int itemUses)
{
    cout << "starting addInventory().  The itemUses I received is " << itemUses << "\n";
    if (playerItemCount < 25 )
    {
        player_inv[playerItemCount][0] = table;
        player_inv[playerItemCount][1] = item;
        cout << "making player_inv uses equal to itemUses which is " << itemUses << "\n";
        player_inv[playerItemCount][2] = itemUses;
        cout << "playerItemCount is " << playerItemCount << "\n";
        cout << "player_inv[playerItemCount][2] is now " << player_inv[playerItemCount][2] << "\n";
        playerItemCount++;
        cout << "playerItemCount is " << playerItemCount << "\n";
    }
    else
    {
        cout << "Inventory is full.";
    }
    cout << "ending addInventory()";
}

void displayInventory()
{
    cout << "starting displayInventory()\n";
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
                cout << "         " << "Item Location:  player_inv[" << pos1 << "][" << pos2 << "]\n";
                cout << "         " << "Uses Location:  player_inv[" << i << "][" << j <<"]\n";
                cout << "number of uses of following item coming from itemUses variable which is currently " << itemUses << "\n";
                cout << "         " << findItemName(pos1, pos2) << " Uses " << itemUses << "\n";
                cout << "//////////\n";
            }
        }
    }
    cout << "\n";
    cout << "ending displayInventory()";
}

string findItemName(int table, int itemNumber)
{
    item = weapons[itemNumber];
    return item;
}

int displayEquipped()
{
    cout << "     Weapon:   ";
    pos1 = player_eweapon[0][0];
    pos2 = player_eweapon[0][1];
    itemUses = player_eweapon[0][2];
    if (pos1 == 69)
    {
        cout << "\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item<< "    uses:   " << itemUses << "\n";
    }
}
