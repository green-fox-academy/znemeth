//
// Created by NEMETH on 2019.02.13..
//

#ifndef AIRCRAFT_CARRIER_AIRCRAFT_H
#define AIRCRAFT_CARRIER_AIRCRAFT_H

#include <string>

enum AircraftType
{
    F16,
    F35
};

std::string aircraftToString(AircraftType aircraftType);

class Aircraft
{
public:
    Aircraft(AircraftType aircraftType);
    AircraftType get_aircraftType() const;

    int get_maxAmmo() const;
    int get_baseDamage() const;
    int get_ammoStore() const;
    int fight();
    int refill(int fillingAmmo);

protected:
    AircraftType _aircraftType;
    int _maxAmmo;
    int _baseDamage;
    int _ammoStore;
};

#endif //AIRCRAFT_CARRIER_AIRCRAFT_H
