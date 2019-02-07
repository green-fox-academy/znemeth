//
// Created by NEMETH on 2019.02.07..
//

#include <iostream>
#include "Bird.h"
#include "Animal.h"
#include "Flyable.h"

Bird::Bird()
{
    _name = "Sparrow";
    _age = 5;
}

void Bird::fly()
{
    std::cout << "BiRD FLY FLY FLY!!!" << std::endl;
}

void Bird::land()
{
    std::cout << "BiRD LAND LAND LAND!!!" << std::endl;
}

void Bird::takeOff()
{
    std::cout << "BiRD TAKEOFF TAKEOFF TAKEOFF!!!" << std::endl;
}