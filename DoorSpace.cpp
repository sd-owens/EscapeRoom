//
// Created by Steve Owens on 12/4/19.
//

#include <sstream>
#include <iostream>
#include "DoorSpace.hpp"

DoorSpace::DoorSpace(std::string& name)
    :Space(name){
    locked = true;
}

bool DoorSpace::isLocked() {
    return locked;
}

void DoorSpace::openDoor() {

//    std::stringstream ss;
//
//    // if player backpack contains key
//
//    else {
//        ss << "The lock releases and falls free of the iron door, the door is\n";
//        ss << "now open and the way is clear\n";
//    }
//
//    std::cout << ss.str();



}

void DoorSpace::search() {

    std::stringstream ss;

    ss << "You search the room and discover an solid iron bar door with a giant\n";
    ss << "metal padlock with a black metal skull embossed on the face\n\n";
    ss << "Beyond the door you can faintly see stone steps leading up!\n";
    ss << "This must be the way out! You have to find the key to the lock!\n";

    std::cout << ss.str();
}
