#include <iostream>
#include "Helicopter.h"
#include "Bird.h"
int main()
{
    Helicopter ob1(30, 200, 234);
    ob1.land();

    Helicopter ob2(30, 200, 234);
    ob2.fly();

    Helicopter ob3(30, 200, 234);
    ob3.takeOff();

    Bird bird;
    bird.land();

    Bird bird2;
    bird2.fly();

    Bird bird3;
    bird3.takeOff();

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}