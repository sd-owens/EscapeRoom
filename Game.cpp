//
// Created by Steve Owens on 12/4/19.
//

#include <iostream>
#include "Game.hpp"
#include "GameMap.hpp"

Game::Game(Menu* menu) {

    map = new GameMap();
    player = new Player(20);
    this->menu = menu;

}

Game::~Game() {

    Space* space = map->playerLocation();
    delete player;
    space->setPlayer(nullptr);
    delete map;
    player = nullptr;
    map = nullptr;

}

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

void Game::printStatus() {

    std::cout << "\n*** Situation Update ***\n\n";

    std::cout << "Flashlight charge remaining: " << player->getFlashLight() << " turns\n\n";

    map->printMap();

}

int Game::endGame() {

    std::cout << "\nYou've unlocked the Iron Door!  You run towards the light and\n";
    std::cout << "quickly hurry up the stairs.  You have been in the darkness for\n";
    std::cout << "so long the sun light is blinding as your burst into the room!\n\n";
    std::cout << "You begin to recover your vision just in time to see a steel\n";
    std::cout << "door swing shut behind and lock into place...\n\n";
    std::cout << "Trapped again!  Be sure to play Trapped 2, coming soon!\n\n";

    return -1;
}
