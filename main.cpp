#include <iostream>
#include "BookSpace.hpp"
#include "GameMap.hpp"

int main() {

    auto* gm = new GameMap();
    gm->printMap();

    delete gm;
    gm = nullptr;

    return 0;
}