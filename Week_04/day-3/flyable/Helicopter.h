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
    void land();

    void fly();

    void takeOff();
};

#endif //FLYABLE_HELICOPTER_H
