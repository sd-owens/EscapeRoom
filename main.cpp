#include <iostream>
#include "BookSpace.hpp"
#include "GameMap.hpp"

int main() {

    auto* gm = new GameMap(6);

    delete gm;
    gm = nullptr;

    return 0;
}