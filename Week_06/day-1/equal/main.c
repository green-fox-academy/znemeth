#include <stdio.h>
#include <stdlib.h>

int equality(num1, num2)
{
    if (num1 == num2) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    // Create a program which asks for two integers and stores them separately
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise


    int num1;
    int num2;
    printf("1. number: \n");
    scanf("%d", &num1);
    printf("2. number: \n");
    scanf("%d", &num2);

    equality(num1, num2);

    printf("Result: %d \n", equality());
    return 0;
}