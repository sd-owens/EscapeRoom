//
// Created by Steve Owens on 12/7/19.
//

#include <iostream>
#include "Inventory.hpp"


Inventory::Inventory() {

    this->head = nullptr;
    this->maxItems = 4;
    this->numItems = 0;

}

Inventory::~Inventory() {

    if(!isEmpty()) {

        ListNode* itr = head;
        ListNode* next = head->next;

        while(itr) {

            delete itr;
            itr = next;

        }

    }
    
}

bool Inventory::isEmpty() {

    return !head;
}

bool Inventory::isFull() {

    return numItems == maxItems;

}

void Inventory::addItem(Item* item) {

    if (isFull()) {

        std::cout << "The Backpack is full!" << std::endl;

    } else {

        auto* thing = new ListNode(item);

        if(isEmpty()) {

            head = thing;

        } else {

            head->next = thing;
            head = thing;

        }
    }
}

void Inventory::printInventory() {

    ListNode* itr = head;

    while(itr) {

        std::cout << "Inventory:\n";
        std::cout << itr->item->getName() << std::endl;
        itr = itr->next;

    }

}
