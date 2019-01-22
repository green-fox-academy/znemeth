#include <iostream>

int *whichIsBigger(int *intPtr1, int *intPtr2) {
    if (*intPtr1 > *intPtr2) {
        return intPtr1;
    } else {
        return intPtr2;
    }
}

int main ()
{
    int a = 77;
    int b = 18;

    int *biggerNumberPtr = nullptr;
    biggerNumberPtr = whichIsBigger(&a, &b);

    std::cout << "The bigger number is: " << *biggerNumberPtr << std::endl;

    return 0;
}