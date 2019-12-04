//
// Created by Steve Owens on 12/4/19.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <string>

class Player {
private:
    struct Item {
        std::string name;
    };
    int flashLight;
    Item backpack [4];
public:
    explicit Player (int);
    int getFlashLight() const;
    void initBackpack();
    void showBackpack();

};


#endif //PLAYER_HPP
