//
// Created by NEMETH on 2019.02.07..
//
#include "Animal.h"
#include "Flyable.h"

#ifndef FLYABLE_BIRD_H
#define FLYABLE_BIRD_H

class Bird : public Flyable, public Animal
{
public:
    Bird();

    std::string breed() override;

    std::string getName() override;

    void fly() override;
    void land() override;
    void takeOff() override;

};

#endif //FLYABLE_BIRD_H
