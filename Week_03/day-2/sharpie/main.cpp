#include <iostream>
#include "sharpie.h"

int main() {

    Sharpie ob ("roddzsa", 14.3);

    int decr;
    std::cout << "Decrease level: " << std::endl;
    std::cin>> decr;

    for (int i = 0; i < decr ; i++){
        ob.use();
    }

    std::cout << "Sharpie properties: " << ob.getColor() << ", " << ob.getWidth()<< ", " << ob.getInkAmount() << std::endl;

    return 0;
}