#include <string>
using namespace std;

int damage(int attack);
int findAttack(int itemNumber);
extern int monsterHealth;
extern int playerchoice;
void enemyDropItem(int itemNumber);
extern int monsterAC;
extern bool stillAlive;
int lootEnemy(string enemy);
bool thacoRoll(int ac, int speed);
int monsterAttack(int speed, int attack, string enemyType);
int playerAttack(int speed, int attack, string enemyType);
int battle(int monsterspeed, int monsterattack, int playerspeed, int playerattack, string enemyType);
