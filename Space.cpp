//
// Created by Steve Owens on 12/4/19.
//

#include "Space.hpp"

Space::Space() {

    player = nullptr;
    north = nullptr;
    east = nullptr;
    south = nullptr;
    west = nullptr;

}

Space::~Space() = default;

bool Space::isOccupied() {
    return false;
}

void Space::showDoors() {

}


