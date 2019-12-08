//
// Created by Steve Owens on 12/4/19.
//

#include <sstream>
#include <iostream>
#include "BookSpace.hpp"

BookSpace::BookSpace(std::string& name, int books, Color color)
    : Space(name) {
    numBooks = books;
    colorBooks = color;
}

void BookSpace::search() {

    std::stringstream ss;

    ss << "You search the room and discover an old dusty book shelf\n";
    ss << "with countless dust covered books, but your eye is drawn to\n";
    ss << numBooks << " " << (*this) << " books that appear out of place somehow.\n";

    std::cout << ss.str();

}

//void BookSpace::do_print(std::ostream &) {
//
//}

std::ostream& operator << (std::ostream& os, const BookSpace& space){

    switch (space.colorBooks) {
        case Blue: os << "blue";
            break;
        case Green: os << "green";
            break;
        case Red: os << "red";
            break;
    }
    return os;
}
