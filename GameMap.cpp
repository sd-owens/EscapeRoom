//
// Created by steve on 12/5/19.
//

#include <random>
#include <iostream>
#include <iomanip>
#include "GameMap.hpp"
#include "ChestSpace.hpp"
#include "DoorSpace.hpp"
#include "BookSpace.hpp"
#include "EmptySpace.hpp"

GameMap::GameMap() {

    this->numSpaces = 9;
    this->start = nullptr;
    this->end = nullptr;
    createMap();

}

GameMap::~GameMap() {

    Space* itr = start;
    Space* next = nullptr;

    while (!isEmpty()) {

        if(itr == end) {

            delete itr;
            itr = nullptr;
            start = nullptr;
            end = nullptr;

        } else {

            next = findNext(itr);
            delete itr;

            if(next) {
                itr = next;
            }

        }
    }
}

void GameMap::createMap() {

    static int bookSpace;       // static variable to maintain count of bookSpaces created;

    Space* space;

    // 0 = EmptySpace, 1 = ChestSpace, 2 = BookSpace, 3 = DoorSpace
    std::string names [] = {" Start", " 1st Library", " Empty Corridor",
                            " 2nd Library", " Chest Room", " Empty Corridor",
                            " 3rd Library", " Empty Corridor", " Iron door"};
    int roomTypes [] = {0, 2, 0, 2, 1, 0, 2, 0, 3};
    int numBooks [] = {3, 6, 5};                // chest combination
    Color colors [] = {Blue, Green, Red};
    Direction direction [] = {south, east, east, south, south, west, north, west, south};


    for (int i = 0; i < numSpaces; i++) {

        if(roomTypes[i] == 2) {

            space = &(createSpace(names[i],roomTypes[i],numBooks[bookSpace], colors[bookSpace]));
            addSpace(*space, direction[i]);
            bookSpace++;

        } else {

            space = &(createSpace(names[i], roomTypes[i], 0, Red));
            addSpace(*space, direction[i]);

        }

    }

}

Space& GameMap::createSpace(std::string& name, int type, int numBooks, Color color) {

    Space* space = nullptr;

    switch (type){
        case 1:
            space = new ChestSpace(name);
            break;
        case 2:
            space = new BookSpace(name, numBooks, color);
            break;
        case 3:
            space = new DoorSpace(name);
            break;
        default:
            space = new EmptySpace(name);
    }

    return *space;
}

void GameMap::addSpace(Space& space, Direction direction) {

    static int row = 0;
    static int col = 0;

    if(!start) {

        this->start = &space;
        this->end = &space;
        start->setRow(row);
        start->setCol(col);

    } else {

        switch (direction) {

            case north:
                row -= 1;
                end->north = &space;
                this->end = &space;
                break;

            case east:
                col += 1;
                end->east = &space;
                this->end = &space;
                break;

            case south:
                row += 1;
                end->south = &space;
                this->end = &space;
                break;

            case west:
                col -= 1;
                end->west = &space;
                this->end = &space;
                break;

        }

        end->setRow(row);
        end->setCol(col);

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

Space* GameMap::findNext(Space* itr) {

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

void GameMap::printMap() {

    Space *itr;

    std::cout << std::string(76, '*') << std::endl;

    for (int j = 0; j < 3; j++) {

        std::cout << std::setw(25) << std::left << "*";
        std::cout << std::setw(25) << std::left << "*";
        std::cout << std::setw(25) << std::left << "*";
        std::cout << "*" << std::endl;

        for (int i = 0; i < 3; i++) {

                std::cout << "*";
                itr = start;

                while (itr) {

                    if (itr->getCol() == i && itr->getRow() == j) {

                        std::cout << std::setw(24) << std::left << itr->name;

                    }

                    itr = findNext(itr);
                }


            }
            std::cout << "*" << std::endl;

            for(int k = 0; k < 3; k++) {

                std::cout << std::setw(25) << std::left << "*";
                std::cout << std::setw(25) << std::left << "*";
                std::cout << std::setw(25) << std::left << "*";
                std::cout << "*" << std::endl;

            }

            std::cout << std::string(76, '*') << std::endl;
        }


    }
