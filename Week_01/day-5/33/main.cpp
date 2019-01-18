#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stried number is lower
    // You found the number: 8
    int a = 23;
    int b;


    std::cout << "Make a guess: " << std::endl;
    std::cin >>b;

    if (a<b){
        std::cout << "The stored number is smaller!" << std::endl;
        std::cout << "Make a guess: " << std::endl;
        std::cin >>b;
    };


    if (a>b){
        std::cout << "The stored number is bigger!" << std::endl;
        std::cout << "Make a guess: " << std::endl;
        std::cin >>b;
    };

    if (a==b){
        std::cout << "WIN!" << std::endl;
    };

    return 0;
}