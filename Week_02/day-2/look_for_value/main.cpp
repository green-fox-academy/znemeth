#include <iostream>

int lfv (int array[], int size, int number) {
    for (int i = 0; size > i; i++) {
        if (array[i] == number) {
            return i;
        }
    }
    return 0;
};

int main()
{
    // Create a function which takes an array (and it's lenght) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return 0

    int number;
    std::cout << "Give me a number to check: " << std::endl;
    std::cin >> number;

    int array[6] = {2, 4, 6, 5, 8, 9};

    int size = sizeof(array)/sizeof(array[0]);
    std::cout << size << std::endl;

    lfv(array, size, number);

    std::cout << lfv(array, size, number) << std::endl;

    return 0;
}