//
// Created by NEMETH on 2019.02.01..
//

#ifndef PETROL_STATION_STATION_H
#define PETROL_STATION_STATION_H
#include "car.h"

class station {
    int gasAmount;
public:
    station();
    void fill(Car& car);
    int getgasAmount();
};


#endif //PETROL_STATION_STATION_H
