#include <iostream>

// Write a recursive function that takes one parameter: n and adds numbers from 1 to n.

int adder (int x) {
    if (x < 1) {
        return 0;
    } else {
        return x + adder(x - 1);

    }
}

int main() {
    int num = 3;
    adder(num);
    std::cout << "Number: " << adder(num) << std::endl;
    return 0;
}