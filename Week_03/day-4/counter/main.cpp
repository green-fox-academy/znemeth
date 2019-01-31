#include <iostream>

// Write a recursive function that takes one parameter: n and counts down from n.

int counter (int num) {
    if (num >= 1) {
        std::cout << "Number: " << num << std::endl;
        counter(num - 1);
    }
}

int main() {
    int num = 10;
    counter(num);
    return 0;
}