#include <iostream>

void multiplyByTwo(int *intPtr) {
    *intPtr *= 2;
}

int main ()
{
    int number = 10;

    std::cout << "Value of the variable number is: " << number << std::endl;
    multiplyByTwo(&number);
    std::cout << "Value of the variable number is: " << number << std::endl;

    int *intPtr = &number;

    multiplyByTwo(intPtr);
    std::cout << "Value of the variable number is: " << number << std::endl;

    return 0;
}