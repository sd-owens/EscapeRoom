//
// Created by Steve Owens on 12/7/19.
//

#include "Item.hpp"

Item::Item(std::string &name) {
    this->name = name;
}

const std::string &Item::getName() const {
    return name;
}
