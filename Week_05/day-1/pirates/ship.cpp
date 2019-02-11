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

int Ship::getGolds()
{
    int sumGold = 0;
    for (int i = 0; i < _pirates.size(); ++i) {
        sumGold += _pirates[i].getGold();
    }
    return sumGold;
}

std::vector<std::string> Ship::getPoorPirates()
{
    std::vector<std::string> poorPirateNames;
    for (int i = 0; i < _pirates.size(); ++i) {
        if (_pirates[i].hasWoodenleg() && _pirates[i].getGold() < 15) {
        }
    }
    return poorPirateNames;
}

void Ship::lastDayOnTheShip()
{
    for (int i = 0; i < _pirates.size(); ++i) {
        _pirates[i].party();
    }
}

void Ship::prepareForBattle()
{

    for (int i = 0; i < _pirates.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            _pirates[i].work();
        }
        lastDayOnTheShip();
    }
}