//
// Created by Steve Owens on 12/7/19.
//

#include <iostream>
#include "Inventory.hpp"


Inventory::Inventory() {

    this->head = nullptr;
    this->tail = nullptr;
    this->maxItems = 5;
    this->numItems = 0;

}

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

bool Inventory::isEmpty() {

    return !head;
}

bool Inventory::isFull() {

    return numItems == maxItems;

}

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

void Inventory::printInventory() {

    ListNode* itr = head;

    std::cout << "\nBackpack contains:\n";

    while(itr) {


        std::cout << itr->item->getName() << std::endl;
        itr = itr->next;

    }
    std::cout << std::endl;

}

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
