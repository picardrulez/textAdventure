#include "inv.h"
#include "enemies.h"
#include "menus.h"
#include "battle.h"

int madechoice = 0;
int xp = 0;
int playerchoice = 0;
int monsterHealth = 0;
int monsterAC = 0;
int battle(int monsterspeed, int monsterattack, string enemyType)
{
    int battlerun = 1;
    //Battle Loop
    while (battlerun == 1)
    {
        madechoice = 0;
        while (madechoice == 0)
        {
            clearScreen();
	    //Main Battle Menu
            cout << menuBar;
            cout << "       " << enemyType << "Battle \n\n";
            displayEnemy(enemyType);
//	    healthMessage();
//	    magicMessage();
	    drunkMessage();
            cout << "Your attack is " << playersAttack << "\n";
            cout << "Your speed  is " << playersSpeed << "\n";
            cout << "Your AC is " << playersAC << "\n";
            cout << "           (1) Attack\n";
            cout << "           (2) Item Menu\n";
            cout << "           (3) Run Away\n\n";
            cout << menuBar;
            cin >> playerchoice;
            if (playerchoice == 2)
            {
                itemMenu();
            }
            else if (playerchoice == 3)
            {
                return 0;
            }
            else
            {
                madechoice = 1;
            }
        }
	//Checks if player's alive after player attack function
        bool stillAlive = playerAttack(playersSpeed, playersAttack, enemyType);
        if (stillAlive == false)
        {
            battlerun = 0;
            return 0;
        }
	//Checks if monster's alive after monster attack function
        stillAlive = monsterAttack(monsterspeed, monsterattack, enemyType);
        if (stillAlive == false)
        {
            battlerun = 0;
            return 1;
        }
    }
}
//monster Attack function.  determines if monster hits and how much damage is done
int monsterAttack(int speed, int attack, string enemyType)
{

    //findhit is a booleon determined by whether or not thac0 roll is successfl
    bool findhit = thacoRoll(playersAC, speed);
    if (findhit)
    {

	//damageDealt is the output of the damage function which is then modified by the game's difficulty setting
        int damageDealt = damage(attack);
        if ((difficultySetting == "Medium") && (damageDealt < 100))
        {
            damageDealt = damageDealt + 10;
        }
        else if ((difficultySetting == "Medium") && (damageDealt >=100))
        {
            damageDealt = damageDealt * 1.5;
        }
        else if ((difficultySetting == "Hard") && (damageDealt < 100))
        {
            damageDealt = damageDealt + 25;
        }
        else if ((difficultySetting == "Hard") && (damageDealt >=100))
        {
            damageDealt = damageDealt * 2.5;
        }
        clearScreen();
        cout << menuBar << "\n\n";
        displayEnemy(enemyType);
        cout << "             You get hit for "<< damageDealt << " damage!\n\n";
        playerHealth = playerHealth - damageDealt;
	//on successful hit by monster a use is taken away from a random armor piece on the player
        srand(static_cast<unsigned int>(time(0)));
        int randomNumber = rand();
        int armorSelection = (randomNumber % 4);
        if (armorSelection == 0)
        {
            itemUses = player_ehelm[0][2];
            player_ehelm[0][2] = itemUses - 1;
            if (player_ehelm[0][2] = 0)
            {
                cout << findItemName(player_ehelm[0][0], player_ehelm[0][1]) << " has been destroyed!\n";
                player_ehelm[0][0] = 9;
                player_ehelm[0][1] = 9;
                player_ehelm[0][2] = 9;
            }
        }
        else if (armorSelection == 1)
        {
            itemUses = player_eplate[0][2];
            player_eplate[0][2] = itemUses - 1;
            if (player_eplate[0][2] == 0)
            {
                cout << findItemName(player_eplate[0][0], player_eplate[0][1]) << " has been destroyed!\n";
                player_eplate[0][0] = 9;
                player_eplate[0][1] = 9;
                player_eplate[0][2] = 9;
            }
        }
        else if (armorSelection == 2)
        {
            itemUses = player_egauntlets[0][2];
            player_egauntlets[0][2] = itemUses - 1;
            if (player_egauntlets[0][2] = 0)
            {
            cout << findItemName(player_egauntlets[0][0], player_egauntlets[0][1]) << " has been destroyed!\n";
            player_egauntlets[0][0] = 9;
            player_egauntlets[0][1] = 9;
            player_egauntlets[0][2] = 9;
            }
        }
        else if (armorSelection == 3)
        {
            itemUses = player_eboots[0][2];
            player_eboots[0][2] = itemUses;
            if (player_eboots[0][2] = 0)
            {
                cout << findItemName(player_eboots[0][0], player_eboots[0][1]) << " has been destroyed!\n";
                player_eboots[0][0] = 9;
                player_eboots[0][1] = 9;
                player_eboots[0][2] = 9;
            }
        }
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
        clearScreen();
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
        clearScreen();
        cout << menuBar << "\n\n";
        displayEnemyHit(enemyType);
        cout << "         You hit the monster for " << damageDealt << " damage!\n\n\n";
        xp = xp + damageDealt;
        itemUses = player_eweapon[0][2];
        player_eweapon[0][2] = itemUses - 1;
        if (player_eweapon[0][2] == 0)
        {
            cout << findItemName(player_eweapon[0][0], player_eweapon[0][1]) << " has been destroyed!\n";
            player_eweapon[0][0] = 9;
            player_eweapon[0][1] = 9;
            player_eweapon[0][2] = 9;
            playersAttack = 1;
        }
        monsterHealth = monsterHealth - damageDealt;
        if (monsterHealth <= 0)
        {
            madechoice = 0;
            xp = xp + 100;
            while (madechoice == 0)
            {
                clearScreen();
                cout << menuBar << "\n\n";
                cout << "             You defeated him!\n";
                cout << "          Press '1' to continue!\n";
                cout << "          Press '2' to loot for items!\n\n\n";
                cout << menuBar;
                cin >> playerchoice;
                if (playerchoice == 2)
                {
                    madechoice = lootEnemy(enemyType);
                    return false;
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
        clearScreen();
        cout << menuBar << "\n\n";
        displayEnemy(enemyType);
        cout << "                   You missed!\n\n\n";
        cout << "              Press '1' to continue!\n\n\n\n";
        cout << menuBar;
        cin >> playerchoice;
    }
}
//determines damage done on successful attack
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

//determines if character hits. classic 2e "to hit armor class 0"
bool thacoRoll(int ac, int speed)
{
    int thaco = (30 - speed - ac);
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    int thacoRoll = (randomNumber % 20);
    if (thacoRoll < thaco)
    {
        return true;
        xp = xp + 1;
    }
    else
    {
        return false;
    }
}

//creates an inventory for the enemy and then gives and option to the player to loot them.
int lootEnemy(string enemy)
{
    makeEnemyInventory(enemy);
    int doneLooting = 0;
    while (doneLooting == 0)
    {
        clearScreen();
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
            return 1;
        }
        else if (userInput > 0)
        {
            itemNumber = userInput - 1;
            pos1 = enemy_inv[itemNumber][0];
            pos2 = enemy_inv[itemNumber][1];
            itemUses = (findItemUses(pos1,pos2) / 2);
            addInventory(pos1,pos2, itemUses);
            enemyDropItem(itemNumber);
        }
    }
}

//managing enemy's inventory
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

