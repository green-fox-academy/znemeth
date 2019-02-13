//
// Created by NEMETH on 2019.02.13..
//

#ifndef AIRCRAFT_CARRIER_CARRIER_H
#define AIRCRAFT_CARRIER_CARRIER_H

#include <vector>
#include "Aircraft.h"


class Carrier
{
public:
    Carrier(int initAmmo, int HP);

private:
    std::vector<Aircraft> _aircrafts;
    int _initAmmo;
    int _HP;
};

#endif //AIRCRAFT_CARRIER_CARRIER_H
