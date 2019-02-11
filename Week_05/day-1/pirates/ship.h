//
// Created by NEMETH on 2019.02.11..
//

#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H

#include <vector>
#include "pirate.h"

class Ship
{
public:
    void addPirate(Pirate pirate);

private:
    std::vector<Pirate> _pirates;

};

#endif //PIRATES_SHIP_H
