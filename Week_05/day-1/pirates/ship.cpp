//
// Created by NEMETH on 2019.02.11..
//

#include "ship.h"

void Ship::addPirate(Pirate pirate)
{
    if (pirate.isCaptain()) {
        for (int i = 0; i < _pirates.size(); ++i) {
            if (_pirates[i].isCaptain()) {
                return;
            }
        }

    }
    _pirates.push_back(pirate);
}

