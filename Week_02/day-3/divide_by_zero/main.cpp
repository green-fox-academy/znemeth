#include <iostream>
#include <fstream>

int divi (int b){

    try {
        int ten = 10;

        if (b == 0) {
            throw std::string("Can't divide by 0");
        }
        int c = ten/b;
        //std::cout << "Division: " << divi(b) << std::endl;
        return c;
    } catch (std::string) {
        std::cout << "ZERO!!!" << std::endl;
        return 0;
    }


}


int main() {
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0


    int param;

    std::cout<< "Write a number: " <<std::endl;
    std::cin>>param;

    divi(param);
    std::cout << "Division: " << divi(param) << std::endl;

    return 0;
}