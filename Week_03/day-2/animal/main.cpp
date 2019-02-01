#include <iostream>
#include "Animal.h"

int main()
{
    Animal cat;
    Animal dog (9, 10);


    int thirst_number, hunger_number;
    int thi, hun;


    std::cout << "Number of drinking: " << std::endl;
    std::cin >> thirst_number;

    std::cout << "Number of eating:  " << std::endl;
    std::cin >> hunger_number;

    for (int i = 0; i < thirst_number; i++){
        cat.drink();
    }

    for (int i = 0; i < hunger_number; i++){
        cat.eat();
    }


    std::cout << "Thirst: " << cat.thirst << ", " << "Hunger: " << cat.hunger << std::endl;
    return 0;
}