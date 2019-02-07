//
// Created by NEMETH on 2019.02.06..
//

#ifndef FLYABLE_HELICOPTER_H
#define FLYABLE_HELICOPTER_H

#include "Flyable.h"
#include "Vehicle.h"

class Helicopter : public Flyable, public Vehicle
{
public:
    Helicopter(int speed, int elevation, int size);

    void land() override;

    void fly() override;

    void takeOff() override;
};

#endif //FLYABLE_HELICOPTER_H
