#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000
    int a=5, b=6, c=7, area, vol;

    vol = a * b * c;
    area = 2*(a*b + a*c + b*c);

    std::cout<< "Surface area: " << area << std::endl;
    std::cout<< "Volumen: " << vol << std::endl;

    return 0;
}