#include <stdio.h>
#include <stdlib.h>

int sumdigit(num1, num2)
{
    int rem1 = 0;
    int sum1 = 0;

    while (num1 > 0) {
        rem1 = num1 % 10;
        sum1 = sum1 + rem1;
        num1 = num1 / 10;
    }

    //printf("Result: %d \n", sum1);

    int rem2 = 0;
    int sum2 = 0;

    while (num2 > 0) {
        rem2 = num2 % 10;
        sum2 = sum2 + rem2;
        num2 = num2 / 10;
    }

   // printf("Result: %d \n", sum2);

    if (sum1 == sum2) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise

    int num1;
    int num2;
    printf("1. number: \n");
    scanf("%d", &num1);
    printf("2. number: \n");
    scanf("%d", &num2);

    sumdigit(num1, num2);

    printf("Result: %d \n", sumdigit());
    return 0;
}