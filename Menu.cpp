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

#include <iostream>
#include <string>
#include "Menu.hpp"
#include "validInput.hpp"
#include "MenuData.hpp"
/*
 * Summary: Refactored Menu Class which has been decomposed into smaller member functions for
 *          modularity.  Constructor takes single MenuData object with all required data for
 *          user menu prompts and collection of game data.
 * Param: MenuData class object pointer named data.
 * Returns: N/A
 */
Menu::Menu(MenuData* data) {

    this->menuPrompts = data->menuData;

}
/*
 * Summary: Displays the main menu to the user and captures their choice, data is validated
 *          as a string and converted to an integer.  Static int count exists to prevent
 *          reprinting "title" on subsequent iterations of main menu calls.
 * Param: none
 * Returns: int which is a 1 or 2 by the menu
 */
int Menu::main() {

    static int count {0};

    std::string input {};
    int choice {};

    if(count == 0) {

        std::cout << this->menuPrompts->at("title");

    }
    std::cout << this->menuPrompts->at("mainMenu");

   do {
       getline(std::cin, input);
       choice = validateIntegerInput(input);
       if(choice < 0 || choice > 45) {
           std::cerr << "Must choose a number between 0 and 45!\n";
       }
   } while(choice < 0 || choice > 45);

    count++;
    return choice;
}
/*
 * Summary: Function to provide intro to start of game and provide direction.
 * Param: none
 * Returns: N/A
 */
void Menu::introduction() {
    std::cout << this->menuPrompts->at("intro");
}
/*
 * Summary: Displays the player action menu to the user and captures their choice, data
 *          is validated as a string and converted to an integer.  Provides the 4 options
 *          to the player for each turn: search space, view inventory, more forward or move
 *          backwards one space.
 * Param: none
 * Returns: int which is 1 - 4 by the menu
 */
int Menu::roomMenu() {

    std::string input {};
    int choice {};

    std::cout << this->menuPrompts->at("roomMenu");

    do {
        getline(std::cin, input);
        choice = validateIntegerInput(input);
        if(choice < 1 || choice > 4) {
            std::cerr << "Must choose 1 - 4!\n";
        }
    } while(choice < 1 || choice > 4);

    return choice;
}
/*
 * Summary: Displays the player unlocked menu to the user and captures their choice, data
 *          is validated as a string and converted to an integer.  Provides the 4 options
 *          to the player for each turn: search space, view inventory, more forward or move
 *          backwards one space PLUS the 5th option to unlock the door
 * Param: none
 * Returns: int which is 1 - 5 by the menu
 */
int Menu::unlockMenu() {

    std::string input {};
    int choice {};

    std::cout << this->menuPrompts->at("unlockMenu");

    do {
        getline(std::cin, input);
        choice = validateIntegerInput(input);
        if(choice < 1 || choice > 5) {
            std::cerr << "Must choose 1 - 5!\n";
        }
    } while(choice < 1 || choice > 5);

    return choice;
}
/*
 * Summary: Takes the user attempt at the combination as a string, validates it and coverts
 *          it to an integer before returning it to the calling function.
 * Param: none
 * Returns: validated integer
 */
int Menu::comboMenu() {

    std::string input {};
    int choice {};

    std::cout << this->menuPrompts->at("comboMenu");

    getline(std::cin, input);
    choice = validateIntegerInput(input);

    return choice;
}
/*
 * Summary: Displays the tryAgain menu to the user and captures their choice, data is validated
 *          as a string and converted to an integer.  Allows user to attempt to enter the combo
 *          another time after a failed attempt.
 * Param: none
 * Returns: int which is a 1 or 2 by the menu
 */
int Menu::tryAgain() {

    std::string input {};
    int choice {};

    std::cout << this->menuPrompts->at("tryAgain");

    do {
        getline(std::cin, input);
        choice = validateIntegerInput(input);
        if(choice < 1 || choice > 2) {
            std::cerr << "Must choose 1 or 2!\n";
        }
    } while(choice < 1 || choice > 2);

    return choice;
}

/*
 * Summary: Displays menu to the user and captures their choice, data is validated
 *          as a string and converted to an integer.  Used to obtain user's input for
 *          the Nth term of the Fibonacci sequence.
 * Param: none
 * Returns: int which is between 1 and 45 by the menu
 */
int Menu::replay() {

    std::string input {};
    int choice {};

    std::cout << this->menuPrompts->at("replayMenu");

    do {
        getline(std::cin, input);
        choice = validateIntegerInput(input);
        if(choice < 1 || choice > 2) {
            std::cerr << "Must choose 1 or 2!\n";
        }
    } while(choice < 1 || choice > 2);

    return choice;
}
/*
 * Summary: Function to thank the user for playing and show positive game exit.
 * Param: none
 * Returns: N/A
 */
void Menu::salutation() {
    std::cout << this->menuPrompts->at("outputPrompt");
}
