//
// Created by NEMETH on 2019.02.13..
//

#include "Aircraft.h"
#include "string"

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

std::string Aircraft::getType()
{
    return aircraftToString(get_aircraftType());
}

std::string Aircraft::getStatus()
{
    return "Type: " + getType() +
           ", Ammo: " + std::to_string(_ammoStore) +
           ", Base Damage: " + std::to_string(_baseDamage) +
           ", All Damage: " + std::to_string(_ammoStore * _baseDamage);
}

bool Aircraft::isPriority()
{
    if (_aircraftType == F35) {
        return true;
    } else {
        return false;
    }
}

std::string Aircraft::boolToString(){
    if (isPriority() == 0){
        return "TRUE";
    } else
        return "FALSE";
}