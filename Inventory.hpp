//
// Created by Steve Owens on 12/7/19.
//

#ifndef INVENTORY_HPP
#define INVENTORY_HPP


#include "Item.hpp"

class Inventory {

private:
    struct ListNode{

        explicit ListNode(Item* item) {
            this->item = item;
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
    void addItem(Item* item);
    void printInventory();

};


#endif //INVENTORY_HPP
