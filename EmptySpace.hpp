//
// Created by steve on 12/5/19.
//

#ifndef EMPTYSPACE_HPP
#define EMPTYSPACE_HPP


#include "Space.hpp"

class EmptySpace : public Space {
private:
public:
    void search() override;
};


#endif //EMPTYSPACE_HPP