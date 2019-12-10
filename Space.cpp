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
#include "Space.hpp"
/*
 * Summary: Custom constructor for the abstract class Space that inits the private
 *          member variables of its derived class shared common fields.
 * Param: std::string by reference to init the name variable.
 * Returns: N/A
 */
Space::Space(std::string& name) {

    player = nullptr;
    this->name = name;
    this->roomNum = 0;
    this->locked = true;
    this->row = 0;
    this->col = 0;
    north = nullptr;
    east = nullptr;
    south = nullptr;
    west = nullptr;

}
/*
 * Summary: Virtual default destructor.
 * Param: none
 * Returns: N/A
 */
Space::~Space() = default;
/*
 * Summary: Virtual method to get the status of the private locked field
 * Param:
 * Returns: N/A
 */
bool Space::isLocked() {
    return false;
}
/*
 * Summary: A custom setter for the locked field, can only unlock the space.
 * Param: none
 * Returns: boolean true or false, true for locked.
 */
void Space::unlock() {

    this->locked = false;
}
/*
 * Summary: Standard getters and setting for object fields below this summary.
 * Param: various
 * Returns: various
 */
void Space::setRow(int row) {
    Space::row = row;
}

void Space::setCol(int col) {
    Space::col = col;
}

int Space::getRow() const {
    return row;
}

int Space::getCol() const {
    return col;
}

void Space::setPlayer(Player *player) {

    this->player = player;
}

Player* Space::getPlayer() const {
    return this->player;
}

const std::string &Space::getName() const {

    return name;
}


