#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have

    int a,b,leg;

    std::cout<< "Number of chickens: " <<std::endl;
    std::cin>>a;

    std::cout<< "Number of pigs: " <<std::endl;
    std::cin>>b;

    leg = 2*a + 4*b;

    std::cout<< "Number of legs: " << leg <<std::endl;

    return 0;
}