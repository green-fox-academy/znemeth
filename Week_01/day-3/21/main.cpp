#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two numbers
    // The first number represents the number of girls that comes to a party, the
    // second the boys
    // It should print: The party is excellent!
    // If the the number of girls and boys are equal and 20 or more people are coming to the party
    //
    // It should print: Quite cool party!
    // If there are 20 or more people coming to the party but the girl - boy ratio is not 1-1
    //
    // It should print: Average party...
    // If there are less people coming than 20
    //
    // It should print: Sausage party
    // If no girls are coming, regardless the count of the people

    int boy;
    int girl;

    std::cout << "Number of girls: " << std::endl;
    std::cin >> girl;

    std::cout << "Number of boys: " << std::endl;
    std::cin >> boy;

    if (girl + boy > 19 && girl == boy){
        std::cout << "The party is excellent!" << std::endl;
    }

    if (girl + boy > 19 && girl != boy){
        std::cout << "Quite cool party!" << std::endl;
    }

    if (girl + boy < 20 && girl > 0){
        std::cout << "Average party...!" << std::endl;
    }

    if (girl == 0){
        std::cout << "Sausage party!" << std::endl;
    }

    return 0;
}