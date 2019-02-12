#include <iostream>
#include "Animal.h"
#include "Farm.h"

int main()
{
    Animal dog;
   /* dog.eat();
    dog.eat();
    dog.eat();
    dog.eat();
    dog.eat();
    dog.eat();
    dog.eat();
    dog.eat();
    dog.eat();*/
    std::cout << dog.getHunger() << "\n";

    Animal cat;
    //cat.eat();
    std::cout << cat.getHunger() << "\n";

    std::vector<Animal> myvector;
    myvector.push_back(dog);
    myvector.push_back(cat);

    Farm farm(5, myvector);

    farm.breed();
    farm.breed();
    farm.breed();
    /*farm.breed();
    farm.breed();
    farm.breed();
    farm.breed();*/

    farm.slaughter();
    std::cout << farm.sizeOfAnimalVector() << "\n";


    /*
    Animal cat;
    for (int i = 0; i < 10; ++i) {
        cat.eat();
    }

    std:
     :cout << cat.getHunger();
*/
    /* Animal cat;
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