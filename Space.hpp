//
// Created by Steve Owens on 12/4/19.
//

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Player.hpp"

enum Color {Blue , Green, Red};

class Space {
    friend class GameMap;
protected:
    Player* player;
    std::string name;
    int row;
    int col;
    Space* north;
    Space* east;
    Space* south;
    Space* west;
public:
    explicit Space(std::string& name);
    virtual ~Space();
    virtual void search() = 0;
    virtual bool isLocked();
    void showDoors();
    void setRow(int row);
    void setCol(int col);
    int getRow() const;
    int getCol() const;
    void setPlayer(Player *player);
    Player *getPlayer() const;
    const std::string &getName() const;

};


#endif //SPACE_HPP
