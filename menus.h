using namespace std;

int menuChoice = 0;
string menuBar = "|--------------------------------------------------|\n\n";
string difficultySetting = "Medium";
bool menuSelection = false;
int madechoice = 0;
int mainMenu();
int settings();
int credits();
int difficulty();
int controls();
int startGame();

int mainMenu()
{
    madechoice = 0;
    while (madechoice == 0)
    {
        cout << menuBar;
        cout << "            Welcome to Geoff's Text Adventure!\n\n";
        cout << "                   (1) Start Game\n";
        cout << "                   (2) Settings\n";
        cout << "                   (3) Credits\n";
        cout << "                   (4) Quit\n\n";
        cout << "               Enter a Selection:  \n\n";
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
        cout << "                        Settings\n\n";
        cout << "                      (1) Difficulty\n";
        cout << "                      (2) Controls\n";
        cout << "                      (3) Return\n\n";
        cout << "                Enter a Selection:  \n\n";
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
        cout << "                   (3) Hard\n\n";
        cout << "                   (4) Return\n\n";
        cout << "           Current difficulty is set to " <<  difficultySetting << "\n\n";
        cout << "               Enter a Selection:\n\n";
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
    cout << "                    Controls\n\n";
    cout << "                 'Enter' ==>  Shoot Gun\n";
    cout << "                 'Spacebar' ==> Fire Missiles\n";
    cout << "                 'Arrow Keys' ==> Move Ship\n\n";
    cout << "                 Press '1' to return to settings.\n\n";
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
    cout << menuBar;
    cout << "   This silly system of menus was made by Geoff\n";
    cout << "       Press '1' to return to Main Menu\n\n";
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
