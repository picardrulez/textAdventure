using namespace std;

void level1();

void level1()
{
    system("clear");
    int running = 1;
    while (running)
    {
        if (playerLocation ==1) 
        {
            system("clear");
            cout << "You are standing in the middle of a forest.  A path veers off to the East and to the west\n";
            cout << "1:  Go East\n";
            cout << "2:  Go West\n";
            cin >> userInput;
    
            if (userInput == 1)
            {
                playerLocation = 2;
            }
            else if (userInput == 2)
            {
                playerLocation = 3;
            }
        }
        else if (playerLocation == 2)
        {
            system("clear");
            cout << "You travel deeper into the forest.  The path continues East, but there is a wooden hut.\n";
            cout << "1:  Continue East\n";
            cout << "2:  Enter Hut\n";
            cout << "3:  Go West\n";
            cin >> userInput;
            if( userInput == 1)
            {
                playerLocation = 4;
            }
            else if (userInput == 2)
            {
                playerLocation = 5;
            }
            else if (userInput == 3)
            {
                playerLocation = 1;
            }
        }
        else if (playerLocation == 3)
        {
            system("clear");
            cout << "You go West.  A river is flowing in front of you.  There is a small dock with a conoe.\n";
            cout << "1:  Cross River\n";
            cout << "2:  Enter Conoe\n";
            cin >> userInput;
            if (userInput == 1)
            {
                playerLocation = 6;
            }
            else if (userInput == 2)
            {
                playerLocation = 7;
            }
        }
        else if (playerLocation == 4)
        {
            system("clear");
            cout << "You coneinue East on your path.  A powerful wizard appears before you, extends his arms to reveal a large staff and crystal.  He sings arcane tones and sucks you into his crystal.\n";
            cout << "1:  Exit\n";
            cin >> userInput;
            if (userInput == 1)
            {
                running = 0;
            }
        }
        else if (playerLocation == 5)
        {
            system("clear");
            cout << "You enter the hut.  A man is there selling items.\n";
            cout << "1:  Exit\n";
            cin >> userInput;
    
            if (userInput == 1)
            {
                running = 0;
            }
        }
        else if (playerLocation == 6)
        {
            system("clear");
            cout << "You begin to wade across the river.  Out of the bushes on either side mud people appear and shoot you with blowguns.  You pass out.\n";
            cout << "1:  Exit\n";
            cin >> userInput;
            if (userInput == 1)
            {
                running = 0;
            }
        }
        else if (playerLocation == 7)
        {
            system("clear");
            cout << "You paddle down the river in the conoe.  As the river gets faster you ealize the waterfall you are heading straight towards.  You die!\n";
            cout << "1:  Exit\n";
            cin >> userInput;
            if (userInput == 1)
            {
                running = 0;
            }
        }
    }
}
