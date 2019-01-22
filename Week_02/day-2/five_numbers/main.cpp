#include <iostream>

int main()
{
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    int array[5]={};
    std::cout<< "Give me 5 numbers: " << std::endl;

    for (int i=0; i < sizeof(array)/sizeof(array[0]) ; i++) {
        std::cin >> array[i];
    }

    int *arrayPtr = array;


    for (int i=0; i < sizeof(array)/sizeof(array[0]) ; i++) {
        std::cout<< "Values by pointers: " << arrayPtr[i]<< std::endl;
    }
    return 0;
}