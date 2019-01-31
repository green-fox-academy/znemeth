#include <iostream>

int factorialIterative(int num) {
    int fact = 1;
    for(int i = 0; i < num; i+= 1) {
        fact *= i + 1;
    }
    return fact;
}

int main() {
    std::cout << factorialIterative(5) << std::endl;
    return 0;
}