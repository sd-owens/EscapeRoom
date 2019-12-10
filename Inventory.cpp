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
#include "Inventory.hpp"
/*
 * Summary: Custom constructor for the Inventory class which is a simple implementation
 *          of a singly linked list that tracks the head and tail ListNodes, can only
 *          iterate through the list in the head to tail direction.  Sets a maximum
 *          inventory quantity of 5 and current number to 0.
 * Param: none
 * Returns: N/A
 */
Inventory::Inventory() {

    this->head = nullptr;
    this->tail = nullptr;
    this->maxItems = 5;
    this->numItems = 0;

}
/*
 * Summary: Custom destructor for the Inventory class ensures memory allocated for
 *          each ListNode is freed upon deletion of the Inventory object.
 * Param: none
 * Returns: N/A
 */
Inventory::~Inventory() {

    if(!isEmpty()) {

        ListNode* itr = head;
        ListNode* next = head->next;

        while(itr) {

            delete itr->item;
            delete itr;
            itr = next;

            if(itr) {
                next = itr->next;
            }

        }

        head = nullptr;
        tail = nullptr;

    }

}
/*
 * Summary: Method to check whether inventory is empty or all items deleted.
 * Param: none
 * Returns: boolean true if Inventory is empty
 */
bool Inventory::isEmpty() {

    return !head;
}
/*
 * Summary: Method to check whether inventory is full based on maxItem field.
 * Param: none
 * Returns: boolean true if Inventory is full
 */
bool Inventory::isFull() {

    return numItems == maxItems;

}
/*
 * Summary: Method to add items to the Inventory.  Provides error handling if the
 *          backpack is already full (max capacity).  Sets pointers for head and tail
 *          as required based on whether Inventory has one or more objects currently.
 * Param: Item by reference
 * Returns: void
 */
void Inventory::addItem(Item& item) {

    if (isFull()) {

        std::cout << "The Backpack is full!" << std::endl;

    } else {

        auto* thing = new ListNode(item);

        if(isEmpty()) {

            head = thing;
            tail = thing;
            numItems++;

        } else {

            tail->next = thing;
            tail = thing;
            numItems++;

        }
    }
}
/*
 * Summary: Method to print the Items in the inventory by name to the console.
 * Param: none
 * Returns: void
 */
void Inventory::printInventory() {

    ListNode* itr = head;

    std::cout << "\nBackpack contains:\n";

    while(itr) {


        std::cout << itr->item->getName() << std::endl;
        itr = itr->next;

    }
    std::cout << std::endl;

}
/*
 * Summary: Method to check whether inventory contains a specified item by name
 * Param: std::string name by reference
 * Returns: boolean true if Inventory contains item
 */
bool Inventory::containsItem(std::string& name) {

    ListNode* itr = head;

    while(itr) {

        if(itr->item->getName() == name) {
            return true;

        } else {
            itr = itr->next;
        }
    }

    return false;
}
