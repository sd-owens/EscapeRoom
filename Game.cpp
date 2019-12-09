//
// Created by Steve Owens on 12/4/19.
//

#include <iostream>
#include "Game.hpp"
#include "GameMap.hpp"

Game::Game() {

    map = new GameMap();
    player = new Player(2);

}

Game::~Game() {

    delete map;
    map = nullptr;
}

void Game::play() {

    map->start->setPlayer(player);   // set player at start Space;

    int choice;

    do {

        printStatus();


        map->printMap();
        moveForward();
        searchRoom();




        player->useFlashLight();

    } while (player->getFlashLight() > 0);

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

void Game::searchRoom() {

    Space* room = map->playerLocation();

    room->search();

    if(room->getName() == " 1st Library") {
        std::string clue = "Clue: 3 Blue Books";
        auto* books = new Item(clue);
        player->addItemToPack(books);
        std::cout << "You've found a clue, you put it in your pack!\n";

    } else if (room->getName() == " 2nd Library") {
        std::string clue = "Clue: 6 Green Books";
        auto* books = new Item(clue);
        player->addItemToPack(books);
        std::cout << "You've found a clue, you put it in your pack!\n";

    } else if (room->getName() == " 3rd Library") {
        std::string clue = "Clue: 5 Red Books";
        auto* books = new Item(clue);
        player->addItemToPack(books);
        std::cout << "You've found a clue, you put it in your pack!\n";
    }

    std::cout << "You don't think anything here can help solve the puzzle!\n";


}

void Game::printStatus() {

    std::cout << "\n*** Situation Update ***\n\n";

    std::cout << "Flashlight charge remaining: " << player->getFlashLight() << " turns\n\n";

    player->showBackpack();



}
