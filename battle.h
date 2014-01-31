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

int battle(int monsterspeed, int monsterattack, int playerspeed, int playerattack, string enemyType)
{
    int battlerun = 1;
    while (battlerun == 1)
    {
        stillAlive = playerAttack(playerspeed, playerattack, enemyType);
        if (stillAlive == false)
        {
            battlerun = 0;
            return 0;
        }
        stillAlive = monsterAttack(monsterspeed, monsterattack, enemyType);
        if (stillAlive == false)
        {
            battlerun = 0;
            return 1;
        }
    }
}
int monsterAttack(int speed, int attack, string enemyType)
{

    bool findhit = thacoRoll(playersAC, speed);
    if (findhit)
    {

        int damageDealt = damage(attack);
        system("clear");
        cout << menuBar << "\n\n";
        displayEnemy(enemyType);
        cout << "             You get hit for "<< damageDealt << " damage!\n\n";
        playerHealth = playerHealth - damageDealt;
        cout << "               Health is at "<< playerHealth << "!\n\n";
        if (playerHealth <= 0)
        {
            cout << "             Oh no!  You died!\n";
            cout << "      Press '1' to return to the Main Menu\n\n\n";
            cout << menuBar;
            cin >> playerchoice;
            return false;
        }
        cout << "              Press '1' to continue!\n\n\n";
        cout << menuBar;
        cin >> playerchoice;
    }
    else
    {
        system("clear");
        cout << menuBar << "\n\n";;
        displayEnemy(enemyType);
        cout << "                   He missed!\n\n\n";
        cout << "              Press '1' to continue!\n\n\n\n";
        cout << menuBar;
        cin >> playerchoice;
    }
}

int playerAttack(int speed, int attack, string enemyType)
{
    bool findhit = thacoRoll(monsterAC, speed);
    if (findhit)
    {
        int damageDealt = damage(attack);
        system("clear");
        cout << menuBar << "\n\n";
        displayEnemyHit(enemyType);
        cout << "         You hit the monster for " << damageDealt << " damage!\n\n\n";
        monsterHealth = monsterHealth - damageDealt;
        if (monsterHealth <= 0)
        {
            madechoice = 0;
            while (madechoice == 0)
            {
                system("clear");
                cout << menuBar << "\n\n";
                cout << "             You defeated him!\n";
                cout << "          Press '1' to continue!\n";
                cout << "          Press '2' to loot for items!\n\n\n";
                cout << menuBar;
                cin >> playerchoice;
                if (playerchoice == 2)
                {
                    madechoice = lootEnemy(enemyType);
                }
                else if (playerchoice == 1)
                {
                    madechoice = 1;
                    return false;
                }
            }
        }
        cout << "              Press '1' to continue!\n\n\n\n";
        cout << menuBar;
        cin >> playerchoice;
    }
    else
    {
        system("clear");
        cout << menuBar << "\n\n";
        displayEnemy(enemyType);
        cout << "                   You missed!\n\n\n";
        cout << "              Press '1' to continue!\n\n\n\n";
        cout << menuBar;
        cin >> playerchoice;
    }
}
int damage(int attack)
{
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
     int damage = (randomNumber % attack + 1);
    return damage;
}

int findAttack(int itemNumber)
{
    int attack = weapon_prop[itemNumber][2];
    return attack;
}

bool thacoRoll(int ac, int speed)
{
    int thaco = (30 - speed - ac);
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    int thacoRoll = (randomNumber % 20);
    if (thacoRoll < thaco)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int lootEnemy(string enemy)
{
    makeEnemyInventory(enemy);
    int doneLooting = 0;
    while (doneLooting == 0)
    {
        system("clear");
        cout << menuBar;
        cout << "      Press '0' to exit\n";
        cout << "    Choose Item to loot:\n\n";
        int startNumber = 0;
        for (int i = 0; i < enemyInventorySize; i++)
        {
            string tableName;
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                {
                    pos1 = enemy_inv[i][j];
                }
                else if (j == 1)
                {
                    pos2 = enemy_inv[i][j];
                    startNumber++;
                    cout << "               (" << startNumber << ")  " << findItemName(pos1,pos2) << "\n";
                }
            }
        }
        cout << "\n";
        cout << menuBar;
        cin >> userInput;
        if (userInput == 0)
        {
            doneLooting = 1;
        }
        else if (userInput > 0)
        {
            itemNumber = userInput - 1;
            pos1 = enemy_inv[itemNumber][0];
            pos2 = enemy_inv[itemNumber][1];
            addInventory(pos1,pos2);
            enemyDropItem(itemNumber);
        }
    }
}

void enemyDropItem(int itemNumber)
{
   for (int i = itemNumber; i < enemyInventorySize + 1; i++ )
   {
       int movingI = i + 1;
       for (int j = 0; j < 2; j++)
       {
           enemy_inv[i][j] = enemy_inv[movingI][j];
       }
   }
   enemyInventorySize = enemyInventorySize - 1;
}
