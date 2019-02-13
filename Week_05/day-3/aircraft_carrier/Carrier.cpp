//
// Created by NEMETH on 2019.02.13..
//

#include "Carrier.h"

Carrier::Carrier(int initAmmo, int HP)
{
    _initAmmo = initAmmo;
    _HP = HP;
}

void Carrier::add(Aircraft aircraft)
{
    _aircrafts.push_back(aircraft);
}

const std::vector<Aircraft> &Carrier::get_aircrafts() const
{
    return _aircrafts;
}

int Carrier::get_initAmmo() const
{
    return _initAmmo;
}

int Carrier::get_HP() const
{
    return _HP;
}

void Carrier::fill()
{

    int totalAmmoNeeded = 0;
    for (int i = 0; i < _aircrafts.size(); ++i) {
        int aircraftMaxAmmo = _aircrafts[i].get_maxAmmo();
        int aircraftActualAmmo = _aircrafts[i].get_ammoStore();
        int aircraftAmmoNeeded = aircraftMaxAmmo - aircraftActualAmmo;
        totalAmmoNeeded += aircraftAmmoNeeded;
    }
    if (_initAmmo < totalAmmoNeeded) {
        for (int i = 0; i < _aircrafts.size(); ++i) {
            if (_aircrafts[i].isPriority()) {
                _aircrafts[i].refill(_aircrafts[i].get_maxAmmo());
            } else {

            }
        }
    }

}


