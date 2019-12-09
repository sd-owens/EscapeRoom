//
// Created by Steve Owens on 12/4/19.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <string>
#include "Inventory.hpp"

class Player {
private:
    int flashLight;
    Inventory* backpack;
public:
    explicit Player (int);
    ~Player();
    int getFlashLight() const;
    void initBackpack();
    void useFlashLight();
    void showBackpack();
    void addItemToPack(Item& item);
    bool hasItem(std::string& name);
};


#endif //PLAYER_HPP
