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
#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "Item.hpp"

class Inventory {

private:
    struct ListNode{
        /*
         * Summary: Custom constructor for the struct ListNode, sets next to nullptr
         * Param: Item by reference
         * Returns: N/A
         */
        explicit ListNode(Item& item) {
            this->item = &item;
            next = nullptr;
        }
        Item* item;
        ListNode* next;
    };
    ListNode* head;
    ListNode* tail;
    int maxItems;
    int numItems;

public:
    explicit Inventory();
    ~Inventory();
    bool isEmpty();
    bool isFull();
    void addItem(Item& item);
    void printInventory();
    bool containsItem(std::string& name);

};


#endif //INVENTORY_HPP
