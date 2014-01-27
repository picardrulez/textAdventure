using namespace std;

int damage(int attack);
int findAttack(int itemNumber);
int monsterHealth;
int playerchoice;
int monsterAC;
bool stillAlive = true;
bool thacoRoll(int ac, int speed);
int monsterAttack(int speed, int attack);
int playerAttack(int speed, int attack);
int battle(int monsterspeed, int monsterattack, int playerspeed, int playerattack);

int battle(int monsterspeed, int monsterattack, int playerspeed, int playerattack)
{
    debugopen();
    debugfile << "battle function started\n";
    debugclose();
    int battlerun = 1;
    while (battlerun == 1)
    {
        stillAlive = playerAttack(playerspeed, playerattack);
        if (stillAlive == false)
        {
            battlerun = 0;
            return 0;
        }
        stillAlive = monsterAttack(monsterspeed, monsterattack);
        if (stillAlive == false)
        {
            battlerun = 0;
            return 1;
        }
    }
    debugopen();
    debugfile << "battle function closed \n";
    debugclose();
}
int monsterAttack(int speed, int attack)
{
    debugopen();
    debugfile << "enemy attack started\n";
    debugclose();

    bool findhit = thacoRoll(playersAC, speed);
    if (findhit)
    {
        debugopen();
        debugfile << "enemy hits \n";
        debugclose();

        int damageDealt = damage(attack);
        debugopen();
        debugfile << "enemy does " << damageDealt << " damage\n";
        debugclose();
        playerHealth -= damageDealt;
        debugopen();
        debugfile << "player health is " << playerHealth << "\n";
        debugclose();
        system("clear");
        cout << menuBar << "\n\n";
        cout << "             You get hit for "<< damageDealt << " damage!\n\n";
        cout << "               Health is at "<< playerHealth << "!\n\n";
        if (playerHealth <= 0)
        {
            debugopen();
            debugfile << "player is dead\n";
            debugclose();
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
        debugopen();
        debugfile << "enemy attack misses\n";
        debugclose();
        system("clear");
        cout << menuBar << "\n\n";;
        cout << "                   He missed!\n\n\n";
        cout << "              Press '1' to continue!\n\n\n\n";
        cout << menuBar;
        cin >> playerchoice;
    }
}

int playerAttack(int speed, int attack)
{
    debugopen();
    debugfile << "player attack started\n";
    debugclose();
    bool findhit = thacoRoll(monsterAC, speed);
    if (findhit)
    {
        debugopen();
        debugfile << "player attack hits\n";
        debugclose();
        int damageDealt = damage(attack);
        debugopen();
        debugfile << "damage dealt is " << damageDealt << "\n";
        debugclose();
        monsterHealth -= damageDealt;
        debugopen();
        debugfile << "enemy health is " << monsterHealth << "\n";
        debugclose();
        system("clear");
        cout << menuBar << "\n\n";
        cout << "         You hit the monster for " << damageDealt << " damage!\n\n\n";
        if (monsterHealth <= 0)
        {
            cout << "             You defeated him!\n";
            cout << "          Press '1' to continue!\n\n\n\n";
            cout << menuBar;
            cin >> playerchoice;
            return false;
        }
        cout << "              Press '1' to continue!\n\n\n\n";
        cout << menuBar;
        cin >> playerchoice;
    }
    else
    {
        system("clear");
        debugopen();
        debugfile << "player attack misses\n";
        debugclose();
        cout << menuBar << "\n\n";
        cout << "                   You missed!\n\n\n";
        cout << "              Press '1' to continue!\n\n\n\n";
        cout << menuBar;
        cin >> playerchoice;
    }
    debugopen();
    debugfile << "player attack ended\n";
    debugclose();
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
    debugopen();
    debugfile << "attack property is " << attack << "\n";
    debugclose();
    return attack;
}

bool thacoRoll(int ac, int speed)
{
    debugopen();
    debugfile << "attack roll has started \n";
    debugfile << "attack speed value is " << speed << "\n";
    debugfile << "AC is " << ac << "\n";
    debugclose();
    int thaco = (30 - speed - ac);
    debugopen();
    debugfile << "needs to roll under " << thaco << " to hit\n";
    debugclose();
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    int thacoRoll = (randomNumber % 20);
    debugopen();
    debugfile << "roll is " << thacoRoll << "\n";
    debugclose();
    if (thacoRoll < thaco)
    {
        debugopen();
        debugfile << "attack roll has ended\n";
        debugclose();
        return true;
    }
    else
    {
        debugopen();
        debugfile << "attack roll has ended\n";
        debugclose();
        return false;
    }
}
