#ifndef HEADER_H_
#define HEADER_H_
#include <string>

using namespace std;
int enemy;
int enemyInfo[3] = {0,0,0};
void enemyWizard();
void displayEnemy(string enemyType);
void displayEnemyShift(string enemyType);
void displayEnemyHit(string enemyType);
#endif
