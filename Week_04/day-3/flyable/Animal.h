//
// Created by NEMETH on 2019.02.06..
//

#ifndef FLYABLE_ANIMAL_H
#define FLYABLE_ANIMAL_H

#include <string>

class Animal
{
public:

    Animal();

    virtual std::string getName() = 0;

    virtual std::string breed() = 0;

protected:
    std::string _name;
    int _age;
};

#endif //FLYABLE_ANIMAL_H
