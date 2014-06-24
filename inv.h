#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
#include <cstdlib>
#include <string>

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
int itemUses;
int uses;
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
void addInventory(int table, int item, int itemUses);
void createItem();
void addPartyLiquor();
int euses;
int itemRoll = 0;
void checkForItem();
int debugInventory();
int inventoryCheck();
void displayInventory();
int findItemUses(int table, int itemNumber);
void displayHutInventory();
void makeEnemyInventory(string enemy);
void equipItem(int table, int itemNumber, int uses);
void equipWeapon(int table, int itemNumber, int uses);
void equipHelm(int table, int itemNumber, int uses);
int findItemPrice(int table, int itemNumber);
void equipPlate(int table, int itemNumber, int uses);
void equipGauntlets(int table, int itemNumber, int uses);
void equipBoots(int table, int itemNumber, int uses);
void dropItem(int itemNumber);
void clearPlayerInv();
int player_eweapon[1][3] = {9,9,9};
int player_ehelm[1][3] = {9,9,9};
int player_egauntlets[1][3] = {9,9,9};
int player_eboots[1][3] = {9,9,9};
int player_eplate[1][3] = {9,9,9};
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
    const int player_inv_col = 3;
    const int player_inv_row = MAX_PLAYER_INV;

    int player_inv[player_inv_row][player_inv_col];
#endif
