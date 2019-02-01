#include <iostream>
#include "car.h"
#include "station.h"


int main() {

    station station;

    Car car1 (20, 30);
    Car car2 (10, 40);
    Car car3 (40, 50);
    Car car4 (60, 80);
    Car car5 (45, 60);

    station.fill(car1);
    station.fill(car2);
    station.fill(car3);
    station.fill(car4);
    station.fill(car5);

    std::cout<< car1.getgasAmount() <<std::endl;
    std::cout<< car2.getgasAmount() <<std::endl;
    std::cout<< car3.getgasAmount() <<std::endl;
    std::cout<< car4.getgasAmount() <<std::endl;
    std::cout<< car5.getgasAmount() <<std::endl;
    std::cout<< station.getgasAmount() <<std::endl;

    return 0;
}