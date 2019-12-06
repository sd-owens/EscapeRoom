//
// Created by Steve Owens on 12/4/19.
//

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Player.hpp"

enum Color {Blue , Green, Red};

class Space {
    friend class GameMap;
//    friend std::ostream& operator << (std::ostream& os, const Color& color);
//    virtual void do_print(std::ostream& str) = 0;
protected:
    Player* player;
    Space* north;
    Space* east;
    Space* south;
    Space* west;
public:
    explicit Space();
    virtual ~Space();
    virtual void search() = 0;
    virtual bool isOccupied();
    void showDoors();

};


#endif //SPACE_HPP
