//
// Created by Steve Owens on 12/4/19.
//

#ifndef GAME_HPP
#define GAME_HPP


#include "Space.hpp"
#include "GameMap.hpp"
#include "Menu.hpp"

class Game {
private:
    GameMap* map;
    Player* player;
    Menu* menu;
public:
    explicit Game(Menu* menu);
    ~Game();
    void play();
    bool moveForward();
    bool moveBackward();
    void searchRoom();
    void printStatus();
    void endGame();
};


#endif //GAME_HPP
