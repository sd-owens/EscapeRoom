//
// Created by Steve Owens on 12/4/19.
//

#include <iostream>
#include <sstream>
#include "ChestSpace.hpp"

ChestSpace::ChestSpace(std::string& name)
    : Space(name){
    locked = true;
}

bool ChestSpace::isLocked() {
    return locked;
}

void ChestSpace::unlock() {

    locked = false;

}

void ChestSpace::search() {

    std::stringstream ss;

    ss << "\nYou search the room and discover an old iron chest with a fancy\n";
    ss << "new combination lock?!? The combo requires 3 digits...\n";

    std::cout << ss.str();
}
