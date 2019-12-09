//
// Created by Steve Owens on 12/4/19.
//

#ifndef CHESTSPACE_HPP
#define CHESTSPACE_HPP


#include "Space.hpp"

class ChestSpace : public Space {
private:
    bool locked;
public:
    explicit ChestSpace(std::string& name);
    bool isLocked() override;
    void openChest(int);
    void search() override;
};


#endif //CHESTSPACE_HPP
