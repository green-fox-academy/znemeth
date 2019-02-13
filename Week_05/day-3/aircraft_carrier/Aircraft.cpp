//
// Created by NEMETH on 2019.02.13..
//

#include "Aircraft.h"

std::string aircraftToString(AircraftType aircraftType)
{
    if (aircraftType == AircraftType::F16) {
        return "F16";

    } else {
        return "F35";
    }
}

Aircraft::Aircraft(AircraftType aircraftType)
{
    _aircraftType = aircraftType;
    if (aircraftType == F16) {
        _maxAmmo = 8;
        _baseDamage = 30;
        _ammoStore = 0;
    } else {
        _maxAmmo = 12;
        _baseDamage = 50;
        _ammoStore = 0;
    };
}

AircraftType Aircraft::get_aircraftType() const
{
    return _aircraftType;
}

int Aircraft::get_maxAmmo() const
{
    return _maxAmmo;
}

int Aircraft::get_baseDamage() const
{
    return _baseDamage;
}

int Aircraft::get_ammoStore() const
{
    return _ammoStore;
}

int Aircraft::fight()
{
    int usedAmmo = 0;
    while (_ammoStore == 0) {
        usedAmmo++;
        _ammoStore--;
    }
    return (usedAmmo * _baseDamage);
}

int Aircraft::refill(int fillingAmmo)
{
    int remainingAmmo;
    if (fillingAmmo >= _maxAmmo) {
        _ammoStore = _maxAmmo;
        remainingAmmo = fillingAmmo - _ammoStore;
    } else {
        _ammoStore = fillingAmmo;
        remainingAmmo = 0; //fillingAmmo - _ammoStore;
    }
    return remainingAmmo;
}