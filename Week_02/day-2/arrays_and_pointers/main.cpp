#include <iostream>

int main ()
{
    int numbers[] = {12, 42, 33};
    int *numbersPtr = numbers;

    // prints out the memory addresses
    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        std::cout << numbers + i << std::endl;
    }

    // prints out the memory addresses
    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        std::cout << numbersPtr + i << std::endl;
    }

    // prints out the values
    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        std::cout << numbers[i] << std::endl;
    }

    // prints out the values
    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        std::cout << numbersPtr[i] << std::endl;
    }

    // prints out the values
    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        std::cout << *(numbersPtr + i) << std::endl;
    }

    // prints out the values
    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        std::cout << *(numbers + i) << std::endl;
    }

    return 0;
}