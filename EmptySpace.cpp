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
#include <sstream>
#include "EmptySpace.hpp"
/*
 * Summary: Custom constructor for the class EmptySpace that inits its private
 *          member variables by calling its base class constructor.
 * Param: std::string by reference
 * Returns: N/A
 */
EmptySpace::EmptySpace(std::string &name)
    : Space(name){

}
/*
 * Summary: Derived class implementation of the pure virtual function search() from the
 *          base class.  Each derived class provides a unique stringstream output
 *          regarding the contents of the room and/or clues to solves the puzzle.
 * Param: none
 * Returns: void
 */
void EmptySpace::search() {

    std::stringstream ss;

    ss << "\nYou search the room and find that its just an empty corridor!\n";
    std::cout << ss.str();

}
