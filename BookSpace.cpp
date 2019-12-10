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
#include "BookSpace.hpp"
/*
 * Summary: Custom constructor for the class BookSpace that inits its private
 *          member variables by calling its base class constructor and then its
 *          unique member fields.
 * Param: std::string by reference, integer for books, Color for the bookcolor
 * Returns: N/A
 */
BookSpace::BookSpace(std::string& name, int books, Color color)
    : Space(name) {
    numBooks = books;
    colorBooks = color;
}
/*
 * Summary: Derived class implementation of the pure virtual function search() from the
 *          base class.  Each derived class provides a unique stringstream output
 *          regarding the contents of the room and/or clues to solves the puzzle.
 * Param: none
 * Returns: void
 */
void BookSpace::search() {

    std::stringstream ss;

    ss << "\nYou search the room and discover an old dusty book shelf\n";
    ss << "with countless dust covered books, but your eye is drawn to\n";
    ss << numBooks << " " << (*this) << " books that appear out of place somehow.\n";

    std::cout << ss.str();

}
/*
 * Summary: Method of overload the insertion operator for the BookSpace class to allow
 *          a clean conversion of a enum to a string text output to the console vice an
 *          integer output which is the default.
 * Param: ostream by reference and a BookSpace object by reference
 * Returns: ostream by reference
 *
 * Credit:  Implemented based on a post by user Simian Mann on GameDev.net
 *          https://www.gamedev.net/forums/topic/437852-c-enum-names-as-strings/
 */
std::ostream& operator << (std::ostream& os, const BookSpace& space){

    switch (space.colorBooks) {
        case Blue: os << "blue";
            break;
        case Green: os << "green";
            break;
        case Red: os << "red";
            break;
    }
    return os;
}
