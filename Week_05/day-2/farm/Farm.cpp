//
// Created by NEMETH on 2019.02.12..
//

#include "Farm.h"

Farm::Farm(int numSlots, std::vector<Animal> concreteAnimalList)
{
    _animals = concreteAnimalList;
    _numSlots = numSlots;
}

void Farm::breed()
{
    if (_numSlots > _animals.size()) {
        _animals.push_back(Animal());
    }
}

int Farm::sizeOfAnimalVector()
{
    return _animals.size();
}

void Farm::slaughter()
{
    int temp = _animals[0].getHunger();
    for (int i = 0; i < _animals.size(); ++i) {
        if (_animals[i].getHunger() < temp) {
            temp = _animals[i].getHunger();
        }
    }

    for (int j = 0; j < _animals.size(); ++j) {
        if (_animals[j].getHunger() == temp) {
            _animals.erase(_animals.begin() + j);
            _numSlots++;
            break;
        }
    }
}