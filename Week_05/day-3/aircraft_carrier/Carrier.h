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
    void add(Aircraft aircraft);
    const std::vector<Aircraft> &get_aircrafts() const;
    int get_initAmmo() const;
    int get_HP() const;
    void fill();

private:
    std::vector<Aircraft> _aircrafts;
    int _initAmmo;
    int _HP;
};

#endif //AIRCRAFT_CARRIER_CARRIER_H
