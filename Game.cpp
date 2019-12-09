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
        map->printMap();
        moveForward();









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

void Game::printStatus() {

    std::cout << "\n*** Situation Update ***\n\n";

    std::cout << "Flashlight charge remaining: " << player->getFlashLight() << " turns\n\n";

    player->showBackpack();



}
