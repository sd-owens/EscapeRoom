//
// Created by Steve Owens on 12/4/19.
//

#ifndef DOORSPACE_HPP
#define DOORSPACE_HPP


#include "Space.hpp"

class DoorSpace : public Space {
private:
    bool locked;
public:
    explicit DoorSpace();
    bool isLocked();
    void openDoor();
    void search() override;
};


#endif //DOORSPACE_HPP