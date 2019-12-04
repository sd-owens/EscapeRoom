//
// Created by Steve Owens on 12/4/19.
//

#include <iostream>
#include "Player.hpp"

Player::Player(int value) {

    flashLight = value;
    initBackpack();
}
void Player::initBackpack() {

    for (int i = 0; i < 4; i++){

        backpack[i].name = "empty";
    }
}

void Player::showBackpack() {

    for (int i = 0; i < 4; i++){

        std::cout << backpack[i].name << std::endl;
    }
}

int Player::getFlashLight() const {
    return flashLight;
}
