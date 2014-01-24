using namespace std;

// Management System for Weapon Items
int displayInventory();
int moneybag = 0;
int userInput = 0;
int weapons_system()
{
    const int NUM_WEAPONS = 13;
    string weapons[NUM_WEAPONS] = {
        "Sword",
        "Iron Sword",
        "Steel Sword",
        "Great Sword"
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
    
    const int weapon_prop_col = 5;
    const int weapon_prop_row = NUM_WEAPONS;
    int weapon_prop[weapon_prop_row][weapon_prop_col] = {
        {0, 2, 50, 6, 100} ,
        {1, 5, 75, 4, 85} ,
        {2, 8, 100, 3, 50} ,
        {3, 12, 300, 1, 5},
        {4, 4, 75, 8, 75} ,
        {5, 6, 100, 6, 50} ,
        {6, 8, 100, 5, 30} ,
        {7, 14, 300, 4, 5} ,
        {8, 6, 100, 10, 50} ,
        {9, 8, 150, 8, 25} ,
        {10, 10, 200, 7, 10} ,
        {11, 16, 300, 6, 5} ,
        {12, 5, 1, 2, 40}
    };
}

//Management System for Armor Items
int armor_system()
{
    const int NUM_ARMOR = 13;
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
   
    const int armor_prop_col = 5;
    const int armor_prop_row = NUM_ARMOR;
    int armor_prop[armor_prop_row][armor_prop_col] = {
        {0, 3, 50, 100} ,
        {1, 5, 75, 75} ,
        {2, 7, 100, 50} ,
        {3, 1, 50, 100} ,
        {4, 3, 75, 75} ,
        {5, 4, 100, 50} ,
        {6, 1, 50, 100} ,
        {7, 1, 20, 75} ,
        {8, 4, 75, 75} ,
        {9, 7, 100, 50} ,
        {10, 5, 50, 100} ,
        {11, 7, 75, 75} ,
        {12, 9, 100, 50}
    };
}

//Management System for Consumable Items
int consum_system()
{
    const int NUM_CONSUM = 10;
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

    const int consum_prop_col = 5;
    const int consum_prop_row = NUM_CONSUM;
    int consum_prop[consum_prop_row][consum_prop_col] = {
        {0, 2, 0, 1, 70} ,
        {1, 5, 0, 3, 30} ,
        {2, 2, 0, 1, 70} ,
        {3, 5, 0, 3, 30} ,
        {4, 4, 1, 1, 70} ,
        {5, 8, 4, 10, 20} ,
        {6, 8, 4, 10, 20} ,
        {7, 4, 0, 1, 55} ,
        {8, 8, 0, 1, 35} ,
        {9, 5, 2, 1, 50}
        };
}

//Array for maintaining the player's inventory.
//int player_inventory_sys()
//{
    int playerItemCount = 0;
    const int MAX_PLAYER_INV = 25;
    const int player_inv_col = 2;
    const int player_inv_row = MAX_PLAYER_INV / player_inv_col;

    int player_inv[player_inv_row][player_inv_col];

//}

int displayInventory()
{
    system("clear");
    cout << "You have " << moneybag << " gold pieces\n";
    cout << "You're inventory consists of:\n";
    for (int i = 0; i < playerItemCount; i++ )
    {
        for (int j = 0; j < 2; j++)
        {
            cout << player_inv[i][j];
        }
        cout << "\n";
    }
    cout << "Press '1' to continue\n";
    cin >> userInput;
}
