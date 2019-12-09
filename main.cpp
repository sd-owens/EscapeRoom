#include <iostream>
#include "BookSpace.hpp"
#include "GameMap.hpp"
#include "Inventory.hpp"
#include "Menu.hpp"
#include "Game.hpp"

/*
* Summary: Main method containing logic for menu functions for the Queue
*          program.  Creates the MenuData object, Menu object and list object and contains
*          the main do-while loop to obtain user input.  Finally displays goodbye to the
*          user and de-allocates all of the memory on the heap for the application.
* Param:  None
* Returns: Void
*/
    int main() {

        int option {};

        auto* data = new MenuData();
        auto* menu = new Menu(data);

        Game* game;

        option = menu->main();

        do{

            if(option == 1) {

                game = new Game(menu);
                game->play();

                option = menu->replay();
                delete game;
                game = nullptr;

            }

        } while (option != 2);

        menu->salutation();

        delete data;
        delete menu;
        data = nullptr;
        menu = nullptr;

        return 0;

    }
