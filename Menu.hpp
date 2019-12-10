/**********************************************************************************
 * Program name: Final Project - Trapped! A C++ Escape Room Adventure
 * Author: Steven Owens
 * Date: 11/23/2019
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

#ifndef MENU_HPP
#define MENU_HPP

#include <unordered_map>
#include "MenuData.hpp"

class Menu {
private:
    std::unordered_map<std::string, std::string>* menuPrompts;

public:
    explicit Menu(MenuData* data);
    int main();
    void introduction();
    int roomMenu();
    int unlockMenu();
    int comboMenu();
    int tryAgain();
    int replay();
    void salutation();
};

#endif //MENU_HPP
