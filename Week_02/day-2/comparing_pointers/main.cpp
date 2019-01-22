#include <iostream>

int main ()
{
    std::string a = "Bob";
    std::string b = "Bob";

    std::string *aPtr = &a;
    std::string *bPtr = &b;
    std::string *ptr = &a;

    // false
    std::cout << (aPtr == bPtr) << std::endl;

    // true
    std::cout << (aPtr == ptr) << std::endl;

    //true
    std::cout << (*aPtr == *bPtr) << std::endl;

    // true
    std::cout << (*aPtr == *ptr) << std::endl;

    return 0;
}