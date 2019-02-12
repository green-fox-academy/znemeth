//
// Created by NEMETH on 2019.02.12..
//

#ifndef FARM_ANIMAL_H
#define FARM_ANIMAL_H

class Animal
{
public:
    Animal();

    Animal(int hun, int thi);
    void eat();
    void drink();
    void play();

//private:
    int hunger;
    int thirst;
};

#endif //FARM_ANIMAL_H
