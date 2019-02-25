#include <stdio.h>

int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13
    int a = 22;
    int b = 13;
    // Print the result of 13 added to 22
    int sum = a + b;
    // Print the result of 13 substracted from 22
    int subst = a - b;
    // Print the result of 22 multiplied by 13
    int mult = a * b;
    // Print the result of 22 divided by 13 (as a decimal fraction)
    float div = (float) a / (float) b;
    // Print the reminder of 22 divided by 13
    int rem = a % b;
    // Store the results in variables and use them when you display the result

    printf("Sum: %d \n", sum);
    printf("Subst: %d \n", subst);
    printf("Mult: %d \n", mult);
    printf("Div: %.2f \n", div);
    printf("Rem: %d \n", rem);

    return 0;
}