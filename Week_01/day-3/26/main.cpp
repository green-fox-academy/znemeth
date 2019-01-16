#include <iostream>

int main(int argc, char* args[]) {

    // Create a program that asks for two numbers
    // If the second number is not bigger than the first one it should print:
    // "The second number should be bigger"
    //
    // If it is bigger it should count from the first number to the second by one
    //
    // example:
    //
    // first number: 3, second number: 6, should print:
    //
    // 3
    // 4
    // 5
    int i;
    int j;
    std::cout << "Write a number: " << std::endl;
    std::cin>>i;
    std::cout << "Write a 2. number: " << std::endl;
    std::cin>>j;

    return 0;
}