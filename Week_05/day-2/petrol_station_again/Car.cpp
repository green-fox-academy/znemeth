//
// Created by NEMETH on 2019.02.12..
//

#include "Car.h"

Car::Car()
{

};

Car::Car(int gasAmount, int capacity)
{
    _gasAmount = gasAmount;
    _capacity = capacity;
}

bool Car::isFull()
{
    return (_gasAmount == _capacity);
}

void Car::fill()
{
    if (_gasAmount < _capacity) {
        _gasAmount++;
    }
}

void Car::setgasAmount(int gasAmount){
    _gasAmount = gasAmount;
};

int Car::getgasAmount(){
    return _gasAmount;
};