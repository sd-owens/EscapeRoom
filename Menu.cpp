/**********************************************************************************
 * Program name: Lab 9 - STL: Queues and Stacks
 * Author: Steven Owens
 * Date: 11/23/2019
 * Description: This program is demonstrates the use of standard template library
 *              queue and stack data structures.  The STL queue is used to demo
 *              a buffer by simulated a user specified number of rounds with a
 *              random chance of adding an integer between 1 and 1000 to the
 *              queue aka \"buffer\".  The user also specifies the percent
 *              chance of adding and removing a value form the queue. The STL
 *              stack structure is used to demo reversing a given input string
 *              through creation of a palindrome (same word forward or backward).
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
 * Returns: int which is a or 2 by the menu
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

void Menu::introduction() {
    std::cout << this->menuPrompts->at("intro");
}

int Menu::gameMenu() {

    std::string input {};
    int choice {};

    std::cout << this->menuPrompts->at("gameMenu");

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
