#include <iostream>
#include "Car.h"
#include "Station.h"

int main()
{

    Station station;

    Car car1(10, 20);
    Car car2(15, 30);
    Car car3(10, 10);
    Car car4(10, 20);
    Car car5(10, 20);

    station.fill(car1);
    station.fill(car2);
    station.fill(car3);
    station.fill(car4);
    station.fill(car5);

    std::cout << "Station gas amount: " << station.getgasAmount() << std::endl;

    return 0;
}