//
// Created by NEMETH on 2019.02.12..
//

#include "Animal.h"

Animal::Animal()
{
    hunger = 50;
    thirst = 50;
};

Animal::Animal(int hun, int thi)
{
    hunger = hun;
    thirst = thi;
};

void Animal::eat()
{
    hunger--;

};

void Animal::drink()
{
    thirst--;
};

void Animal::play()
{
    hunger++;
    thirst++;
};