#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user

    std::string name;
    std::cout << "Please, type your name!" << std::endl;
    std::cin >> name;


    std::cout << "Hello " << name <<"!" << std::endl;

    return 0;
}