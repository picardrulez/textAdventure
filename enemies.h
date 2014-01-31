using namespace std;
int enemy;

int enemyInfo[3] = {200,20,1};

void displayWizard();




string wizardImage0 = "                       .        \n";
string wizardImage1 = "                       x.       \n";
string wizardImage2 = "                      '',       \n";
string wizardImage3 = "                ..   :  .:.     \n";
string wizardImage4 = "                .' 'Ox;,cO0.    \n";
string wizardImage5 = "                .kOKo:kxxkoXOc  \n";
string wizardImage6 = "                 ,k0.xxkO0.Kk   \n";
string wizardImage7 = "                 ...,0xxOK .,   \n";
string wizardImage8 = "                 .  x0kxkX.     \n";
string wizardImage9 = "                 .  0OkxkX      \n";
string wizardImage10 = "                 .  KkxkOK      \n";
string wizardImage11 = "                  ',. .,c.  '\n\n\n";

string wizardImageHit0 = "                    .        \n";
string wizardImageHit1 = "                    x.       \n";
string wizardImageHit2 = "                   '',       \n";
string wizardImageHit3 = "             ..   :  .:.     \n";
string wizardImageHit4 = "             .' 'Ox;,cO0.    \n";
string wizardImageHit5 = "             .kOKo:kxxkoXOc  \n";
string wizardImageHit6 = "              ,k0.xxkO0.Kk   \n";
string wizardImageHit7 = "              ...,0xxOK .,   \n";
string wizardImageHit8 = "              .  x0kxkX.     \n";
string wizardImageHit9 = "              .  0OkxkX      \n";
string wizardImageHit10 = "              .  KkxkOK      \n";
string wizardImageHit11 = "              ',. .,c.  '\n\n\n";

void displayWizard()
{
    cout << wizardImage0;
    cout << wizardImage1;
    cout << wizardImage2;
    cout << wizardImage3;
    cout << wizardImage4;
    cout << wizardImage5;
    cout << wizardImage6;
    cout << wizardImage7;
    cout << wizardImage8;
    cout << wizardImage9;
    cout << wizardImage10;
    cout << wizardImage11;
}

void displayWizardShift()
{
    cout << wizardImageHit0;
    cout << wizardImageHit1;
    cout << wizardImageHit2;
    cout << wizardImageHit3;
    cout << wizardImageHit4;
    cout << wizardImageHit5;
    cout << wizardImageHit6;
    cout << wizardImageHit7;
    cout << wizardImageHit8;
    cout << wizardImageHit9;
    cout << wizardImageHit10;
    cout << wizardImageHit11;
}

void displayWizardHit()
{
    system("clear");
    cout << menuBar;
    displayWizardShift();
    cout << menuBar;
    usleep(300000);
    system("clear");
    cout << menuBar;
    displayWizard();
    cout << menuBar;
    usleep(300000);
    system("clear");
    cout << menuBar;
    displayWizardShift();
    cout << menuBar;
    usleep(300000);
    system("clear");
    cout << menuBar;
    displayWizard();
    cout << menuBar;
    usleep(300000);
    system("clear");
    cout << menuBar;
    displayWizardShift();
    cout << menuBar;
    usleep(300000);
    system("clear");
    cout << menuBar;
    displayWizard();
}
