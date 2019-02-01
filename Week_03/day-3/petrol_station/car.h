//
// Created by NEMETH on 2019.01.30..
//

#ifndef PETROL_STATION_CAR_H
#define PETROL_STATION_CAR_H

class Car
{
public:
    Car(int carGasAmount,int carCapacity);
    int gasAmount, capacity;

    void fill(Car certaincar);

#endif //PETROL_STATION_CAR_H
