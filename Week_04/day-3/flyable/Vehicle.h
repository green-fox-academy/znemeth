//
// Created by NEMETH on 2019.02.06..
//

#ifndef FLYABLE_VEHICLE_H
#define FLYABLE_VEHICLE_H

class Vehicle
{
public:
    Vehicle(int speed, int elevation, int size);
protected:
    int _speed;
    int _elevation;
    int _size;
};

#endif //FLYABLE_VEHICLE_H
