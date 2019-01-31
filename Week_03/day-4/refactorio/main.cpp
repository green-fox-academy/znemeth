#include <iostream>

int refracto (int x) {
    if (x < 1) {
        return 1;
    } else {
        return x * refracto(x-1);
    }
}

int main() {
    int input = 3;
    refracto(input);
    std::cout << "Factorial of " << input << ": " << refracto(input) << std::endl;
    return 0;
}