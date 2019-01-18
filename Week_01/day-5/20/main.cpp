#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers and prints the bigger one

    int a,b;
    std::cout<<"Write 2 numbers! " <<std::endl;
    std::cin>>a;
    std::cin>>b;

    if (a>b) {
        std::cout<<"The bigger is a: " << a << std::endl;
    };

    if (a<b) {
        std::cout<<"The bigger is b: " << b << std::endl;
    };

    if (a=b) {
        std::cout<<"They are equal!" << std::endl;
    };

    return 0;
}