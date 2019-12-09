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

Player::~Player() {

    delete backpack;
    backpack = nullptr;
}

void Player::initBackpack() {

    std::string flashlight = "Old Flashlight";

    auto* item = new Item(flashlight);

    backpack->addItem(*item);

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

void Player::addItemToPack(Item& item) {

    backpack->addItem(item);

}

bool Player::hasItem(std::string &name) {

    return backpack->containsItem(name);
}
