#ifndef HEADER_H_
#define HEADER_H_
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int menuChoice;
string menuBar = "|--------------------------------------------------|\n\n";
string difficultySetting = "Medium";
string playerSelection;
bool menuSelection = false;
int xp;
int madechoice = 0;
int playerMana;
int mainMenu();
int settings();
int credits();
int difficulty();
int itemMenu();
int equipMenu();
int equipmentMenu();
int controls();
int dropItemMenu();
int statusMenu();
void gameMenu();
int displayEquipped();
void displayInventory();
int inventoryMenu();
int moneybag;
int playersHelmAC = 0;
int playersGauntletAC = 0;                                                     
int playersPlateAC = 0;
int playersBootAC = 0;
int playersAC = 0;
int playersSpeed = 1;
int playersAttack = 1;
int playerDrunk = 0;
int playerHealth = 100;
#endif
