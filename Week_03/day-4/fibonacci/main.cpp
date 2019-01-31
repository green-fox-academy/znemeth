#include <iostream>

int fibo (int x) {
    if (x < 1) {
        return 0;
    }
    if (x == 1) {
        return 1;
    }
    if (x == 2) {
        return 1;
    } else if (x > 1) {
        return fibo(x-1) + fibo(x-2);
    }
}

int main() {
    int x = 5;
    fibo(x);
    std::cout << x << ". element of Fibonacci sequence: " << fibo(x) << std::endl;
    return 0;
}