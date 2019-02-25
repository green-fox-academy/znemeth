#include <stdio.h>
#include <stdlib.h>

int prime(num1)
{
    int flag = 0;
    if (num1 <= 1) {
        return 0;
    }

    for (int i = 2; i <= num1 / 2; i++) {
        if (num1 % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    int num1;
    printf("Your number: \n");
    scanf("%d", &num1);

    prime(num1);

    printf("Result: %d \n", prime());
    return 0;
}