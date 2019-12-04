//
// Created by Steve Owens on 12/4/19.
//

#include <iostream>
#include <sstream>
#include "ChestSpace.hpp"

ChestSpace::ChestSpace()
    : Space(){
    locked = true;
}

bool ChestSpace::isLocked() {
    return locked;
}

void ChestSpace::openChest(int value) {

    std::stringstream ss;

    if(value == 365) {
        locked = false;
        ss << "The chest is unlocked!  You find a large metal skeleton key inside,\n";
        ss << "this might be the key to the iron door!\n";

    } else {
        ss << "The combination did not work! I must be missing something...\n";

    }
    std::cout << ss.str();
}

void ChestSpace::search() {

    std::stringstream ss;

    ss << "You search the room and discover an old iron chest with a fancy\n";
    ss << "new combination lock ?!?  You must have to find the combination!\n";
    std::cout << ss.str();
}
