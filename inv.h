#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Management System for Weapon Items
//int moneybag = 0;
extern string playerInput;
extern int userInput;
extern int itemType;
extern int enemy_inv[4][2]; 
extern int userMessage;
extern int itemNumber;
extern int enemyInventorySize;
extern int percentRoll;
extern int itemUses;
extern int uses;
extern int doneEquiping;
void equipMessage();
void healthMessage();
void magicMessage();
void drunkMessage();
int findItemValue(int table, int itemNumber);
extern int countloops;
extern int pos1;
int sellItem(int itemTable, int itemNumber, int invnumber);
extern int pos2;
int storeSellMenu();
int buyItem(int itemTable, int itemNumber, int invnumber);
void useItem(int itemNumber);
extern int etable;
int storeBuyMenu();
extern int eitemNumber;
extern string lastEquipped;
string findItemName(int itemNumber, int table);
extern string selection;
extern string item;
void addInventory(int table, int item, int itemUses);
extern void createItem();
void addPartyLiquor();
extern int euses;
extern int itemRoll;
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
extern void clearPlayerInv();
extern int player_eweapon[1][3]; 
extern int player_ehelm[1][3];
extern int player_egauntlets[1][3];
extern int player_eboots[1][3];
extern int player_eplate[1][3];
extern int wizard_inv[4][2];

const int NUM_WEAPONS = 13;
extern string weapons[NUM_WEAPONS];

const int weapon_prop_col = 6;
const int weapon_prop_row = NUM_WEAPONS;
extern int weapon_prop[weapon_prop_row][weapon_prop_col];
//Management System for Armor Items
const int NUM_ARMOR = 13;
extern string inv_armor[NUM_ARMOR];

const int armor_prop_col = 5;
const int armor_prop_row = NUM_ARMOR;
extern int armor_prop[armor_prop_row][armor_prop_col];

const int NUM_CONSUM = 10;
extern string inv_consum[NUM_CONSUM];
const int consum_prop_col = 7;
const int consum_prop_row = NUM_CONSUM;
extern int consum_prop[consum_prop_row][consum_prop_col]; 

//Array for maintaining the player's inventory.
extern int playerItemCount;
const int MAX_PLAYER_INV = 25;
const int player_inv_col = 3;
const int player_inv_row = MAX_PLAYER_INV;
extern int player_inv[player_inv_row][player_inv_col];
