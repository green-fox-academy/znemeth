#include <iostream>
#include "Animal.h"
#include "Farm.h"

int main()
{
    Farm farm(4);

    farm.breed();
    farm.breed();
    farm.breed();
    farm.breed();
    farm.breed();
    
    std::cout << farm.sizeOfAnimalVector();

    /*  Animal cat;
      cat.eat();

      for (int i = 0; i < 1; ++i) {
          cat.drink();
      }

      cat.play();

      std::cout << "Hunger: " << cat.hunger << std::endl;
      std::cout << "Thirst: " << cat.thirst << std::endl;
      */
    return 0;
}