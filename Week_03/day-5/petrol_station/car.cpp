//
// Created by NEMETH on 2019.02.01..
//

#include "car.h"

Car::Car (int gasAmount, int capacity){
    this-> capacity = capacity;
    this-> gasAmount = gasAmount;
}

bool Car::isfull(){
    return (capacity == gasAmount);
}

void Car::fill(){
    gasAmount++;
}

void Car::setgasAmount(int gasAmount){
    gasAmount = gasAmount;
};

int Car::getgasAmount(){
    return gasAmount;
};
