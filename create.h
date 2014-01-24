using namespace std;

int userInput = 0;
int playerInfo[2];
int playerLocation = 0;
int moneybag = 0;
void createCharacter();

void createCharacter() 
{
    cout << "Welcome to Geoff's Adventure.\n";
    cout << "What sex are you?\n";
    cout << "1:  Boy\n";
    cout << "2:  Girl\n";
    cin >> userInput;
    playerInfo[0] = userInput;
    system("clear");
    cout << "And what class are you?\n";
    cout << "1:  Warrior\n";
    cout << "2:  Druid\n";
    cout << "3:  Thief\n";
    cin >> userInput;
    playerInfo[1] = userInput;
    playerLocation = 1;
    moneybag = initialFunds(playerInfo[1]);
    cout << "Your initial funds are " << moneybag << " gold pieces.\n";
    cout << "Press 1 to start your adventure.";
    cin >> userInput;
    return;
}
