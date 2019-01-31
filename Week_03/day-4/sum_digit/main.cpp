// Given a non-negative int n, return the sum of its digits recursively (no loops).
// Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while
// divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
#include <iostream>

int sumdigit(int x) {

    if (x == 0) {
        return 0;
    } else {
        return (x % 10 + sumdigit(x / 10));
    }
}

    int main() {
        int orignum;
        std::cout << "Enter a non-negative  integer: " <<std::endl;
        std::cin >> orignum;

        sumdigit(orignum);

        int result = sumdigit(orignum);

        std::cout << "Sum of digits are: " << result <<std::endl;

        return 0;
    }
