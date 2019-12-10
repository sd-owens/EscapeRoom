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
#include "Item.hpp"
/*
 * Summary: Custom constructor for the class Item that inits its private
 *          member variable to the passed string by reference.
 * Param: std::string by reference
 * Returns: N/A
 */
Item::Item(std::string &name) {
    this->name = name;
}
/*
 * Summary: Getter for the Item name, returns a const string by reference.
 * Param: none
 * Returns: const std::string by reference
 */
const std::string &Item::getName() const {
    return name;
}
