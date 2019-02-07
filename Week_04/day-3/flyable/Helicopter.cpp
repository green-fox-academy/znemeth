//
// Created by NEMETH on 2019.02.06..
//

#include <iostream>
#include "Helicopter.h"

Helicopter::Helicopter(int speed, int elevation, int size) : Vehicle(speed, elevation, size){}

void Helicopter::fly()
{
    std::cout << "FLY FLY FLY!!!" << std::endl;
}

void Helicopter::land()
{
    std::cout << "LAND LAND LAND!!!" << std::endl;
}

void Helicopter::takeOff()
{
    std::cout << "TAKEOFF TAKEOFF TAKEOFF!!!" << std::endl;
}