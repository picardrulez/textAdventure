#include <string>
using namespace std;

int damage(int attack);
int findAttack(int itemNumber);

//fix monsterHealth so that level1.cpp is not calling it.  fix dat shit with an object or something
extern int monsterHealth;
void enemyDropItem(int itemNumber);

//same with this.  level1.cpp is using it
extern int monsterAC;
int lootEnemy(string enemy);
bool thacoRoll(int ac, int speed);
int monsterAttack(int speed, int attack, string enemyType);
int playerAttack(int speed, int attack, string enemyType);
int battle(int monsterspeed, int monsterattack, string enemyType);
