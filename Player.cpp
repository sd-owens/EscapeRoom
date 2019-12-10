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
#include "Player.hpp"
/*
 * Summary: Custom constructor for the class Player that creates a new Inventory
 *          object called backpack and sets its flashlight value to the passed
 *          integer by value.
 * Param: integer flashlight charge level by value
 * Returns: N/A
 */
Player::Player(int value) {

    this->backpack = new Inventory();
    initBackpack();
    flashLight = value;
}
/*
 * Summary: Custom destructor for the class Player that ensure the memory allocated
 *          for the backpack object is freed and its pointer nulled.
 * Param: none
 * Returns: N/A
 */
Player::~Player() {

    delete backpack;
    backpack = nullptr;
}
/*
 * Summary: Method to initial the backpack content with the starting flashlight object.
 *          Passed the new Item object by reference to the inventory object.
 * Param: integer flashlight charge level by value
 * Returns: N/A
 */
void Player::initBackpack() {

    std::string flashlight = "old flashlight";

    auto* item = new Item(flashlight);

    backpack->addItem(*item);

}
/*
 * Summary: Getter to return the current charge level of the flashlight.
 * Param: none
 * Returns: Integer for charge level by value
 */
int Player::getFlashLight() const {
    return flashLight;
}
/*
 * Summary: Method to decrement the charges of the flashlight from their initial value
 *          which each move of the player.
 * Param: none.
 * Returns: void
 */
void Player::useFlashLight() {

    this->flashLight--;

}
/*
 * Summary: Helper method which keeps Player and Inventory encapsulated allowing the
 *          hiding of their private fields.  Simply allows functionality within Player
 *          to call the printInventory function of the Inventory class.
 * Param: Item by reference.
 * Returns: void
 */
void Player::showBackpack() {

    backpack->printInventory();
}
/*
 * Summary: Helper method which keeps Player and Inventory encapsulated allowing the
 *          hiding of their private fields.  Simply passes the Item by reference from
 *          the Game class to the Inventory of the player.
 * Param: Item by reference.
 * Returns: void
 */
void Player::addItemToPack(Item& item) {

    backpack->addItem(item);

}
/*
 * Summary: Helper method which keeps Player and Inventory encapsulated allowing the
 *          hiding of their private fields.  Simply passes the Item string name by
 *          reference from the Game class to the Inventory of the player.
 * Param: Item by reference.
 * Returns: boolean true or false, true if item is present.
 */
bool Player::hasItem(std::string &name) {

    return backpack->containsItem(name);
}
