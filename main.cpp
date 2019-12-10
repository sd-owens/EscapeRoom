/**********************************************************************************
 * Program name: Final Project - Trapped! A C++ Escape Room Adventure
 * Author: Steven Owens
 * Date: 12/09/2019
 * Description: This is an escape room style game with a twist. You must solve the
 *              puzzle to find the skeleton key that unlocks the door to safety,
 *              but you must do so before the batteries in your flashlight are dead.
 *              Each time you move between rooms the charge diminishes, and once the
 *              batteries are dead, your character is plunged into darkness. Without
 *              a source of light, they will never be able to solve the puzzle to
 *              find their way out of the darkness.
 *
 * Secret:      365 is the combination to the chest, based on 3 Blue Books, 6 Green
 *              Books, and 5 Red books.  Alphabetizing the book colors and reading
 *              their quantity in sequence solves the riddle to unlock the chest.
 *********************************************************************************/
#include "Menu.hpp"
#include "Game.hpp"

/*
* Summary: Main method containing logic for menu functions for the Escape Room program.
*          Creates the MenuData object, Menu object and list object and contains
*          the main do-while loop to obtain user input.  Finally displays goodbye to the
*          user and de-allocates all of the memory on the heap for the application called
 *          during execution of main.cpp.
* Param:  None
* Returns: integer, 0 for successful execution, other integers by operating system.
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
