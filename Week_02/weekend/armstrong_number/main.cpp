#include <iostream>

int main() {
    int origNum, num, rem, sum = 0;
    std::cout << "Enter a positive  integer: " <<std::endl;
    std::cin >> origNum;

    num = origNum;

    while(num != 0)
    {
        rem = num % 10;
        sum += rem * rem * rem;
        num /= 10;
    }

    if(sum == origNum)
        std::cout << origNum << " is an Armstrong number." <<std::endl;
    else
        std::cout << origNum << " is not an Armstrong number." <<std::endl;

    return 0;
}