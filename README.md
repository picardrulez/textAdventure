textAdventure
=============
My first c++ project.
File Explanations:
-----------------
* main.cpp - main file, run this to create binary
* create.h - header with code for setting up the character
* inv.h - header with code for the inventory system
* level1.h - header with code containing the first level
* menus.h - header with code for the menu system.
* money.h - header containing the monetary system
* enemies.h - header with code for enemy system

To Do:
------------------
* remove system calls
    * system("clear"); is everywhere.  Need to replace it with a line delete
* add a map system
    * make a map menu pullable in game
    * should only show areas player has been (using playerLocation variable)
* add enemy system
    * give enemies their own item arrays
    * when enemies are defeated, add option to loot
    * enemies should have their own location variable with a chance to change to an adjacent location each time player moves
*  fighting system
    * add more choices during battle
        * access inventory
        * use items
* impliment the inventory system <----DONE 
* replace stand in with game story
* add items in game randomly <----DONE
* add a monetary exchange system
* add a health system <----DONE
* add a fighting system <---- DONE 
* add an in game menu <----DONE
* make different difficulties <----(difficulties are chooseable, they just don't do anything)
