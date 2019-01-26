#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was

    int n;
    std::cout<< "Size of the pyramid: " <<std::endl;
    std::cin>>n;

    for (int i = 0; i < n; i++) {
        for (int y = i; y < n; y++) {
            std::cout << " ";
        }
        for (int j = 0; j <= (2 * i); j++) {
            std::cout << "%";
        }
        std::cout << "\n";
    }
    return 0;
}