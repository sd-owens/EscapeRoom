//
// Created by steve on 12/5/19.
//

#ifndef GAMEMAP_HPP
#define GAMEMAP_HPP

#include "Space.hpp"

enum Direction {north = 1, east, south, west};

class GameMap {
private:
    Space* start;
    Space* end;
    int numSpaces;
public:
    explicit GameMap(int);
    ~GameMap();
    void createMap();
    Space& createSpace(int type);
    Space& createSpace(int type, int numBooks, Color color);
    void addSpace(Space&, Direction direction);
    int random(int min, int max);
    bool isEmpty();
    Space* findNext(Space*);


};


#endif //GAMEMAP_HPP
