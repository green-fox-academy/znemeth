#include <iostream>
#include "Helicopter.h"

int main()
{
    Helicopter ob1(30, 200, 234);
    ob1.land();

    Helicopter ob2(30, 200, 234);
    ob2.fly();

    Helicopter ob3(30, 200, 234);
    ob3.takeOff();

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}