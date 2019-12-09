//
// Created by Steve Owens on 12/4/19.
//

#include <iostream>
#include "Game.hpp"
#include "GameMap.hpp"

Game::Game(Menu* menu) {

    map = new GameMap();
    player = new Player(9);
    this->menu = menu;

}

Game::~Game() {

    delete map;
    map = nullptr;
}

void Game::play() {

    int choice;

    map->start->setPlayer(player);   // set player at start Space;

    menu->introduction();
    printStatus();

    do {

        choice = menu->roomMenu();

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
        }


    } while (player->getFlashLight() > 0);

    std::cout << "\nThe flashlight batteries are dead, the light slowly fades.....\n\n";

    std::cout << "DARKNESS ENGULFS YOU, YOU WILL NEVER ESCAPE NOW!  GAME OVER!\n\n";

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
        player->addItemToPack(books);
        std::cout << "\nYou've found a clue, you put it in your pack!\n\n";

    } else if (room->getName() == " 2nd Library") {
        std::string clue = "Clue: 6 Green Books";
        auto* books = new Item(clue);
        player->addItemToPack(books);
        std::cout << "\nYou've found a clue, you put it in your pack!\n\n";

    } else if (room->getName() == " 3rd Library") {
        std::string clue = "Clue: 5 Red Books";
        auto* books = new Item(clue);
        player->addItemToPack(books);
        std::cout << "\nYou've found a clue, you put it in your pack!\n\n";

    } else if (room->getName() == " Chest Room" && !room->isLocked()) {

        std::string key = "Key";
        auto* books = new Item(key);
        player->addItemToPack(books);
        std::cout << "\nYou've found the Skeleton key, you put it in your pack!\n\n";
    } else {

        std::cout << "\nYou don't think anything here can help solve the puzzle!\n\n";
    }

}

void Game::printStatus() {

    std::cout << "\n*** Situation Update ***\n\n";

    std::cout << "Flashlight charge remaining: " << player->getFlashLight() << " turns\n\n";

    map->printMap();

}
