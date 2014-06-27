#include "menus.h"
#include "inv.h"

//Arrays for player's equipped items


int playersHelmAC = 0;                                                         
int playersGauntletAC = 0;                                                     
int playersPlateAC = 0;                                                        
int playersBootAC = 0;                                                         
int playersAC = 0;                                                             
int playersSpeed = 1;                                                          
int playersAttack = 1;                                                         
int playerDrunk = 0;                                                           
int playerHealth = 100;
int userMessage = 0;
int percentRoll = 25;
int playerItemCount = 0;
int euses = 0;
string playerInput = "e";
int eitemNumber = 0;
int itemType = 0;
int countloops = 0;
int itemNumber = 0;
int pos1 = 0;
int pos2 = 0;
int itemUses = 0;
int enemyInventorySize = 0;
int doneEquiping = 0;
int etable = 0;
int uses = 0;
int userInput = 0;
int enemy_inv[4][2] = {
    {0,0},
    {0,0},
    {0,0},
    {0,0}
};
string lastEquipped = "";
string item = "";
int itemRoll = 0;
//creates player's inventory
int player_inv[player_inv_row][player_inv_col] = {
        {0,0}
};

//creates player's equipped items array
int player_eweapon[1][3] = {69,69,69};                                            
int player_ehelm[1][3] = {69,69,69};                                              
int player_egauntlets[1][3] = {69,69,69};                                         
int player_eboots[1][3] = {69,69,69};                                             
int player_eplate[1][3] = {69,69,69};                                             
int wizard_inv[4][2] = {                                                       
    {0,3},                                                                     
    {2,3},                                                                     
    {2,3},                                                                     
    {2,9}                                                                      
 };  


string weapons[NUM_WEAPONS] = {                                            
    "Sword",                                                               
    "Iron Sword",                                                          
    "Steel Sword",                                                         
    "Great Sword",                                                         
    "Axe",                                                                 
    "Iron Axe",                                                            
    "Steel Axe",                                                           
    "Great Axe",                                                           
    "Hammer",                                                              
    "Iron Hammer",                                                         
    "Steel Hammer",                                                        
    "Great Hammer",                                                        
    "Dart"                                                                 
}; 

//weapon's properties:  item number, max damage, uses, speed, rarity, price
int weapon_prop[weapon_prop_row][weapon_prop_col] = {                          
     {0, 5, 50, 6, 100, 3} ,                                                    
     {1, 11, 75, 4, 85, 7} ,                                                    
     {2, 17, 100, 3, 50, 10} ,                                                  
     {3, 25, 300, 1, 5, 15},                                                    
     {4, 8, 75, 8, 75, 5} ,                                                     
     {5, 15, 100, 6, 50, 9} ,                                                   
     {6, 23, 100, 5, 30, 12} ,                                                  
     {7, 30, 300, 4, 5, 17} ,                                                   
     {8, 12, 100, 10, 50, 7} ,                                                  
     {9, 18, 150, 8, 25, 11} ,                                                  
     {10, 27, 200, 7, 10, 15} ,                                                 
     {11, 40, 300, 6, 5, 20} ,                                                  
     {12, 5, 1, 2, 40, 2}                                                       
};    

string inv_armor[NUM_ARMOR] = {                                            
      "Helm",                                                                
      "Iron Helm",                                                           
      "Steel Helm",                                                          
      "Gauntlets",                                                           
      "Iron Gauntlets",                                                      
      "Steel Gauntlets",                                                     
      "Boots",                                                               
      "Riding Boots",                                                        
      "Iron Boots",                                                          
      "Steel Boots",                                                         
      "Breast Plate",                                                        
      "Iron Breast Plate",                                                   
      "Steel Breast Plate"                                                   
};   

//armor properties:  item number, armor class, uses, rarity, price
int armor_prop[armor_prop_row][armor_prop_col] = {                                                          
    {0, 3, 50, 100, 5} ,                                                   
    {1, 5, 75, 75, 7} ,                                                    
    {2, 7, 100, 50, 10} ,                                                  
    {3, 1, 50, 100, 2} ,                                                   
    {4, 3, 75, 75, 5} ,                                                    
    {5, 4, 100, 50, 8} ,                                                   
    {6, 1, 50, 100, 2} ,                                                   
    {7, 1, 20, 75, 5} ,                                                    
    {8, 4, 75, 75, 5} ,                                                    
    {9, 7, 100, 50, 7} ,                                                   
    {10, 5, 50, 100, 10} ,                                                 
    {11, 7, 75, 75, 13} ,                                                  
    {12, 9, 100, 50, 17}                                                   
};

string inv_consum[NUM_CONSUM] = {                                              
    "Healing Potion",                                                                                          
    "Greater Healing Potion",                                              
    "Magic Potion",                                                        
    "Greater Magic Potion",                                                
    "Booze",                                                               
    "Party Liquor Brown",                                                  
    "Party Liquor Clear",                                                  
    "Small Rations",                                                       
    "Large Rations",                                                       
    "Mushrooms"                                                            
};  

//consumable properties:  item number, health adjustment, magic adjustment, hinderence points, uses, rarity, price
int consum_prop[consum_prop_row][consum_prop_col] = { 
    {0, 2, 0, 0, 1, 70, 5} ,                                               
    {1, 5, 0, 0, 3, 30, 8} ,                                               
    {2, 0, 2, 0, 1, 70, 5} ,                                               
    {3, 0, 5, 0, 3, 30, 8} ,                                               
    {4, 4, 0, 1, 1, 70, 1} ,                                               
    {5, 8, 0, 4, 10, 20, 10} ,                                             
    {6, 8, 0, 4, 10, 20, 10} ,                                             
    {7, 4, 0, 0, 1, 55, 1} ,                                               
    {8, 8, 0, 0, 1, 35, 5} ,                                               
    {9, 5, 5, 2, 1, 50, 3}                                                 
}; 

//displays inventory menu
int inventoryCheck()
{
    clearScreen();
    cout << menuBar;
    cout << "                 Your health is " << playerHealth << "\n";
    cout << "            You have " << moneybag << " gold pieces\n\n";
    cout << "              --Equipped--\n";
    displayEquipped();
    cout << "              --Inventory--\n";
    displayInventory();
    cout << "          (E)quip / Use Item (1)Return\n\n";
    cout << menuBar;
    cin >> playerInput;
    if (playerInput == "e")
    {
        equipMenu();
    }
    else if (playerInput == "1")
    {
        return 0;
    }
}


//displays equipped items on screen
int displayEquipped()
{
    cout << "           Weapon:  ";
    pos1 = player_eweapon[0][0];
    pos2 = player_eweapon[0][1];
    itemUses = player_eweapon[0][2];
    if (pos1 == 9)
    {
        cout << "\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item <<  "     uses:  " << itemUses << "\n";
    }
    cout << "           Helm:  ";
    pos1 = player_ehelm[0][0];
    pos2 = player_ehelm[0][1];
    itemUses = player_ehelm[0][2];
    if (pos1 == 9)
    {
        cout << "\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "     uses:  " << itemUses << "\n";
    }
    cout << "           Breast plate:  ";
    pos1 = player_eplate[0][0];
    pos2 = player_eplate[0][1];
    itemUses = player_eplate[0][2];
    if (pos1 == 9)
    {
        cout << "\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "     uses:  " << itemUses << "\n";
    }
    cout << "           Gauntlets:  ";
    pos1 = player_egauntlets[0][0];
    pos2 = player_egauntlets[0][1];
    itemUses = player_egauntlets[0][2];
    if (pos1 == 9)
    {
        cout << "\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "     uses:  " << itemUses << "\n";
    }
    cout << "           Boots:  ";
    pos1 = player_eboots[0][0];
    pos2 = player_eboots[0][1];
    itemUses = player_eboots[0][2];
    if (pos1 == 9)
    {
        cout << "\n\n";
    }
    else
    {
        item = findItemName(pos1, pos2);
        cout << item << "     uses:  " << itemUses << "\n\n";
    }

}

//displays inventory array on screen
void displayInventory()
{
    for (int i = 0; i < playerItemCount; i++ )
    {
        string tableName;
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                pos1 = player_inv[i][j];
            }
            else if (j == 1)
            {
               pos2 = player_inv[i][j];
            }
            else if (j == 2)
            {
                itemUses = player_inv[i][j];
                cout << "                 " << findItemName(pos1, pos2) << " Uses " << itemUses << "\n";
            }
        }
    }
    cout << "\n";
}

//debug function I was using for inventory bugs
int debugInventory()
{
    int itemPos;
    clearScreen();
    cout << "DEBUG INVENTORY\n";
    for (int i = 0; i < playerItemCount; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            itemPos = player_inv[i][j];
            cout << itemPos << ",";
        }
        cout << "\n";
    }
//    cout << "Press '1' to continue\n";
//    cin >> userInput;
}

//function used to find an item's name
string findItemName(int table, int itemNumber)
{
    if (table == 0)
    {
        item = weapons[itemNumber];
    }
    else if (table == 1)
    {
        item = inv_armor[itemNumber];
    }
    else if (table == 2)
    {
        item = inv_consum[itemNumber];
    }
    return item;
}

//function used for adding an item to the player's inventory
void addInventory(int table, int item, int itemUses)
{
    if (playerItemCount < MAX_PLAYER_INV )
    {
    player_inv[playerItemCount][0] = table;
    player_inv[playerItemCount][1] = item;
    player_inv[playerItemCount][2] = itemUses;
    playerItemCount++;
    xp = xp + 1;
    }
    else
    {
        cout << "Inventory is full.";
    }
}

//function used to add party liquore to the player's inventory
void addPartyLiquor()
{
    player_inv[playerItemCount][0] = 2;
    player_inv[playerItemCount][1] = 5;
    playerItemCount++;
}

//function is called by checkForItem() if player successfully finds an item.  it determines a rarity and loops through items until it finds one matching the rarity before passing it back to the calling function
void createItem()
{
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    itemType = (randomNumber % 3);
    if (difficultySetting == "Easy")
    {
        percentRoll = ((randomNumber % 100) + 1) - 20;
    }
    else if (difficultySetting == "Medium")
    {
        percentRoll = (randomNumber % 100) + 1;
    }
    else if (difficultySetting == "Hard")
    {
        percentRoll = (randomNumber % 100) + 1;
        if (percentRoll > 10)
        {
            percentRoll = percentRoll + 10;
        }
    }
    else if (difficultySetting == "easy")
    {
        percentRoll = 25;
    }
    string itemArray;

    if (itemType == 0)
    {
        itemRoll = (randomNumber % NUM_WEAPONS);
        bool wrongrare = true;
        while (wrongrare)
        {
            int checkItem = weapons[itemRoll][5];
            if (checkItem < percentRoll)
            {
                srand(static_cast<unsigned int>(time(0)));
                randomNumber = rand();
                itemRoll = (randomNumber % NUM_WEAPONS);
            }
            else
            {
                wrongrare = false;
            }
        }
        return;
    }
    else if (itemType == 1)
    {
        itemRoll = (randomNumber % NUM_ARMOR);
        bool wrongrare = true;
        while (wrongrare)
        {
            int checkItem = inv_armor[itemRoll][4];
            if (checkItem < percentRoll)
            {
                srand(static_cast<unsigned int>(time(0)));
                randomNumber = rand();
                itemRoll = (randomNumber % NUM_ARMOR);
            }
            else
            {
                wrongrare = false;
            }
        }
        return;
    }
    else if (itemType == 2)
    {
        itemRoll = (randomNumber % NUM_CONSUM);
        bool wrongrare = true;
        while (wrongrare)
        {
            int checkItem = inv_consum[itemRoll][6];
            if (checkItem < percentRoll)
            {
                srand(static_cast<unsigned int>(time(0)));
                randomNumber = rand();
                itemRoll = (randomNumber % NUM_CONSUM);
            }
            else
            {
                wrongrare = false;
            }
        }
        return;
    }
}

//function used to clear the player's inventory.  called at the beginning of character creation in case player restarted game.
void clearPlayerInv()
{
    for (int i=0; i < playerItemCount; ++i )
    {
        for (int j=0; j < 2; ++j)
        {
            player_inv[i][j]=0;
        }
    }
    playerItemCount = 0;
    player_eweapon[0][0] = 69;
    player_eweapon[0][1] = 69;
    player_ehelm[0][0] = 69;
    player_ehelm[0][1] = 69;
    player_egauntlets[0][0] = 69;
    player_egauntlets[0][1] = 69;
    player_eboots[0][0] = 69;
    player_eboots[0][1] = 69;
    player_eplate[0][0] = 69;
    player_eplate[0][1] = 69;
}


//displays the equipping menu
int equipMenu()
{
    doneEquiping = 0;
    while (doneEquiping == 0)
    {
        clearScreen();
        cout << menuBar;
        cout << "          Press '0' to return.\n";
        cout << "          Choose Item to equip / use:\n\n";
        int startNumber = 0;
        for (int i = 0; i < playerItemCount; i++)
        {
            string tableName;
            for (int j = 0; j < 3; j++)
            {
                if (j == 0)
                {
                    pos1 = player_inv[i][j];
                }
                else if (j == 1)
                {
                    pos2 = player_inv[i][j];
                }
                else if (j == 2)
                {
                    itemUses = player_inv[i][j];
                    startNumber++;
                    cout << "                 (" << startNumber << ")  " << findItemName(pos1, pos2) << "\n";
                }
            }
        }
        cout <<"\n";
        cout << menuBar;
        if (userMessage == 1)
        {
            equipMessage();    
        }
        else if (userMessage == 2)
        {
            healthMessage();
        }
        else if (userMessage == 3)
        {
            magicMessage();
        }
        else if (userMessage == 4)
        {
            drunkMessage();
        }
        userMessage = 0;
        cin >> userInput;
        if (userInput == 0)
        {
            doneEquiping = 1;
            return 0;
        }
        itemNumber = userInput - 1;
	cout << "player_inv[" << itemNumber << "][0] is " << player_inv[itemNumber][0] << "\n";
	cout << "player_inv[" << itemNumber << "][1] is " << player_inv[itemNumber][1] << "\n";
	cout << "player_inv[" << itemNumber << "][2] is " << player_inv[itemNumber][2] << "\n";
        pos1 = player_inv[itemNumber][0];
        pos2 = player_inv[itemNumber][1];
        itemUses = player_inv[itemNumber][2];
        item = findItemName(pos2, pos2);
        if (pos1 == 2)
        {
            useItem(pos2);
        }
        else
        {
            cout << "itemUses for item being equipped is " << itemUses << "\n";
        equipItem(pos1,pos2, itemUses);
        }
        dropItem(itemNumber);
    }
}

//displays the drop item menu
int dropItemMenu()
{
    int itemSelection;
    madechoice = 0;
    while (madechoice == 0)
    {
        clearScreen();
        cout << menuBar;
        cout << "              Press '0' To Return\n";
        cout << "              Choose Item To Drop:\n\n";
        int startNumber = 0;
        for (int i = 0; i < playerItemCount; i++)
        {
            string tableName;
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                {
                    pos1 = player_inv[i][j];
                }
                else if (j == 1)
                {
                    pos2 = player_inv[i][j];
                    startNumber++;
                    cout << "                       (" << startNumber << ")  " << findItemName(pos1, pos2) << "\n";
                }
            }
        }
        cout << "\n";
        cout << menuBar;
        cin >> itemSelection;
        if (itemSelection == 0)
        {
            madechoice = 1;
            return 0;
        }
        else
        {
            itemNumber = itemSelection - 1;
            dropItem(itemNumber);
        }
    }
}

//function used to move an item from the inventory into the equipped items array (calls a function that actually does this depending on what type of item is being equipped)
void equipItem(int table, int itemNumber, int uses)
{
    item = findItemName(table, itemNumber);
    lastEquipped = item;
    userMessage = 1;
    if (item.find("Sword") != string::npos || item.find("Axe") != string::npos || item.find("Hammer") != string::npos || item.find("Dart") != string::npos )
    {
        equipWeapon(table, itemNumber, uses);
    }
    else if (item.find("Helm") != string::npos)
    {
        equipHelm(table, itemNumber, uses);
    }
    else if (item.find("Gauntlets") != string::npos)
    {
        equipGauntlets(table, itemNumber, uses);
    }
    else if (item.find("Boots") != string::npos)
    {
        equipBoots(table, itemNumber, uses);
    }
    else if (item.find("Plate") != string::npos)
    {
        equipPlate(table, itemNumber, uses);
    }
}

void equipWeapon(int table, int itemNumber, int uses)
{
    if (player_eweapon[0][0] != 69)
    {
        etable = player_eweapon[0][0];
        eitemNumber = player_eweapon[0][1];
        euses = player_eweapon[0][2];
        addInventory(etable, eitemNumber, euses);
    }
    player_eweapon[0][0] = table;
    player_eweapon[0][1] = itemNumber;
    player_eweapon[0][2] = uses;
    playersAttack = weapon_prop[itemNumber][1];
    playersSpeed = weapon_prop[itemNumber][3];

}

void equipHelm(int table, int itemNumber, int uses)
{
    if (player_ehelm[0][0] != 69)
    {
        etable = player_ehelm[0][0];
        eitemNumber = player_ehelm[0][1];
        euses = player_ehelm[0][2];
        addInventory(etable, eitemNumber, euses);
    }
    player_ehelm[0][0] = table;
    player_ehelm[0][1] = itemNumber;
    player_ehelm[0][2] = uses;
    playersHelmAC = armor_prop[itemNumber][1];
    playersAC = playersHelmAC + playersGauntletAC + playersPlateAC + playersBootAC;
}

void equipPlate(int table, int itemNumber, int uses)
{
    if (player_eplate[0][0] != 69)
    {
        etable = player_eplate[0][0];
        eitemNumber = player_eplate[0][1];
        euses = player_eplate[0][2];
        addInventory(etable, eitemNumber, euses);
    }
    player_eplate[0][0] = table;
    player_eplate[0][1] = itemNumber;
    player_eplate[0][2] = uses;
    playersPlateAC = armor_prop[itemNumber][1];
    playersAC = playersHelmAC + playersGauntletAC + playersPlateAC + playersBootAC;

}

void equipGauntlets(int table, int itemNumber, int uses)
{
    if (player_egauntlets[0][0] != 69)
    {
        etable = player_egauntlets[0][0];
        eitemNumber = player_egauntlets[0][1];
        euses = player_egauntlets[0][2];
        addInventory(etable, eitemNumber, euses);
    }
    player_egauntlets[0][0] = table;
    player_egauntlets[0][1] = itemNumber;
    player_egauntlets[0][2] = uses;
    playersGauntletAC = armor_prop[itemNumber][1];
    playersAC = playersHelmAC + playersGauntletAC + playersPlateAC + playersBootAC;
}

void equipBoots(int table, int itemNumber, int uses)
{
    if (player_eboots[0][0] != 69)
    {
        etable = player_eboots[0][0];
        eitemNumber = player_eboots[0][1];
        euses = player_eboots[0][2];
        addInventory(etable, eitemNumber, euses);
    }
    player_eboots[0][0] = table;
    player_eboots[0][1] = itemNumber;
    player_eboots[0][2] = uses;
    playersBootAC = armor_prop[itemNumber][1];
    playersAC = playersHelmAC + playersGauntletAC + playersPlateAC + playersBootAC;
}

//function is called every time a player moves places.  it determines whether or not the player finds an item and then uses the createItem() function to find what item to offer the player
void checkForItem()
{
    string playerInput;
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    int percentRoll = (randomNumber % 100) + 1;
    int difficultyPercentage;
    if (difficultySetting == "Easy")
    {
        difficultyPercentage = 50;
    }
    else if (difficultySetting == "Medium")
    {
        difficultyPercentage = 25;
    }
    else if (difficultySetting == "Hard")
    {
        difficultyPercentage = 5;
    }
    if ( percentRoll < difficultyPercentage ) {
        clearScreen();
        createItem();
        item = findItemName(itemType, itemRoll); 
        cout << menuBar << "\n";
        cout << "               You find a " << item << "!\n\n\n";
        cout << "             Press '1' to take it\n";
        cout << "             Press '2' to leave it\n\n\n\n";
        cout << menuBar;
        cin >> playerInput;
        if (playerInput == "1")
        {
            itemUses = findItemUses(itemType, itemRoll);
            addInventory(itemType, itemRoll, itemUses);
        }
        else if (playerInput == "2")
        {
            return;
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
}

//used to remove an item from the inventory and then fill in the empty space of the array
void dropItem(int itemNumber)
{
    for (int i = itemNumber; i < playerItemCount + 1; i++ )
    {
        int movingI = i + 1;
        for (int j = 0; j < 3; j++)
        {
            player_inv[i][j] = player_inv[movingI][j];
        }
    }
    playerItemCount = playerItemCount - 1;
}

//creates an enemy's inventory
void makeEnemyInventory(string enemy)
{
    if (enemy == "wizard")
    {
       for (int i=0; i < 4; i++)
       {
           countloops++;
        for (int j = 0; j < 2; j++)
        {
            enemy_inv[i][j] = wizard_inv[i][j];
        }
       }
    }
    enemyInventorySize = countloops;
}

int hutGuyMoneybag = 1000;
const int MAX_HUTGUY_INV = 20;
int hutGuyItemCount = 10;

//hutguy's inventory
int hutGuy_inv[MAX_HUTGUY_INV][2] = {
    {0,1},
    {0,6},
    {0,11},
    {1,2},
    {1,4},
    {1,9},
    {1,10},
    {2,0},
    {2,3},
    {2,6}
};

void displayHutInventory()
{
    for (int i = 0; i < hutGuyItemCount; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                pos1 = hutGuy_inv[i][j];
            }
            else if (j == 1)
            {
                pos2 = hutGuy_inv[i][j];
                cout << "                    " << findItemName(pos1,pos2) << "\n";
            }
        }
    }
    cout << "\n";
}

int storeBuyMenu()
{
    int doneBuying = 0;
    while (doneBuying == 0)
    {
        clearScreen();
        cout << menuBar;
        cout << "       Press '0' to return.\n";
        cout << "       Choose Item to Purchase:\n\n";
        int startNumber = 0;
        for (int i = 0; i < hutGuyItemCount; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                {
                    pos1 = hutGuy_inv[i][j];
                }
                else if (j == 1)
                {
                    pos2 = hutGuy_inv[i][j];
                    startNumber++;
                    cout << "             (" << startNumber << ") " << findItemName(pos1,pos2) << ": " << findItemPrice(pos1,pos2) << " GP" << "\n";
                }
            }
        }
        cout << "\n";
	cout << "Moneybag:  " << moneybag << " GP\n";
        cout << menuBar;
        cin >> userInput;
        if (userInput == 0)
        {
            doneBuying = 1;
            return 0;
        }
        int itemnumber = userInput - 1;
        pos1 = hutGuy_inv[itemnumber][0];
        pos2 = hutGuy_inv[itemnumber][1];
        item = findItemName(pos1,pos2);
        if (playerItemCount >= MAX_PLAYER_INV)
        {
            cout << "Inventory is Full\n";
            cout << "Press '1' to continue";
            cin >> userInput;
        }
        else if (findItemPrice(pos1,pos2) > moneybag)
        {
            cout << "Not enough money\n";
            cout << "Press '1' to continue";
            cin >> userInput;
        }
        else
        {
            buyItem(pos1,pos2,itemnumber);
        }
    }
}

//used when player buy's an item.  updates hutguy's inventory and fixes the player's
int buyItem(int itemTable, int itemNumber, int invnumber)
{
    for (int i = invnumber; i < hutGuyItemCount + 1; i++ )
    {
        int movingI = i + 1;
        for (int j = 0; j < 2; j++)
        {
            hutGuy_inv[i][j] = hutGuy_inv[movingI][j];
        }
    }
    hutGuyItemCount = hutGuyItemCount - 1;
    moneybag = moneybag - findItemPrice(itemTable, itemNumber);
    uses = findItemUses(itemTable, itemNumber);
    addInventory(itemTable, itemNumber, uses);
    xp = xp + findItemPrice(itemTable, itemNumber);
}

int storeSellMenu()
{
    int doneSelling = 0;
    while (doneSelling == 0)
    {
        clearScreen();
        cout << menuBar;
        cout << "         Press '0' to return.\n";
        cout << "         Choose Item to Sell:\n\n";
        int startNumber = 0;
        for (int i = 0; i < playerItemCount; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                {
                    pos1 = player_inv[i][j];
                }
                else if (j == 1)
                {
                    pos2 = player_inv[i][j];
                    startNumber++;
                    cout << "            (" << startNumber << ") " << findItemName(pos1,pos2) << ": " << findItemValue(pos1,pos2) << " GP" << "\n";
                }
            }
        }
        cout << "\n";
	cout << "Moneybag:  " << moneybag << " GP \n";
        cout << menuBar;
        cin >> userInput;
        if (userInput == 0)
        {
            doneSelling = 1;
            return 0;
        }
        int itemnumber = userInput - 1;
        pos1 = player_inv[itemnumber][0];
        pos2 = player_inv[itemnumber][1];
        item = findItemName(pos1,pos2);
        if (hutGuyItemCount >= MAX_HUTGUY_INV)
        {
            cout << "Shop is full\n";
            cout << "Press '1' to continue";
            cin >> userInput;
        }
        else if (findItemValue(pos1,pos2) > hutGuyMoneybag)
        {
            cout << "Store doesn't have enough money\n";
            cout << "Press '1' to continue";
            cin >> userInput;
        }
        else
        {
            sellItem(pos1,pos2,itemnumber);
        }
    }
}

//takes item from player's inventory and puts it in the hutguy's while updating money stuff
int sellItem(int itemTable, int itemNumber, int invnumber)
{
    hutGuy_inv[hutGuyItemCount][0] = itemTable;
    hutGuy_inv[hutGuyItemCount][1] = itemNumber;
    hutGuyItemCount++;
    dropItem(invnumber);
    hutGuyMoneybag = hutGuyMoneybag - findItemValue(itemTable, itemNumber);
    moneybag = moneybag + findItemValue(itemTable, itemNumber);
    xp = xp + findItemValue(itemTable, itemNumber);
}

int findItemPrice(int table, int itemNumber)
{
    int price;
    if (table == 0)
    {
        price = weapon_prop[itemNumber][5];
    }
    else if (table == 1)
    {
        price = armor_prop[itemNumber][4];
    }
    else if (table == 2)
    {
        price = consum_prop[itemNumber][6];
    }
    return price;
}

//reduces the value of an item by half if the player wants to sell one of his items
int findItemValue(int table, int itemNumber)
{
    int price = findItemPrice(table, itemNumber) / 2;
    return price;
}

//used if the player takes one of their consumables
void useItem(int itemNumber)
{
    xp = 5;
    playerHealth = playerHealth + consum_prop[itemNumber][1];
    playerDrunk = playerDrunk + consum_prop[itemNumber][3];
    playerMana = playerMana + consum_prop[itemNumber][2];
    if (playerHealth > 100)
    {
        playerHealth = 100;
    }
    if ((consum_prop[itemNumber][1] != 0) && (consum_prop[itemNumber][2] == 0) && (consum_prop[itemNumber][3] == 0))
    {
        userMessage = 2;
    }
    else if (consum_prop[itemNumber][1] == 0)
    {
        userMessage = 3;
    }
    else if (consum_prop[itemNumber][3] !=0)
    {
        userMessage = 4;
    }
}

//displays player's health
void healthMessage()
{
    cout << "Health is now " << playerHealth << "\n";
}

void equipMessage()
{
    cout << lastEquipped << " has been equipped\n";
}

//displays player's magic
void magicMessage()
{
    cout << "Magic is now " << playerMana <<"\n";
}

//displays player's innebriateion
void drunkMessage()
{
    cout << "Health is now " << playerHealth << "\n";
    cout << "Magic is " << playerMana << "\n";
    cout << "Innebriation is now " << playerDrunk << "\n";
}

//determines how many uses an item has left
int findItemUses(int table, int itemNumber)
{
    if (table == 0)
    {
        itemUses = weapon_prop[itemNumber][2];
    }
    else if (table == 1)
    {
        itemUses = armor_prop[itemNumber][2];
    }
    else if (table == 2)
    {
        itemUses = consum_prop[itemNumber][4];
    }
    return itemUses;
}
