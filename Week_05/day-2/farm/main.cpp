#include <iostream>
#include "Animal.h"

int main()
{

    Animal cat;
    cat.eat();

    for (int i = 0; i < 7; ++i) {
        cat.drink();
    }

    //cat.play();

    std::cout << "Hunger: "<< cat.hunger << std::endl;
    std::cout << "Thirst: "<< cat.thirst << std::endl;
    return 0;
}