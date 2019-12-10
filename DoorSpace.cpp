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
#include <sstream>
#include <iostream>
#include "DoorSpace.hpp"
/*
 * Summary: Custom constructor for the class DoorSpace that inits its private
 *          member variables by calling its base class constructor and then its
 *          unique member fields locked
 * Param: std::string by reference
 * Returns: N/A
 */
DoorSpace::DoorSpace(std::string& name)
    :Space(name){
    locked = true;
}
/*
 * Summary: Derived class implementation of the pure virtual function search() from the
 *          base class.  Each derived class provides a unique stringstream output
 *          regarding the contents of the room and/or clues to solves the puzzle.
 * Param: none
 * Returns: void
 */
void DoorSpace::search() {

    std::stringstream ss;

    ss << "\nYou search the room and discover an solid iron bar door with a giant\n";
    ss << "metal padlock and a black metal skull embossed on the face\n\n";
    ss << "Beyond the door you can faintly see stone steps leading up!\n";
    ss << "This must be the way out! You have to find the key to the lock!\n";

    std::cout << ss.str();
}
/*
 * Summary: Standard getter for object fields below this summary.
 * Param: various
 * Returns: various
 */
bool DoorSpace::isLocked() {
    return locked;
}
