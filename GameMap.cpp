/**********************************************************************************
 * Program name: Final Project - Trapped! A C++ Escape Room Adventure
 * Author: Steven Owens
 * Date: 12/09/2019
 * Description: This is an escape room style game with a twist. You must solve the
 *              puzzle to find the skeleton key that unlocks the door to safety,
 *              but you must do so before the batteries in your flashlight are dead.
 *              Each time you move between rooms the charge diminishes, and once the
 *              batteries are dead, your character is plunged into darkness. Without
 *              a source of light, they will never be able to solve the puzzle to
 *              find their way out of the darkness.
 *
 * Secret:      365 is the combination to the chest, based on 3 Blue Books, 6 Green
 *              Books, and 5 Red books.  Alphabetizing the book colors and reading
 *              their quantity in sequence solves the riddle to unlock the chest.
 *********************************************************************************/
#include <iostream>
#include <iomanip>
#include "GameMap.hpp"
#include "ChestSpace.hpp"
#include "DoorSpace.hpp"
#include "BookSpace.hpp"
#include "EmptySpace.hpp"
/*
 * Summary: Custom constructor for the class GameMap that inits its private
 *          member variable pointers to nullptr, numSpaces to hardcoded value of 9.
 *          Once fields are set, it calls the createMap() method.
 * Param: none
 * Returns: N/A
 */
GameMap::GameMap() {

    this->numSpaces = 9;
    this->start = nullptr;
    this->end = nullptr;
    createMap();

}
/*
 * Summary: Custom destructor for the class GameMap that iterates through the spaces
 *          in the forward direction freeing allocated memory, stops once the findNext()
 *          method returns a nullptr.
 * Param: none
 * Returns: N/A
 */
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
/*
 * Summary: Method to handle instantion of the 9 required Space type object of various
 *          derived types based on local hard-coded arrays.  Calls the respective create
 *          space method to instiantiate the object and then passes the object by
 *          reference to the addSpace method to link the Spaces together.
 * Param: none
 * Returns: void
 */
void GameMap::createMap() {

    static int bookSpace;       // static variable to maintain count of bookSpaces created;

    Space* space;

    // 0 = EmptySpace, 1 = ChestSpace, 2 = BookSpace, 3 = DoorSpace
    std::string names [] = {" Start", " 1st Library", " Empty Corridor",
                            " 2nd Library", " Chest Room", " Empty Corridor",
                            " 3rd Library", " Empty Corridor", " Iron Door"};

    int roomTypes [] = {0, 2, 0, 2, 1, 0, 2, 0, 3};

    int numBooks [] = {3, 6, 5};                // chest combination

    Color colors [] = {Blue, Green, Red};

    Direction forward [] = {south, east, east, south, south, west, north, west, south};

    for (int i = 0; i < numSpaces; i++) {

        if(roomTypes[i] == 2) {

            space = (createSpace(names[i],roomTypes[i],numBooks[bookSpace], colors[bookSpace]));
            addSpace(space, forward[i]);
            bookSpace++;

        } else {

            space = (createSpace(names[i], roomTypes[i], 0, Red));
            addSpace(space, forward[i]);

        }

    }

}
/*
 * Summary: Method to handle creation of the Space objects based on passed params. Increments
 *          the numRooms static variables to provide a unique room sequence to the created objects.
 *          The local static roomNum variable is what allows forward and reverse iteration through
 *          the rooms connected by 4 different pointers.
 * Param: string name by reference, integer for type, numBooks for value and enum Color by value
 * Returns: Space object on the heap by reference.
 */
Space* GameMap::createSpace(std::string& name, int type, int numBooks, Color color) {

    static int roomNum {1};  // used during room creation to allow backwards iteration

    Space* space;

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

    space->roomNum = roomNum;
    roomNum++;

    return space;
}
/*
 * Summary: Method to handle connection of the Space objects setting them in the passed forward
 *          direction and setting their reciprocal (180 degree out) direction for future reverse
 *          (backward) iteration. Uses a static variable int row and int column to create an X, Y
 *          coordinate system for use in the printMap method later
 * Param: Space object by reference, and Direction by value.
 * Returns: void
 */
void GameMap::addSpace(Space* space, Direction direction) {

    static int row = 0;
    static int col = 0;

    Space* temp;

    if(!start) {

        this->start = space;
        this->end = space;
        start->setRow(row);
        start->setCol(col);

    } else {

        temp = end;

        switch (direction) {

            case north:
                row -= 1;
                end->north = space;
                this->end = space;
                end->south = temp;
                break;

            case east:
                col += 1;
                end->east = space;
                this->end = space;
                end->west = temp;
                break;

            case south:
                row += 1;
                end->south = space;
                this->end = space;
                end->north = temp;
                break;

            case west:
                col -= 1;
                end->west = space;
                this->end = space;
                end->east = temp;
                break;

        }

        end->setRow(row);
        end->setCol(col);

    }

}
/*
 * Summary: Method to check if the linked list structure is empty based on whether the member
 *          variables start and end are set to nullptr.
 * Param: none
 * Returns: boolean true if empty based on negating the start and header pointers.
 */
bool GameMap::isEmpty() {

    return !start && !end;
}
/*
 * Summary: Method to find the next sequential Space object in the sequence of the Map, uses
 *          roomNum to find which one of the 4 pointers points to the next Space.
 * Param: Space* pointer or nullptr if at the end.
 * Returns: Space pointer to the next space
 */
Space* GameMap::findNext(Space* itr) {

    int next = itr->roomNum + 1;


    if(itr->north && itr->north->roomNum == next) {
        return itr->north;

    } else if (itr->east && itr->east->roomNum == next) {
        return itr->east;

    } else if (itr->south && itr->south->roomNum == next) {
        return itr->south;

    } else if (itr->west && itr->west->roomNum == next) {
        return itr->west;

    } else {

        return nullptr;
    }
}
/*
 * Summary: Method to find the last sequential Space object in the sequence of the Map, uses
 *          roomNum to find which one of the 4 pointers points to the last Space.
 * Param: Space* pointer or nullptr if at the start again.
 * Returns: Space pointer to the last space
 */
Space* GameMap::findLast(Space* itr) {

    int last = itr->roomNum - 1;


    if(itr->north && itr->north->roomNum == last) {
        return itr->north;

    } else if (itr->east && itr->east->roomNum == last) {
        return itr->east;

    } else if (itr->south && itr->south->roomNum == last) {
        return itr->south;

    } else if (itr->west && itr->west->roomNum == last) {
        return itr->west;

    } else {

        return nullptr;
    }

}
/*
 * Summary: Method to print the linked list structure as a 2D Map of the Escape Room.
 *          Uses std::cout formatting and X, Y coordinate system initialized during
 *          object connection to allow use of multiple for loops to print the Map.
 *          Iterates back through the linked list a second time to find the players
 *          current location and updates the Map with this location.
 * Param: none
 * Returns: void
 */
void GameMap::printMap() {

    std::cout << "Location: \n\n";

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

        std::cout << std::setw(25) << std::left << "*";
        std::cout << std::setw(25) << std::left << "*";
        std::cout << std::setw(25) << std::left << "*";
        std::cout << "*" << std::endl;

        // logic to find location of player and print on Map (P) is here

        for (int i = 0; i < 3; i++) {

            std::cout << "*";
            itr = start;

            while (itr) {

                if (itr->getCol() == i && itr->getRow() == j) {

                    if(itr->getPlayer() != nullptr) {
                        std::cout << std::setw(24) << std::left << " (P) is here";

                    } else {
                        std::cout << std::setw(24) << std::left << "";
                    }

                }

                itr = findNext(itr);
            }

        }
        std::cout << "*" << std::endl;

        // formatting for last 3 rows of mape

        for(int k = 0; k < 2; k++) {

            std::cout << std::setw(25) << std::left << "*";
            std::cout << std::setw(25) << std::left << "*";
            std::cout << std::setw(25) << std::left << "*";
            std::cout << "*" << std::endl;

        }

        std::cout << std::string(76, '*') << std::endl;
    }

    std::cout << std::endl;
}
/*
 * Summary: Method to find the Space that the player is currently located.  Iterates through
 *          the linked list until the iterator points to a Space with a valid Player pointer
 *          that is not set to nullptr.
 * Param: none
 * Returns: Space pointer that which current player resides.
 */
Space* GameMap::playerLocation() {

    Space* itr = start;

    while (itr->getPlayer() == nullptr) {

        itr = findNext(itr);

    }

    return itr;
}