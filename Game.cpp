/**********************************************************************************
 * Program name: Final Project - Trapped! A C++ Escape Room Adventure
 * Author: Steven Owens
 * Date: 11/23/2019
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
#include "Game.hpp"
#include "GameMap.hpp"
/*
 * Summary: Custom constructor that creates new instances of GameMap object and Player
 *          objects.  Assigns a private pointer Menu* to the menu object on the heap.
 * Param: Menu* pointer passed by value.
 * Returns: N/A
 */
Game::Game(Menu* menu) {

    map = new GameMap();
    player = new Player(20);
    this->menu = menu;

}
/*
 * Summary: Custom destructor that ensures all objects created in the Game class are
 *          properly deallocated and pointers nulled out.
 * Param: none
 * Returns: N/A
 */
Game::~Game() {

    Space* space = map->playerLocation();
    delete player;
    space->setPlayer(nullptr);
    delete map;
    player = nullptr;
    map = nullptr;

}
/*
 * Summary: Core gameplay logic for the Escape Room game.  Use a do-while loop to
 *          execute the game until either the plays exits the locked room or the
 *          flashlight charges is extinguished ending the game.  Status codes are
 *          passed back to play() for successful completion changing the value to
 *          -1 vice 0
 * Param: none
 * Returns: void
 */
void Game::play() {

    int status{0};
    std::string input;
    std::string key {"key"};
    Space* location;

    map->start->setPlayer(player);   // set player at start Space;

    menu->introduction();
    printStatus();

    do {

        location = map->playerLocation();

        if (player->hasItem(key) && location->getName() == " Iron Door") {

            status = hasKeyMenu();

        } else {

            noKeyMenu();

        }


    } while (status == 0 && player->getFlashLight() > 0);

    if (status == 0) {

        std::cout << "\nThe flashlight batteries are dead, the light slowly fades.....\n\n";
        std::cout << "DARKNESS ENGULFS YOU, YOU WILL NEVER ESCAPE NOW!\n\n  GAME OVER!\n\n";
    }

}
/*
 * Summary: Player action menu which is normally active when the key from the chest is
 *          not in the players inventory.  Provides optiosn to search the room, view
 *          the contents of the player's backpack, move forward to the next room or
 *          move backwards to the last room visited.
 * Param: none
 * Returns: void
 */
void Game::noKeyMenu() {

    Space* location = map->playerLocation();

    int choice = menu->roomMenu();

    switch (choice) {
        case 1:
            searchRoom();
            if(location->getName() == " Chest Room" && location->isLocked()) {
                enterCombo();
            }
            break;
        case 2:
            player->showBackpack();
            break;
        case 3:
            moveForward();
            player->useFlashLight();
            printStatus();
            break;
        case 4:
            moveBackward();
            player->useFlashLight();
            printStatus();
            break;
    }
}
/*
 * Summary: Player action menu which becomes active only once the  player has the "key"
 *          and the player is currently in the lastroom with name " Iron Door".  Allows a
 *          5th menu option to become available to "unlocked the door" enabling the win
 *          condition to be available.
 * Param: none
 * Returns: A status code of 0 or -1 depending on return value of the endGame method.
 */
int Game::hasKeyMenu() {

    int choice = menu->unlockMenu();

    int status{0};

    switch (choice) {
        case 1:
            searchRoom();
            break;
        case 2:
            player->showBackpack();
            break;
        case 3:
            moveForward();
            player->useFlashLight();
            printStatus();
            break;
        case 4:
            moveBackward();
            player->useFlashLight();
            printStatus();
            break;
        case 5:
            status = endGame();
            break;

    }

    return status;
}
/*
 * Summary: Method to move the player to the next connected space or sequenced (numRoom)
 *          room using the helper function findNext.
 * Param: none
 * Returns: boolean value true or false, false if the player is unable to move forward.
 */
bool Game::moveForward() {

    Space* location = map->playerLocation();

    Space* next = map->findNext(location);

    if(next != nullptr) {

        next->setPlayer(player);
        location->setPlayer(nullptr);
        return true;
    }

    return false;

}
/*
 * Summary: Method to move the player to back to the last connected space or room
 *          using the helper function findLast.
 * Param: none
 * Returns: boolean value true or false, false if the player is unable to move backward.
 */
bool Game::moveBackward() {

    Space* location = map->playerLocation();

    Space* last = map->findLast(location);

    if(last != nullptr) {

        last->setPlayer(player);
        location->setPlayer(nullptr);

        return true;
    }

    return false;

}
/*
 * Summary: Method search the current room based on the player's location in the Space
 *          list.  Provides functionality to find Item objects or clues to the combination
 *          for the ChestRoom.  Items found are added to the players backpack.
 * Param: none
 * Returns: void
 */
void Game::searchRoom() {

    Space* room = map->playerLocation();

    room->search();

    if(room->getName() == " 1st Library") {
        std::string clue = "Clue: 3 Blue Books";
        auto* books = new Item(clue);
        player->addItemToPack(*books);
        std::cout << "\nYou've found a clue, you put it in your pack!\n\n";

    } else if (room->getName() == " 2nd Library") {
        std::string clue = "Clue: 6 Green Books";
        auto* books = new Item(clue);
        player->addItemToPack(*books);
        std::cout << "\nYou've found a clue, you put it in your pack!\n\n";

    } else if (room->getName() == " 3rd Library") {
        std::string clue = "Clue: 5 Red Books";
        auto* books = new Item(clue);
        player->addItemToPack(*books);
        std::cout << "\nYou've found a clue, you put it in your pack!\n\n";

    } else if (room->getName() == " Chest Room" && !room->isLocked()) {

        std::string key = "Key";
        auto* books = new Item(key);
        player->addItemToPack(*books);
        std::cout << "\nYou've found the Skeleton key, you put it in your pack!\n\n";

    } else if (room->getName() == " Empty Corridor") {

        std::cout << "\nYou don't think anything here can help solve the puzzle!\n\n";
    }

}
/*
 * Summary: Method to enter the combination for the chest in the ChestRoom, entering a
 *         succesful combination unlocked the chest allowing recover of the key to the
 *         Iron Gate which is the Item enabling the win condition to be available.
 *         365 is the combination to the chest, based on 3 Blue Books, 6 Green Books,
 *         and 5 Red books.  Alphabetizing the book colors and reading their quantity
 *         in sequence solves the riddle to unlock the chest.
 * Param: none
 * Returns: void
 */
void Game::enterCombo() {

    Space* location = map->playerLocation();

    int option{};

    do {

        int input = menu->comboMenu();

        if(input == 365) {

            location->unlock();
        }

        if(!location->isLocked()) {

            std::cout << "\nYou unlocked the chest!\n";
            std::string key = "key";
            auto* skeleton = new Item(key);
            player->addItemToPack(*skeleton);
            std::cout << "\nYou've found the key, you put it in your pack!\n\n";
            option = 2;

        } else {

            std::cout << "\nThe combination didn't work!\n\n";
            option = menu->tryAgain();
        }

    } while (option != 2);

}
/*
 * Summary: Method to provide information to the user after each movement.  Provides
 *          an indication of the "charges" remaining for the player's flashlight, and
 *          shows the players current location on a map.
 * Param: none
 * Returns: void
 */
void Game::printStatus() {

    std::cout << "\n*** Situation Update ***\n\n";

    std::cout << "Flashlight charge remaining: " << player->getFlashLight() << " turns\n\n";

    map->printMap();

}
/*
 * Summary: Method to display output to character about meeting the win condition
 *          with a twist at the end :)
 * Param: none
 * Returns: a value of -1 which signals the calling functions back to play() of the
 *          win condition being fulfilled.
 */
int Game::endGame() {

    std::cout << "\nYou've unlocked the Iron Door!  You run towards the light and\n";
    std::cout << "quickly hurry up the stairs.  You have been in the darkness for\n";
    std::cout << "so long the sun light is blinding as your burst into the room!\n\n";
    std::cout << "You begin to recover your vision just in time to see a steel\n";
    std::cout << "door swing shut behind and lock into place...\n\n";
    std::cout << "Trapped again!  Be sure to play Trapped 2, coming soon!\n\n";

    return -1;
}
