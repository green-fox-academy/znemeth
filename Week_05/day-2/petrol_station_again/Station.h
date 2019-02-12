//
// Created by NEMETH on 2019.02.12..
//

#ifndef PETROL_STATION_AGAIN_STATION_H
#define PETROL_STATION_AGAIN_STATION_H

#include "Car.h"

class Station
{
public:
    Station();
    void fill(Car& car);
    int getgasAmount();

protected:
    int _gasAmount;

};

#endif //PETROL_STATION_AGAIN_STATION_H
