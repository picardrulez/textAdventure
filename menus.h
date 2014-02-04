using namespace std;

int menuChoice = 0;
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

int mainMenu()
{
    madechoice = 0;
    while (madechoice == 0)
    {
        cout << menuBar;
        cout << "         Welcome to Geoff's Text Adventure!\n\n\n";
        if (xp != 0)
        {
            cout << "        Previous Experience Points was:  " << xp << "\n\n";
        }
        cout << "                   (1) Start Game\n";
        cout << "                   (2) Settings\n";
        cout << "                   (3) Credits\n";
        cout << "                   (4) Quit\n\n\n";
        cout << menuBar;
        cin >> menuChoice;
        do
        {
            if (menuChoice == 1)
            {
                system("clear");
                madechoice = 1;
                return 1;
            }
            else if (menuChoice == 2)
            {
                system("clear");
                madechoice = settings();
            }
            else if (menuChoice == 3)
            {
                system("clear");
                credits();
            }
            else if (menuChoice == 4)
            {
                system("clear");
                madechoice = 1;
                return 0;
            }
            else
            {
                cout << menuChoice << " is Not a valid entry\n";
                cout << "Press 1, 2, 3, or 4\n";
                cin >> menuChoice;
                menuSelection = true;
            }
        } while (menuSelection);
    }
}

int settings()
{
    while (madechoice == 0)
    {
        cout << menuBar;
        cout << "                     Settings\n\n\n";
        cout << "                  (1) Difficulty\n";
        cout << "                  (2) Controls\n";
        cout << "                  (3) Return\n\n\n\n";
        cout << menuBar;
        cin >> menuChoice;
        do
        {
            if (menuChoice == 1)
            {
                system("clear");
                madechoice = difficulty();
            }
            else if (menuChoice == 2)
            {
                system("clear");
                madechoice = controls();
            }
            else if (menuChoice == 3)
            {
                system("clear");
                madechoice = 1;
                return 0;
            }
            else
            {
                cout << menuChoice << "is not a valid entry\n";
                cout << "Enter 1, 2, or 3\n";
                cin >> menuChoice;
                menuSelection = true;
            }
        } while (menuSelection);
    }
}

int difficulty()
{
    while (madechoice == 0)
    {
        cout << menuBar;
        cout << "                   Difficulty\n\n";
        cout << "                   (1) Easy\n";
        cout << "                   (2) Medium\n";
        cout << "                   (3) Hard\n";
        cout << "                   (4) Return\n\n";
        cout << "           Current difficulty is set to " <<  difficultySetting << "\n\n";
        cout << menuBar;
        cin >> menuChoice;
        do
        {
            if (menuChoice == 1)
            {
                system("clear");
                difficultySetting = "Easy";
            }
            else if (menuChoice == 2)
            {
                system("clear");
                difficultySetting = "Medium";
            }
            else if (menuChoice == 3)
            {
                system("clear");
                difficultySetting = "Hard";
            }
            else if (menuChoice == 4)
            {
                system("clear");
                madechoice = 1;
                return 0;
            }
            else
            {
                cout  << menuChoice << " is not a valid entry\n";
                cout << "Enter 1, 2, 3, or 4\n";
                cin >> menuChoice;
                menuSelection = true;
            }
        } while (menuSelection);
    }
}

int controls()
{
    //resetChoice();
    cout << menuBar;
    cout << "                     Controls\n\n\n";
    cout << "           'i' ==>  Item Management\n";
    cout << "           'm' ==>  Display Menu\n\n";
    cout << "           Press '1' to return to settings.\n\n\n";
    cout << menuBar;
    cin >> menuChoice;
    do
    {
        if (menuChoice == 1)
        {
            system("clear");
            return 0;
        }
        else
        {
            cout << menuChoice << " is not a valid entry\n";
            cout << "Press '1' to return to the main menu.\n";
            cin >> menuChoice;
            menuSelection = true;
        }
    } while (menuSelection);
}

int credits()
{
    //resetChoice();
    cout << menuBar << "\n\n";
    cout << "   This silly system of menus was made by Geoff\n\n";
    cout << "       Press '1' to return to Main Menu\n\n\n\n\n";
    cout << menuBar;
    cin >> menuChoice;
    do
    {
        if (menuChoice == 1)
        {
            system("clear");
            return 0;
        }
        else
        {
            cout << menuChoice << " is not a valid option\n";
            cout << "Press '1' to return to the main menu.\n";
            cin >> menuChoice;
            menuSelection = true;
        }
    } while (menuSelection);
}

void gameMenu()
{
    madechoice = 0;
    while (madechoice == 0)
    {
        system("clear");
        cout << menuBar;
        cout << "                   Menu\n\n";
        cout << "            (1) Status\n";
        cout << "            (2) Difficulty\n";
        cout << "            (3) Controls\n";
        cout << "            (4) Return\n\n";
        cout << "          Enter a selection:\n\n";
        cout << menuBar;
        cin >> menuChoice;
        do
        {
            if (menuChoice == 1)
            {
                system("clear");
                madechoice = statusMenu();
            }
            else if (menuChoice == 2)
            {
                system("clear");
                madechoice = difficulty();
            }
            else if (menuChoice == 3)
            {
                system("clear");
                madechoice = controls();
            }
            else if (menuChoice == 4)
            {
                system("clear");
                madechoice = 1;
            }
            else
            {
                cout << menuChoice << " is not a valid selection\n";
                cout << "Press 1, 2, 3, or 4:\n\n";
                cin >> menuChoice;
                menuSelection = true;
            }
        } while (menuSelection);
    }
}
int statusMenu()
{
    system("clear");
    cout << menuBar;
    cout << "               Status\n\n";
    cout << "             Experience Points:  " << xp << "\n";
    cout << "             Health:  " << playerHealth << "\n";
    cout << "             Magic:  " << playerMana << "\n";
    cout << "             Innebriation:  " << playerDrunk << "\n";
    cout << "             Gold:  " << moneybag << "\n";
    cout << "             Armor Class:  " << playersAC << "\n";
    cout << "             Attack Speed:  " << playersSpeed << "\n";
    cout << "             Maximum Damage:  " << playersAttack << "\n\n";
    cout << "               Press 1 to return to Menu\n\n";
    cout << menuBar;
    cin >> menuChoice;
    return 0;
}

int itemMenu()
{
    madechoice = 0;
    while (madechoice == 0)
    {
        system("clear");
        cout << menuBar << "\n";
        cout << "                Item Management\n\n";
        cout << "                 (e) Equipment\n";
        cout << "                 (i) Inventory\n";
        cout << "                 (1) return\n\n\n\n";
        cout << menuBar;
        cin >> playerSelection;
        if (playerSelection == "e")
        {
            madechoice = equipmentMenu();
        }
        else if (playerSelection == "i")
        {
            madechoice = inventoryMenu();
        }
        else
        {
            return 1;
        }
    }
}
int inventoryMenu()
{
    madechoice = 0;
    while (madechoice == 0)
    {
        system("clear");
        cout << menuBar;
        cout << "               --Inventory--\n\n";
        displayInventory();
        cout << "              Press '1' to Return\n";
        cout << "              (d)rop item\n\n";
        cout << menuBar;
        cin >> playerSelection;
        if (playerSelection == "1")
        {
            madechoice = 1;
            return 0;
        }
        else if (playerSelection == "d")
        {
            madechoice = dropItemMenu();
        }
    }
}

int equipmentMenu()
{
    while (madechoice == 0)
    {
       system("clear");
        cout << menuBar;
        cout << "               --Equipped--\n\n";
        displayEquipped();
        cout << "         (e) Equip / Use Item     (1) Return\n\n";
        cout << menuBar;
        cin >>  playerSelection;
        if (playerSelection == "e")
        {
            madechoice = equipMenu();
        }
        else
        {
            madechoice = 1;
            return 0;
        }
    }
}
