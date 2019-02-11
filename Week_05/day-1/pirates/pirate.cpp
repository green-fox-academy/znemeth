//
// Created by NEMETH on 2019.02.11..
//

#include <string>
#include "pirate.h"

Pirate::Pirate(std::string name, bool isCaptain, bool hasWoodenleg)
{
    _name = name;
    _gold = 0;
    _healthPoints = 10;
    _isCaptain = isCaptain;
    _hasWoodenleg = hasWoodenleg;
}

void Pirate::work()
{
    if (_isCaptain) {
        _gold = _gold + 10;
        _healthPoints = _healthPoints - 5;
    } else {
        _gold = _gold + 1;
        _healthPoints = _healthPoints - 1;
    }
}

void Pirate::party()
{
    if (_isCaptain) {
        _healthPoints = _healthPoints + 10;
    } else {
        _healthPoints = _healthPoints + 1;
    }
}

std::string Pirate::toString()
{
    if (_hasWoodenleg) {
        return "Hello, I'm " + _name + ". " + "I have a wooden leg and " + std::to_string(_gold) + " golds.";
    } else {
        return "Hello, I'm " + _name + ". " + "I still have my real legs and " + std::to_string(_gold) + " golds.";
    }
}

bool Pirate::isCaptain()
{
    return _isCaptain;
}

bool Pirate::hasWoodenleg()
{
    return _hasWoodenleg;
}

int Pirate::getGold()
{
    _gold;
}

std::string Pirate::getName()
{
    return _name;
}