//
// Created by Steve Owens on 12/4/19.
//

#ifndef GAME_HPP
#define GAME_HPP


#include "Space.hpp"
#include "GameMap.hpp"

class Game {
private:
    GameMap* map;
    Player* player;
public:
    explicit Game();
    ~Game();
    void play();
    bool moveForward();
    bool moveBackward();
    void searchRoom();
    void printStatus();
    void endGame();
};


#endif //GAME_HPP
