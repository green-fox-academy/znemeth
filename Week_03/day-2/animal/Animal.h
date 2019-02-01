//
// Created by NEMETH on 2019.01.29..
//
#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H

class Animal {
public:

    Animal ();
    Animal (int hun, int thi);

    void eat();
    void drink();
    void play();

    int hunger;
    int thirst;
};


#endif //ANIMAL_ANIMAL_H
