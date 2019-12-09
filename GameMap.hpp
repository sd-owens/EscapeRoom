//
// Created by steve on 12/5/19.
//

#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include <vector>
#include "Space.hpp"



enum Direction {north = 1, east, south, west};

class GameMap {
    friend class Game;
private:
    Space* start;
    Space* end;
    int numSpaces;

public:
    explicit GameMap();
    ~GameMap();
    void createMap();
    Space& createSpace(std::string& name, int type, int numBooks, Color color);
    void addSpace(Space&, Direction direction);
    int random(int min, int max);
    bool isEmpty();
    Space* findNext(Space*);
    void printMap();
    Space* playerLocation();

};


#endif //GAMEMAP_HPP
