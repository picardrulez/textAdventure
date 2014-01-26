using namespace std;

void level1();

void level1()
{
    system("clear");
    string playerInput;
    bool playerChoice = false;
    int outcome;
    int running = 1;
    while (running)
    {
        if (playerLocation ==1) 
        {
            checkForItem();
            playerChoice = false;
            while (playerChoice == false)
            {
                system("clear");
                cout << menuBar << "\n";
                cout << "    You are standing in the middle of a forest.\n";
                cout << "    A path veers off to the East and to the west\n\n\n";
                cout << "               1:  Go East\n";
                cout << "               2:  Go West\n\n\n";
                cout << menuBar;
                cin >> playerInput;
        
                if (playerInput == "1")
                {
                    playerLocation = 2;
                    playerChoice = true;
                }
                else if (playerInput == "2")
                {
                    playerLocation = 3;
                    playerChoice = true;
                }
                else if (playerInput == "i")
                {
                    inventoryCheck();
                }
                else if (playerInput == "m")
                {
                    gameMenu();
                }
            }
        }
        else if (playerLocation == 2)
        {
            checkForItem();
            playerChoice = false;
            while (playerChoice == false)
            {
                system("clear");
                cout << menuBar << "\n";
                cout << "You travel deeper into the forest.\n";
                cout << "The path continues East, but there is a wooden hut.\n\n\n";
                cout << "               1:  Continue East\n";
                cout << "               2:  Enter Hut\n";
                cout << "               3:  Go West\n\n";
                cout << menuBar;
                cin >> playerInput;
                if( playerInput == "1")
                {
                    playerLocation = 4;
                    playerChoice = true;
                }
                else if (playerInput == "2")
                {
                    playerLocation = 5;
                    playerChoice = true;
                }
                else if (playerInput == "3")
                {
                    playerLocation = 1;
                    playerChoice = true;
                }
                else if (playerInput == "i")
                {
                    inventoryCheck();
                }
                else if (playerInput == "m")
                {
                    gameMenu();
                }
            }
        }
        else if (playerLocation == 3)
        {
            checkForItem();
            playerChoice = false;
            while (playerChoice == false)
            {
                system("clear");
                cout << menuBar << "\n";
                cout << "You go West.  A river is flowing in front of you.\n";
                cout << "There is a small dock with a conoe.\n\n\n";
                cout << "               1:  Cross River\n";
                cout << "               2:  Enter Conoe\n\n\n";
                cout << menuBar;
                cin >> playerInput;
                if (playerInput == "1")
                {
                    playerLocation = 6;
                    playerChoice = true;
                }
                else if (playerInput == "2")
                {
                    playerLocation = 7;
                    playerChoice = true;
                }
                else if (playerInput == "i")
                {
                    inventoryCheck();
                }
                else if (playerInput == "m")
                {
                    gameMenu();
                }
            }
        }
        else if (playerLocation == 4)
        {
            checkForItem();
            playerChoice = false;
            while (playerChoice == false)
            {
                system("clear");
                enemy = 0;
                monsterHealth = 20;
                monsterAC = 10;
                cout << menuBar;
                cout << "You continue East on your path.\n";
                cout << "A powerful wizard appears before you, extends\n";
                cout << "his arms to reveal a large staff and crystal.\n";
                cout << "He sings arcane tones and attacks!\n";
                cout << "               1:  Attack!\n";
                cout << "               2:  Go West\n\n";
                cout << menuBar;
                cin >> playerInput;
                if (playerInput == "1")
                {
                    outcome = battle(1, 25, playersSpeed, playersAttack);
                    if (outcome == 1)
                    {
                        running = 0;
                        playerChoice = true;
                    }
                    else if (outcome == 0)
                    {
                        playerChoice = true;
                    }
                }
                if (playerInput == "2")
                {
                    playerLocation = 2;
                    playerChoice = true;
                }
                else if (playerInput == "i")
                {
                    inventoryCheck();
                }
                else if (playerInput == "m")
                {
                    gameMenu();
                }
            }
        }
        else if (playerLocation == 5)
        {
            checkForItem();
            playerChoice = false;
            while (playerChoice == false)
            {
                system("clear");
                cout << menuBar << "\n\n";
                cout << "You enter the hut.  A man is there selling items.\n\n\n";
                cout << "               1:  Leave Hut\n\n\n\n";
                cout << menuBar;
                cin >> playerInput;
        
                if (playerInput == "1")
                {
                    playerLocation = 2;
                    playerChoice = true;
                }
                else if (playerInput == "i")
                {
                    inventoryCheck();
                }
                else if (playerInput == "m")
                {
                    gameMenu();
                }
            }
        }
        else if (playerLocation == 6)
        {
            checkForItem();
            playerChoice = false;
            while (playerChoice == false)
            {
                system("clear");
                cout << menuBar << "\n\n";
                cout << "You begin to wade across the river.\n";
                cout << "Out of the bushes on either side mud people\n";
                cout << "appear and shoot you with blowguns.  You pass out.\n\n";
                cout << "               1:  Exit\n\n\n";
                cout << menuBar;
                cin >> playerInput;
                if (playerInput == "1")
                {
                    running = 0;
                    playerChoice = true;
                }
                else if (playerInput == "i")
                {
                    inventoryCheck();
                }
                else if (playerInput == "m")
                {
                    gameMenu();
                }
            }
        }
        else if (playerLocation == 7)
        {
            checkForItem();
            playerChoice = false;
            while (playerChoice == false)
            {
                system("clear");
                cout << menuBar << "\n";
                cout << "You paddle down the river in the conoe.\n";
                cout << "As the river gets faster you realize the \n";
                cout << "waterfall you are heading straight towards.  You die!\n\n\n";
                cout << "               1:  Exit\n\n\n";
                cout << menuBar;
                cin >> playerInput;
                if (playerInput == "1")
                {
                    running = 0;
                    playerChoice = true;
                }
                else if (playerInput == "i")
                {
                    inventoryCheck();
                }
                else if (playerInput == "m")
                {
                    gameMenu();
                }
            }
        }
    }
}
