using namespace std;

void level1();

void level1()
{
    debugopen();
    debugfile << "level 1 loaded\n";
    debugclose();
    system("clear");
    bool playerChoice = false;
    int outcome;
    int running = 1;
    while (running)
    {
        debugopen();
        debugfile << "level 1 loop started\n";
        debugclose();
        if (playerLocation ==1) 
        {
            checkForItem();
            playerChoice = false;
            while (playerChoice == false)
            {
                debugopen();
                debugfile << "location 1 loop started\n";
                debugclose();
                system("clear");
                cout << menuBar << "\n";
                cout << "    You are standing in the middle of a forest.\n";
                cout << "    A path veers off to the East and to the west\n\n\n";
                cout << "               1:  Go East\n";
                cout << "               2:  Go West\n\n\n";
                cout << menuBar;
                cin >> playerInput;
                debugopen();
                debugfile << "player chose " << playerInput << "\n";
                debugclose();
        
                if (playerInput == "1")
                {
                    playerLocation = 2;
                    debugopen();
                    debugfile << "playerLocation is 2\n";
                    debugclose();
                    playerChoice = true;
                }
                else if (playerInput == "2")
                {
                    playerLocation = 3;
                    debugopen();
                    debugfile << "playerLocation is 3\n";
                    debugclose();
                    playerChoice = true;
                }
                else if (playerInput == "i")
                {
                    itemMenu();
                }
                else if (playerInput == "m")
                {
                    gameMenu();
                }
            }
            debugopen();
            debugfile << "location 2 loop ended\n";
            debugclose();
        }
        else if (playerLocation == 2)
        {
            checkForItem();
            playerChoice = false;
            while (playerChoice == false)
            {
                debugopen();
                debugfile << "location 2 loop started\n";
                debugclose();
                system("clear");
                cout << menuBar << "\n";
                cout << "You travel deeper into the forest.\n";
                cout << "The path continues East, but there is a wooden hut.\n\n\n";
                cout << "               1:  Continue East\n";
                cout << "               2:  Enter Hut\n";
                cout << "               3:  Go West\n\n";
                cout << menuBar;
                cin >> playerInput;
                debugopen();
                debugfile << "player chose " << playerInput << "\n";
                debugclose();
                if( playerInput == "1")
                {
                    playerLocation = 4;
                    debugopen();
                    debugfile << "playerLocation is " << playerLocation << "\n";
                    debugclose();
                    playerChoice = true;
                }
                else if (playerInput == "2")
                {
                    playerLocation = 5;
                    debugopen();
                    debugfile << "playerLocation is 5\n";
                    debugclose();
                    playerChoice = true;
                }
                else if (playerInput == "3")
                {
                    playerLocation = 1;
                    debugopen();
                    debugfile << "playerLocation is 1\n";
                    debugclose();
                    playerChoice = true;
                }
                else if (playerInput == "i")
                {
                    itemMenu();
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
                debugopen();
                debugfile << "location 3 loop started\n";
                debugclose();
                system("clear");
                cout << menuBar << "\n";
                cout << "You go West.  A river is flowing in front of you.\n";
                cout << "There is a small dock with a conoe.\n\n\n";
                cout << "               1:  Cross River\n";
                cout << "               2:  Enter Conoe\n\n\n";
                cout << menuBar;
                cin >> playerInput;
                debugopen();
                debugfile << "player choice is " << playerInput << "\n";
                debugclose();
                if (playerInput == "1")
                {
                    playerLocation = 6;
                    debugopen();
                    debugfile << "playerLocation is 6\n";
                    debugclose();
                    playerChoice = true;
                }
                else if (playerInput == "2")
                {
                    playerLocation = 7;
                    debugopen();
                    debugfile << "playerLocation is 7\n";
                    debugclose();
                    playerChoice = true;
                }
                else if (playerInput == "i")
                {
                    itemMenu();
                }
                else if (playerInput == "m")
                {
                    gameMenu();
                }
            }
            debugopen();
            debugfile << "location 3 loop ended\n";
            debugclose();
        }
        else if (playerLocation == 4)
        {
            checkForItem();
            playerChoice = false;
            while (playerChoice == false)
            {
                debugopen();
                debugfile << "location 4 loop started\n";
                debugclose();
                system("clear");
                enemy = 0;
                monsterHealth = 20;
                monsterAC = 10;
                cout << menuBar;
                cout << "You continue East on your path.\n";
                cout << "A powerful wizard appears before you, extends\n";
                cout << "his arms to reveal a large staff and crystal.\n";
                cout << "He sings arcane tones and attacks!\n\n\n";
                cout << "               1:  Attack!\n";
                cout << "               2:  Go West\n\n";
                cout << menuBar;
                cin >> playerInput;
                debugopen();
                debugfile << "player chose " << playerInput << "\n";
                debugclose();
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
                    itemMenu();
                }
                else if (playerInput == "m")
                {
                    gameMenu();
                }
            }
            debugopen();
            debugfile << "location 4 loop ended\n";
            debugclose();
        }
        else if (playerLocation == 5)
        {
            checkForItem();
            playerChoice = false;
            while (playerChoice == false)
            {
                debugopen();
                debugfile << "location 5 loop started\n";
                debugclose();
                system("clear");
                cout << menuBar << "\n\n";
                cout << "You enter the hut.  A man is there selling items.\n\n\n";
                cout << "               1:  Leave Hut\n\n\n\n";
                cout << menuBar;
                debugopen();
                cin >> playerInput;
                debugopen();
                debugfile << "player chose " << playerInput << "\n";
                debugclose();
        
                if (playerInput == "1")
                {
                    playerLocation = 2;
                    debugopen();
                    debugfile << "playerLocation is 2\n";
                    debugclose();
                    playerChoice = true;
                }
                else if (playerInput == "i")
                {
                    itemMenu();
                }
                else if (playerInput == "m")
                {
                    gameMenu();
                }
            }
            debugopen();
            debugfile << "location 5 loop closed\n";
            debugclose();
        }
        else if (playerLocation == 6)
        {
            checkForItem();
            playerChoice = false;
            while (playerChoice == false)
            {
                debugopen();
                debugfile << "location 6 loop started\n";
                debugclose();
                system("clear");
                cout << menuBar << "\n\n";
                cout << "You begin to wade across the river.\n";
                cout << "Out of the bushes on either side mud people\n";
                cout << "appear and shoot you with blowguns.  You pass out.\n\n";
                cout << "               1:  Exit\n\n\n";
                cout << menuBar;
                cin >> playerInput;
                debugopen();
                debugfile << "player chose " << playerInput << "\n";
                debugclose();
                if (playerInput == "1")
                {
                    running = 0;
                    playerChoice = true;
                }
                else if (playerInput == "i")
                {
                    itemMenu();
                }
                else if (playerInput == "m")
                {
                    gameMenu();
                }
            }
            debugopen();
            debugfile << "location 6 loop closed\n";
            debugclose();
        }
        else if (playerLocation == 7)
        {
            checkForItem();
            playerChoice = false;
            while (playerChoice == false)
            {
                debugopen();
                debugfile << "location 7 loop started\n";
                debugclose();
                system("clear");
                cout << menuBar << "\n";
                cout << "You paddle down the river in the conoe.\n";
                cout << "As the river gets faster you realize the \n";
                cout << "waterfall you are heading straight towards.  You die!\n\n\n";
                cout << "               1:  Exit\n\n\n";
                cout << menuBar;
                cin >> playerInput;
                debugopen();
                debugfile << "player chose " << playerInput << "\n";
                debugclose();
                if (playerInput == "1")
                {
                    running = 0;
                    playerChoice = true;
                }
                else if (playerInput == "i")
                {
                    itemMenu();
                }
                else if (playerInput == "m")
                {
                    gameMenu();
                }
            }
            debugopen();
            debugfile << "location 7 loop closed\n";
            debugclose();
        }
    }
    debugopen();
    debugfile << "Level 1 loop closed\n";
    debugclose();
}
