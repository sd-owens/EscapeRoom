//
// Created by Steve Owens on 12/4/19.
//

#include "Space.hpp"

Space::Space(std::string& name) {

    player = nullptr;
    this->name = name;
    this->row = 0;
    this->col = 0;
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

void Space::setRow(int row) {
    Space::row = row;
}

void Space::setCol(int col) {
    Space::col = col;
}

int Space::getRow() const {
    return row;
}

int Space::getCol() const {
    return col;
}

void Space::setPlayer(Player *player) {

    this->player = player;
}

Player* Space::getPlayer() const {
    return this->player;
}


