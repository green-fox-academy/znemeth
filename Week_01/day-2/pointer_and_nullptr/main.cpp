#include <iostream>

int main ()
{
    int *ptr;

    // right now our 'ptr' pointer is storing some garbage value
    std::cout << "The value of ptr is " << ptr << std::endl;

    std::cout << "The address of ptr is " << &ptr << std::endl;

    ptr = nullptr;

    // by giving it a nullptr value it will point to 0
    std::cout << "The value of ptr is " << ptr << std::endl;

    std::cout << "The value of ptr is " << &ptr << std::endl;

    return 0;
}