//
// Created by Steve Owens on 12/4/19.
//

#ifndef SPACE_HPP
#define SPACE_HPP

enum direction {north, east, west, south};

class Space {
protected:
    Player* player;
    Space* north;
    Space* east;
    Space* south;
    Space* west;
public:
    explicit Space();
    virtual ~Space();
    virtual bool isOccupied();
    void showDoors();

};


#endif //SPACE_HPP
