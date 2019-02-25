#include <stdio.h>
#include <stdlib.h>

int odd(num1)
{
    if (num1 % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)

    int num1;
    printf("Your number: \n");
    scanf("%d", &num1);

    odd(num1);

    printf("Result: %d \n", odd());
    return 0;
}