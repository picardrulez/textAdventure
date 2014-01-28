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
}
int monsterAttack(int speed, int attack)
{

    bool findhit = thacoRoll(playersAC, speed);
    if (findhit)
    {

        int damageDealt = damage(attack);
        system("clear");
        cout << menuBar << "\n\n";
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
        cout << "                   He missed!\n\n\n";
        cout << "              Press '1' to continue!\n\n\n\n";
        cout << menuBar;
        cin >> playerchoice;
    }
}

int playerAttack(int speed, int attack)
{
    bool findhit = thacoRoll(monsterAC, speed);
    if (findhit)
    {
        int damageDealt = damage(attack);
        system("clear");
        cout << menuBar << "\n\n";
        cout << "         You hit the monster for " << damageDealt << " damage!\n\n\n";
        monsterHealth = monsterHealth - damageDealt;
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
        cout << menuBar << "\n\n";
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
