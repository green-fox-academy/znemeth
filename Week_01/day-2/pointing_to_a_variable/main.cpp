#include <iostream>

int main ()
{

    int age = 31;
    int *agePtr = nullptr;

    std::cout << "The value of age is " << age << std::endl;
    std::cout << "The memory address of age is " << &age << std::endl;

    // it should be 0 because we initialized it as a nullptr
    std::cout << "The value of agePtr is " << agePtr << std::endl;

    agePtr = &age;

    // this time it should be the memory address of the variable 'age'
    std::cout << "The value of agePtr is " << agePtr << std::endl;

    return 0;
}