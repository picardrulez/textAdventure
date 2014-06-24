#ifndef HEADER_H_
#define HEADER_H_
#include <string>
using namespace std;

int damage(int attack);
int findAttack(int itemNumber);
int monsterHealth;
int playerchoice;
void enemyDropItem(int itemNumber);
int monsterAC;
bool stillAlive = true;
int lootEnemy(string enemy);
bool thacoRoll(int ac, int speed);
int monsterAttack(int speed, int attack, string enemyType);
int playerAttack(int speed, int attack, string enemyType);
int battle(int monsterspeed, int monsterattack, int playerspeed, int playerattack, string enemyType);
#endif
