#include <iostream>
#include <string>
#include <exception>

int main() {
    try {
        int a = 10;
        int b = 0;
        if (b == 0) {
            throw std::string("Can't divide by 0");
        }
        std::cout << a / b << std::endl;
    } catch (std::string& e) {
        std::cout << e << std::endl;
    }
    return 0;
}