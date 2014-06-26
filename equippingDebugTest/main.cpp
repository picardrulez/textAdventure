

#include <iostream>
#include <string>

using namespace std;

int player_inv[25][3] = {
    {0,0,50},
    {0,1,75},
    {0,2,100},
    {0,3,300},
    {0,4,75},
    {0,5,100},
    {0,6,250},
    {0,7,500}
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
int playerItemCount = 8;
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
                    itemUses = player_inv[i][j];
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
        int itemUses = player_inv[itemNumber][2];
        string item = findItemName(pos2, pos2);
        cout << "itemUses is " << itemUses << "\n";
        equipItem(pos1,pos2,itemUses);
        dropItem(itemNumber);
    }
}

void equipItem(int table, int itemNumber, int uses)
{
    equipWeapon(table, itemNumber, uses);
}

void equipWeapon(int table, int itemNumber, int uses)
{
    if (player_eweapon[0][0] != 69)
    {
        etable = player_eweapon[0][0];
        eitemNumber = player_eweapon[0][1];
        euses = player_eweapon[0][2];
        addInventory(etable, eitemNumber, euses);
    }
    player_eweapon[0][0] = table;
    player_eweapon[0][1] = itemNumber;
    player_eweapon[0][2] = uses;
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

void addInventory(int table, int item, int itemUses)
{
    if (playerItemCount < 25 )
    {
        player_inv[playerItemCount][0] = table;
        player_inv[playerItemCount][1] = item;
        player_inv[playerItemCount][2] = itemUses;
        playerItemCount++;
    }
    else
    {
        cout << "Inventory is full.";
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
                cout << "         " << "Item Location:  player_inv[" << pos1 << "][" << pos2 << "]\n";
                cout << "         " << "Uses Location:  player_inv[" << i << "][" << j <<"]\n";
                cout << "         " << findItemName(pos1, pos2) << " Uses " << itemUses << "\n";
                cout << "//////////\n";
            }
        }
    }
    cout << "\n";
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
