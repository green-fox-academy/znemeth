#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int b = 17;

    int *aPtr = &a;
    int *bPtr = &b;

    int c = *aPtr + *bPtr;

    std::cout <<"The sum of the 2 numbers: " << c << std::endl;


    return 0;
}