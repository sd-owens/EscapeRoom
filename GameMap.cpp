//
// Created by steve on 12/5/19.
//

#include <random>
#include "GameMap.hpp"
#include "ChestSpace.hpp"
#include "DoorSpace.hpp"
#include "BookSpace.hpp"
#include "EmptySpace.hpp"

GameMap::GameMap(int numSpaces) {

    this->numSpaces = numSpaces;
    this->start = nullptr;
    this->end = nullptr;

}

GameMap::~GameMap() {

    Space* itr = start;
    Space* next;

    while (!isEmpty()) {

        if(!findNext(itr)) {
            delete itr;
            itr = nullptr;
        } else {
            next = findNext(itr);
            delete itr;
            itr = next;
        }
    }
}

void GameMap::createMap() {

    Space* space;

    // 0 = EmptySpace
    // 1 = ChestSpace
    // 2 = BookSpace
    // 3 = DoorSpace

    int roomTypes [] = {0, 2, 2, 1, 2, 3};
    int numBooks [] = {3, 6, 5};                // chest combination
    Color colors [] = {Blue, Green, Red};
    Direction direction [] = {north, east, north, east, south, south};

    //initial map is 6 spaces

    for (int i = 0; i < 6; i++) {

        if(roomTypes[i] == 2) {

            space = &(createSpace(roomTypes[i],numBooks[i], colors[i]));
            addSpace(*space, direction[i]);
        } else {
            space = &(createSpace(roomTypes[i]));
            addSpace(*space, direction[i]);
        }

    }

}

Space& GameMap::createSpace(int type) {

    Space* space = nullptr;

    switch (type){
        case 1:
            space =  new ChestSpace();
            break;
        case 2:
            space = new DoorSpace();
            break;
        case 3:
            space = new EmptySpace();
            break;
    }

    return *space;
}

Space& GameMap::createSpace(int type, int numBooks, Color color) {

    Space* space = new BookSpace(numBooks, color);

    return *space;
}

void GameMap::addSpace(Space& space, Direction direction) {

    static int count {0};   //static variable to

    if(!start) {

        this->start = &space;
        this->end = &space;

    } else {

        switch (direction) {

            case north:
                end->north = &space;
                this->end = &space;
                break;
            case east:
                end->east = &space;
                this->end = &space;
                break;
            case south:
                end->south = &space;
                this->end = &space;
            case west:
                end->west = &space;
                this->end = &space;
        }

    }

}


/*
 * Summary: Random number generator using c++11 <random> library to generate an integer value over a
 *          uniform distribution between 1 and N, where N is this objects number of sides.
 * Param: integers for the min and max value
 * Returns: integer between min and max supplied params
 * Source: Implemented C++ Mersenne_twister_engine based on post by user Bill Lynch on stackoverflow.com
 *         with credit to original author Stephan T. Lavavej from Microsoft.  Retrieved 20191015 from
 *         https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library
 */
int GameMap::random(int min, int max) {

        std::random_device rd;
        std::mt19937 mt(rd());  // Mersenne Twister Engine seeded with rd()
        std::uniform_int_distribution<> dist(min, max); //default is integer type

        return dist(mt);
}

bool GameMap::isEmpty() {

    return !start;
}

Space* GameMap::findNext(Space * itr) {

    if(itr->north) {
        return itr->north;

    } else if (itr->east) {
        return itr->east;

    } else if (itr->south) {
        return itr->south;

    } else if (itr->west) {
        return itr->west;

    } else {
        return nullptr;

    }
}
