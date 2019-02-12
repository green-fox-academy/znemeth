//
// Created by NEMETH on 2019.02.12..
//

#include "Farm.h"

Farm::Farm(int numSlots)
{
    _numSlots = numSlots;
};

void Farm::breed()
{
    if (_numSlots > _animals.size()) {
        Animal animal;
        _animals.push_back(animal);
    }
}

int Farm::sizeOfAnimalVector(){
    return _animals.size();
};