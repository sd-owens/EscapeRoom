//
// Created by Steve Owens on 12/4/19.
//

#include <iostream>
#include "Player.hpp"

Player::Player(int value) {


    this->backpack = new Inventory();
    initBackpack();
    flashLight = value;
}
void Player::initBackpack() {

    std::string flashlight = "Old Flashlight";


    backpack->addItem(new Item(flashlight));

}

int Player::getFlashLight() const {
    return flashLight;
}

void Player::useFlashLight() {

    this->flashLight--;

}

void Player::showBackpack() {

    backpack->printInventory();
}

void Player::addItemToPack(Item* item) {

    backpack->addItem(item);

}
