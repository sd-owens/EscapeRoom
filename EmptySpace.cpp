//
// Created by steve on 12/5/19.
//

#include <iostream>
#include <sstream>
#include "EmptySpace.hpp"

EmptySpace::EmptySpace(std::string &name)
    : Space(name){

}

void EmptySpace::search() {

    std::stringstream ss;

    ss << "You search the room and find that its just an empty corridor!\n";
    std::cout << ss.str();

}
