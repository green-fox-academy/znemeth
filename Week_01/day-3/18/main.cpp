#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input,
    // Then prints "Odd" if the number is odd, or "Even" if it is even.

    int num;
    std::cout << "Write a number here: " << std::endl;
    std::cin >> num;

    if (num%2==1) {
        std::cout << "Odd number" << std::endl;
    } else {
    std::cout << "Even number" << std::endl;
    }
    return 0;
}