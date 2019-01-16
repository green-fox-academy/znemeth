#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for an integer that is a distance in kilometers,
    // then it converts that value to miles and prints it

    int km;
    std::cout << "Add a distance in km: "<< std::endl;
    std::cin >> km;

    std::cout << "It is " << km / 0.621371192 << " miles." << std::endl;

    return 0;
}