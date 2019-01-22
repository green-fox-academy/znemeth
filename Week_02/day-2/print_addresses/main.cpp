#include <iostream>

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the memory addresses of the elements in the array

    int array[5]={};
    std::cout<< "Give me 5 numbers: " << std::endl;

    for (int i=0; i < sizeof(array)/sizeof(array[0]) ; i++) {
        std::cin >> array[i];
    }

    for (int i=0; i < sizeof(array)/sizeof(array[0]) ; i++) {
        std::cout<< "memory addresses: " << &array[i]<< std::endl;
    }





    return 0;
}