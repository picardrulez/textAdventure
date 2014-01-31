using namespace std;
int enemy;
int enemyInfo[3] = {0,0,0};
void enemyWizard();
void displayEnemy(string enemyType);
void displayEnemyShift(string enemyType);
void displayEnemyHit(string enemyType);

//Wizard Stats
int enemyWizardInfo[3] = {200,20,1};


//int wizard_inv[3][2] = {
//    {0,3},
//    {2,3},
//    {2,3},
//    {2,9}
//};

string enemyWizardImage0 = "                       .        \n";
string enemyWizardImage1 = "                       x.       \n";
string enemyWizardImage2 = "                      '',       \n";
string enemyWizardImage3 = "                ..   :  .:.     \n";
string enemyWizardImage4 = "                .' 'Ox;,cO0.    \n";
string enemyWizardImage5 = "                .kOKo:kxxkoXOc  \n";
string enemyWizardImage6 = "                 ,k0.xxkO0.Kk   \n";
string enemyWizardImage7 = "                 ...,0xxOK .,   \n";
string enemyWizardImage8 = "                 .  x0kxkX.     \n";
string enemyWizardImage9 = "                 .  0OkxkX      \n";
string enemyWizardImage10 = "                 .  KkxkOK      \n";
string enemyWizardImage11 = "                  ',. .,c.  '\n\n\n";

string enemyWizardImageHit0 = "                    .        \n";
string enemyWizardImageHit1 = "                    x.       \n";
string enemyWizardImageHit2 = "                   '',       \n";
string enemyWizardImageHit3 = "             ..   :  .:.     \n";
string enemyWizardImageHit4 = "             .' 'Ox;,cO0.    \n";
string enemyWizardImageHit5 = "             .kOKo:kxxkoXOc  \n";
string enemyWizardImageHit6 = "              ,k0.xxkO0.Kk   \n";
string enemyWizardImageHit7 = "              ...,0xxOK .,   \n";
string enemyWizardImageHit8 = "              .  x0kxkX.     \n";
string enemyWizardImageHit9 = "              .  0OkxkX      \n";
string enemyWizardImageHit10 = "              .  KkxkOK      \n";
string enemyWizardImageHit11 = "              ',. .,c.  '\n\n\n";
    
void displayEnemy(string enemyType)
{
    if (enemyType == "wizard")
    {
        cout << enemyWizardImage0;
        cout << enemyWizardImage1;
        cout << enemyWizardImage2;
        cout << enemyWizardImage3;
        cout << enemyWizardImage4;
        cout << enemyWizardImage5;
        cout << enemyWizardImage6;
        cout << enemyWizardImage7;
        cout << enemyWizardImage8;
        cout << enemyWizardImage9;
        cout << enemyWizardImage10;
        cout << enemyWizardImage11;
    }
 }
    
void displayEnemyShift(string enemyType)
{
    if (enemyType == "wizard")
    {
        cout << enemyWizardImageHit0;
        cout << enemyWizardImageHit1;
        cout << enemyWizardImageHit2;
        cout << enemyWizardImageHit3;
        cout << enemyWizardImageHit4;
        cout << enemyWizardImageHit5;
        cout << enemyWizardImageHit6;
        cout << enemyWizardImageHit7;
        cout << enemyWizardImageHit8;
        cout << enemyWizardImageHit9;
        cout << enemyWizardImageHit10;
        cout << enemyWizardImageHit11;
    }
}

void displayEnemyHit(string enemyType)
{
    system("clear");
    cout << menuBar << "\n\n";
    displayEnemyShift(enemyType);
    cout << menuBar << "\n\n";
    usleep(300000);
    system("clear");
    cout << menuBar << "\n\n";
    displayEnemy(enemyType);
    cout << menuBar << "\n\n";
    usleep(300000);
    system("clear");
    cout << menuBar << "\n\n";
    displayEnemyShift(enemyType);
    cout << menuBar << "\n\n";
    usleep(300000);
    system("clear");
    cout << menuBar << "\n\n";
    displayEnemy(enemyType);
    cout << menuBar << "\n\n";
    usleep(300000);
    system("clear");
    cout << menuBar << "\n\n";
    displayEnemyShift(enemyType);
    cout << menuBar << "\n\n";
    usleep(300000);
    system("clear");
    cout << menuBar << "\n\n";
    displayEnemy(enemyType);
}
