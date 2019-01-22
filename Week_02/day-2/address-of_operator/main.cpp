#include <iostream>

int main ()
{
    int number = 42;

    // prints the value stored by the variable called 'number'
    std::cout << "The value of number is: " << number << std::endl;

    // prints the memory location of the variable called 'number'
    std::cout << "The address of number is " << &number << std::endl;

    return 0;
}