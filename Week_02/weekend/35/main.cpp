#include <iostream>

int main(int argc, char* args[]) {

    // Crate a program that draws a chess table like this
    //
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    int a;
    std::cout<< "Size of the chess table: " <<std::endl;
    std::cin>>a;

    for (int i=0; i<a; i++) {
        for (int j = 0; j < a; j++) {
            if ((i % 2 == 1 & j % 2 == 1)) {
                std::cout << " ";
            } else if ((i % 2 == 0 & j % 2 == 0)) {
                std::cout << " ";
            } else {
                std::cout << "%";
            }
        }
        std::cout << "\n" << std::endl;
    }

    return 0;
}