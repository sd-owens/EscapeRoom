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

#include "MenuData.hpp"
/*
 * Summary: Menu Data class whose sole purpose is to pull out all of the menu prompts
 *          and user collected data and reduce the size of the core game logic, main
 *          in this case.
 * Params:  None
 * Return:  MenuData object with two unordered_maps which contain all of the menu
 *          data for the menus and to hold user input.
 */
MenuData::MenuData() {

    this->menuData = new std::unordered_map<std::string, std::string>;

    populateMenuDataMap();

}
/*
 * Summary: Custom destructor to ensure all allocated memory is freed.
 * Param: none
 * Returns: void
 */
MenuData::~MenuData() {
    delete menuData;
    menuData = nullptr;
}
/*
 * Summary: Method to populate menuData map which contains all of the unmodifiable menu
 *          data required by the menu class.  Each prompt is a key with its contents as
 *          the value in the map.  Allows use of a general menu class and encapsulation.
 * Param: none
 * Returns: void
 */
void MenuData::populateMenuDataMap() {

    this->menuData->emplace("title", "\n*******************************************************************\n"
                                     "************   Trapped! - A C++ Escape Room Adventure  ************\n"
                                     "*******************************************************************\n\n"
                                     "This is an escape room style game with a twist. You must solve the\n"
                                     "puzzle to find the skeleton key that unlocks the door to safety,\n"
                                     "but you must do so before the batteries in your flashlight are dead.\n"
                                     "Each time you move between rooms the charge diminishes, and once the\n"
                                     "batteries are dead, your character is plunged into darkness. Without\n"
                                     "a source of light, they will never be able to solve the puzzle to\n"
                                     "find their way out of the darkness.\n");
//                                     "You awake to find yourself in a cold, dark, musty smelling concrete\n"
//                                     "room without any memory of how you arrived here.  ");

    this->menuData->emplace("mainMenu", "\nMain Menu\n\nChoose an option:\n\n"
                                        "1. Play Game \n2. Exit the game\n");

    this->menuData->emplace("intro", "\nYou awake to find yourself in a cold, dark, musty smelling concrete\n"
                                   "room without any memory of how you arrived here. The only light you see\n"
                                   "is cast from an old flashlight you find lying conveniently by your side.\n"
                                   "You pick up the flashlight and take a look around...\n\n");

    this->menuData->emplace("roomMenu", "Choose an option:\n\n1. Search the Room\n2. Show backpack contents\n"
                                        "3. Move to next room\n4. Move back to last room\n");

    this->menuData->emplace("unlockMenu", "Choose an option:\n\n1. Search the Room\n2. Show backpack contents\n"
                                        "3. Move to next room\n4. Move back to last room\n5. UNLOCK THE DOOR!!!\n");

    this->menuData->emplace("comboMenu", "\nEnter Combination:\n");

    this->menuData->emplace("tryAgain", "\nTry again?\n1. Yes\n2. No\n");

    this->menuData->emplace("replayMenu", "\nChoose an option:\n\n1. Play Again?\n2. Exit!\n");

    this->menuData->emplace("outputPrompt", "\nThanks for playing Trapped!, Goodbye!\n");

}