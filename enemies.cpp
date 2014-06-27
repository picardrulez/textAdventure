#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include "menus.h"
#include "enemies.h"

int enemy = 0;
int enemyInfo[3] = {0,0,0};
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
    

 string enemyOrcImage0 = "                \n";
 string enemyOrcImage1 = "                        coxxdoc:, \n";
 string enemyOrcImage2 = "                      ;xdxxxxxdllcc; \n";
 string enemyOrcImage3 = "                      oxdxkkxdolcllol, \n";
 string enemyOrcImage4 = "                   ,cdkddddxxdxxddooc:,\n";
 string enemyOrcImage5 = "                  lkooodxcdoxdxxkxxocc: \n";
 string enemyOrcImage6 = "                 ;l,,;lod;clcc:llooc:c:: \n";
 string enemyOrcImage7 = "                ,c;.   ...............ccclc:, \n";
 string enemyOrcImage8 = "                  ;';. .,lll;,,;:l:'.,:; \n";
 string enemyOrcImage9 = "                  cc,;;..:cc;,::co,''oc. \n";
string enemyOrcImage10 = "                  ,dcdll:;:cclc:;l:;;cc,\n";
string enemyOrcImage11 = "                 locdodxkkOOOxo:cllddccc; \n";
string enemyOrcImage12 = "                ,xllllodoodxkkkkkkkxdlcoxkl' \n";
string enemyOrcImage13 = "                ,l;:::cloldxxddddollcccoOOOk; \n";
string enemyOrcImage14 = "               '',,..';clcldolc;'...'';000OOxc \n";
string enemyOrcImage15 = "           ,:colco.  .'.,,,,'.     ..:dk00K0koo::coc \n";
string enemyOrcImage16 = "         :odddol:..           ..';cdoloxkkkxxoc::lodx; \n";
string enemyOrcImage17 = "        :dooddoc:;;'.      ..,;:ldxxo:oxdddol:::loxkkxc \n";
string enemyOrcImage18 = "        :lollc:::c:::;,;llllooccoxkxoclcccc::::clodOOkd; \n";
string enemyOrcImage19 = "          .',,;codddddollolcll:cddddddxdddollcldddxxdl:      \n";
string enemyOrcImage20 = "              ..,cooddddxxo;:;oxOOO000000Okxo:,,'          \n";
string enemyOrcImage21 = "                        ''.. .';:::::::;,  \n";

string enemyOrcImageHit0 = "                     \n";                                
string enemyOrcImageHit1 = "                             coxxdoc:, \n";               
string enemyOrcImageHit2 = "                           ;xdxxxxxdllcc; \n";            
string enemyOrcImageHit3 = "                           oxdxkkxdolcllol, \n";          
string enemyOrcImageHit4 = "                        ,cdkddddxxdxxddooc:,\n";          
string enemyOrcImageHit5 = "                       lkooodxcdoxdxxkxxocc: \n";         
string enemyOrcImageHit6 = "                      ;l,,;lod;clcc:llooc:c:: \n";        
string enemyOrcImageHit7 = "                     ,c;.   ...............ccclc:, \n";   
string enemyOrcImageHit8 = "                       ;';. .,lll;,,;:l:'.,:; \n";        
string enemyOrcImageHit9 = "                       cc,;;..:cc;,::co,''oc. \n";        
string enemyOrcImageHit10 = "                       ,dcdll:;:cclc:;l:;;cc,\n";         
string enemyOrcImageHit11 = "                      locdodxkkOOOxo:cllddccc; \n";       
string enemyOrcImageHit12 = "                     ,xllllodoodxkkkkkkkxdlcoxkl' \n";    
string enemyOrcImageHit13 = "                     ,l;:::cloldxxddddollcccoOOOk; \n";   
string enemyOrcImageHit14 = "                    '',,..';clcldolc;'...'';000OOxc \n";  
string enemyOrcImageHit15 = "                ,:colco.  .'.,,,,'.     ..:dk00K0koo::coc \n";
string enemyOrcImageHit16 = "              :odddol:..           ..';cdoloxkkkxxoc::lodx; \n";
string enemyOrcImageHit17 = "             :dooddoc:;;'.      ..,;:ldxxo:oxdddol:::loxkkxc \n";
string enemyOrcImageHit18 = "             :lollc:::c:::;,;llllooccoxkxoclcccc::::clodOOkd; \n";
string enemyOrcImageHit19 = "               .',,;codddddollolcll:cddddddxdddollcldddxxdl:      \n";
string enemyOrcImageHit20 = "                   ..,cooddddxxo;:;oxOOO000000Okxo:,,'          \n";
string enemyOrcImageHit21 = "                             ''.. .';:::::::;,  \n";  


//displays picture of enemy
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
    else if (enemyType == "orc")
    {
        cout << enemyOrcImage0;
        cout << enemyOrcImage1;
        cout << enemyOrcImage2;
        cout << enemyOrcImage3;
        cout << enemyOrcImage4;
        cout << enemyOrcImage5;
        cout << enemyOrcImage6;
        cout << enemyOrcImage7;
        cout << enemyOrcImage8;
        cout << enemyOrcImage9;
        cout << enemyOrcImage10;
        cout << enemyOrcImage11;
        cout << enemyOrcImage12;
        cout << enemyOrcImage13;
        cout << enemyOrcImage14;
        cout << enemyOrcImage15;
        cout << enemyOrcImage16;
        cout << enemyOrcImage17;
        cout << enemyOrcImage18;
        cout << enemyOrcImage19;
        cout << enemyOrcImage20;
        cout << enemyOrcImage21;
    }
 }
    
//displays shifted picture of enemy
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
    else if (enemyType == "orc")
    {
        cout << enemyOrcImageHit0;
        cout << enemyOrcImageHit1;
        cout << enemyOrcImageHit2;
        cout << enemyOrcImageHit3;
        cout << enemyOrcImageHit4;
        cout << enemyOrcImageHit5;
        cout << enemyOrcImageHit6;
        cout << enemyOrcImageHit7;
        cout << enemyOrcImageHit8;
        cout << enemyOrcImageHit9;
        cout << enemyOrcImageHit10;
        cout << enemyOrcImageHit11;
        cout << enemyOrcImageHit12;
        cout << enemyOrcImageHit13;
        cout << enemyOrcImageHit14;
        cout << enemyOrcImageHit15;
        cout << enemyOrcImageHit16;
        cout << enemyOrcImageHit17;
        cout << enemyOrcImageHit18;
        cout << enemyOrcImageHit19;
        cout << enemyOrcImageHit20;
        cout << enemyOrcImageHit21;
    }
}

//animates images of enemy
void displayEnemyHit(string enemyType)
{
    clearScreen();
    cout << menuBar << "\n\n";
    displayEnemyShift(enemyType);
    cout << menuBar << "\n\n";
    usleep(300000);
    clearScreen();
    cout << menuBar << "\n\n";
    displayEnemy(enemyType);
    cout << menuBar << "\n\n";
    usleep(300000);
    clearScreen();
    cout << menuBar << "\n\n";
    displayEnemyShift(enemyType);
    cout << menuBar << "\n\n";
    usleep(300000);
    clearScreen();
    cout << menuBar << "\n\n";
    displayEnemy(enemyType);
    cout << menuBar << "\n\n";
    usleep(300000);
    clearScreen();
    cout << menuBar << "\n\n";
    displayEnemyShift(enemyType);
    cout << menuBar << "\n\n";
    usleep(300000);
    clearScreen();
    cout << menuBar << "\n\n";
    displayEnemy(enemyType);
}
