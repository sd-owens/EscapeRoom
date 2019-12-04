//
// Created by Steve Owens on 12/4/19.
//

#ifndef GAME_HPP
#define GAME_HPP


#include "Space.hpp"

class Game {
private:
    Space* start;
    Space* exit;
public:
    void createSpaces();
    void play();
    void endGame();
};


#endif //GAME_HPP
