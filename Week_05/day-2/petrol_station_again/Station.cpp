//
// Created by NEMETH on 2019.02.12..
//

#include <string>
#include "Station.h"

Station::Station()
{
    _gasAmount = 100;
}

void Station::fill(Car &car)
{
    while (!car.isFull() && _gasAmount > 0) {
        car.fill();
        _gasAmount--;
    }
}

int Station::getgasAmount()
{
    return _gasAmount;
}